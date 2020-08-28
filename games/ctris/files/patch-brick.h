--- brick.h.orig	2020-08-28 18:12:58 UTC
+++ brick.h
@@ -8,7 +8,7 @@ void find_index(char [4][4], unsigned char *, unsigned
 char check_brick(char [BOARD_HEIGHT][BOARD_WIDTH], char [4][4], const unsigned char, const unsigned char);
 void draw_to_board(char [BOARD_HEIGHT][BOARD_WIDTH], char [4][4], const char, const unsigned char, const unsigned char);
 
-char brick_digit[7][4][4];
+extern char brick_digit[7][4][4];
 
 #endif
 
