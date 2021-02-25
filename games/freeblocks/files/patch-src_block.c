--- src/block.c.orig	2015-03-09 12:48:31 UTC
+++ src/block.c
@@ -23,8 +23,28 @@ const int POINTS_PER_BLOCK = 10;
 const int POINTS_PER_BUMP = 5;
 const int POINTS_PER_COMBO_BLOCK = 15;
 
-int speed_init = 1;
+int ROWS;
+int COLS;
+int NUM_BLOCKS;
+int START_ROWS;
+int DISABLED_ROWS;
+int CURSOR_MAX_X;
+int CURSOR_MIN_Y;
+int CURSOR_MAX_Y;
+int BLOCK_MOVE_SPEED;
+int DRAW_OFFSET_X;
+int DRAW_OFFSET_Y;
+
 Block **blocks = NULL;
+int speed_init = 1;
+
+bool animating;
+int bump_timer;
+int bump_pixels;
+int speed;
+int speed_timer;
+int game_over_timer;
+bool jewels_cursor_select;
 
 int blockRand(void) {
     return rand() % NUM_BLOCKS;
