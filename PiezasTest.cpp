/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck) {
	ASSERT_TRUE(true);
}

TEST(PiezasTest, basic) {
    Piezas p;
    bool TESTER = p.pieceAt(0, 0) == Blank;
	ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, constructor) {
    Piezas p;
    bool TESTER = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (p.pieceAt(i, j) != Blank) {
                TESTER = false;
                break;
            }
        }
    }
    ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, dropOnePiece) {
    Piezas p;
    p.dropPiece(2);
    bool TESTER = p.pieceAt(0, 2) == X;
    ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, dropTwoPieces) {
    Piezas p;
    p.dropPiece(2);
    p.dropPiece(1);
    bool TESTER = (p.pieceAt(0, 2) == X && p.pieceAt(0, 1) == O);
    ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, stackTwoPieces) {
    Piezas p;
    p.dropPiece(2);
    p.dropPiece(2);
    bool TESTER = (p.pieceAt(0, 2) == X && p.pieceAt(1, 2) == O);
    ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, dropOutOfBounds) {
    Piezas p;
    bool TESTER = (p.dropPiece(4) == X || p.dropPiece(-1) == 0);
    ASSERT_FALSE(TESTER);
}

TEST(PiezasTest, checkOutOfBounds) {
    Piezas p;
    bool TESTER = (p.pieceAt(-1, -1) == Blank || p.pieceAt(3, 4) == Blank);
    ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, tooManyStacked) {
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(0);
    p.dropPiece(0);
    bool TESTER = p.dropPiece(0) == O;
    ASSERT_FALSE(TESTER);
}

TEST(PiezasTest, reset) {
    Piezas p;
    p.dropPiece(0);
    p.reset();
    bool TESTER = p.pieceAt(0, 0) == Blank;
    ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, testWinHorz) {
    /*
        XXXO
        OOOO
        XXXO
    */
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(0);
    p.dropPiece(0);
    p.dropPiece(3);
    p.dropPiece(1);
    p.dropPiece(1);
    p.dropPiece(1);
    p.dropPiece(3);
    p.dropPiece(2);
    p.dropPiece(2);
    p.dropPiece(2);
    p.dropPiece(3);
    bool TESTER = p.gameState() == O;
    ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, testWinVert) {
    /*
        OXXO
        XXOO
        OXOX
    */
    Piezas p;
    p.dropPiece(1);
    p.dropPiece(0);
    p.dropPiece(3);
    p.dropPiece(2);
    p.dropPiece(0);
    p.dropPiece(2);
    p.dropPiece(1);
    p.dropPiece(3);
    p.dropPiece(1);
    p.dropPiece(0);
    p.dropPiece(2);
    p.dropPiece(3);
    bool TESTER = p.gameState() == X;
    ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, testTie) {
    /*
        XOXO
        XXOO
        OXOX
    */
    Piezas p;
    p.dropPiece(1);
    p.dropPiece(0);
    p.dropPiece(3);
    p.dropPiece(2);
    p.dropPiece(0);
    p.dropPiece(2);
    p.dropPiece(1);
    p.dropPiece(3);
    p.dropPiece(0);
    p.dropPiece(1);
    p.dropPiece(2);
    p.dropPiece(3);
    bool TESTER = p.gameState() == Blank;
    ASSERT_TRUE(TESTER);
}

TEST(PiezasTest, incompleteBoard) {
    Piezas p;
    p.dropPiece(0);
    bool TESTER = p.gameState() == X;
    ASSERT_FALSE(TESTER);
}
