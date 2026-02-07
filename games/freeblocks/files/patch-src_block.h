--- src/block.h.orig	2015-03-09 12:48:31 UTC
+++ src/block.h
@@ -33,21 +33,21 @@
 #define SPEED_TIME 1800 / (60/FPS)
 #define MAX_SPEED 25
 
-const int POINTS_PER_BLOCK;
-const int POINTS_PER_BUMP;
-const int POINTS_PER_COMBO_BLOCK;
+extern const int POINTS_PER_BLOCK;
+extern const int POINTS_PER_BUMP;
+extern const int POINTS_PER_COMBO_BLOCK;
 
-int ROWS;
-int COLS;
-int NUM_BLOCKS;
-int START_ROWS;
-int DISABLED_ROWS;
-int CURSOR_MAX_X;
-int CURSOR_MIN_Y;
-int CURSOR_MAX_Y;
-int BLOCK_MOVE_SPEED;
-int DRAW_OFFSET_X;
-int DRAW_OFFSET_Y;
+extern int ROWS;
+extern int COLS;
+extern int NUM_BLOCKS;
+extern int START_ROWS;
+extern int DISABLED_ROWS;
+extern int CURSOR_MAX_X;
+extern int CURSOR_MIN_Y;
+extern int CURSOR_MAX_Y;
+extern int BLOCK_MOVE_SPEED;
+extern int DRAW_OFFSET_X;
+extern int DRAW_OFFSET_Y;
 
 typedef struct Block{
     int x,y;
@@ -62,15 +62,15 @@ typedef struct Block{
     bool sound_after_move;
 }Block;
 
-Block **blocks;
-bool animating;
-int bump_timer;
-int bump_pixels;
-int speed;
-int speed_init;
-int speed_timer;
-int game_over_timer;
-bool jewels_cursor_select;
+extern Block **blocks;
+extern bool animating;
+extern int bump_timer;
+extern int bump_pixels;
+extern int speed;
+extern int speed_init;
+extern int speed_timer;
+extern int game_over_timer;
+extern bool jewels_cursor_select;
 
 void blockSet(int i, int j, bool alive, int color);
 void blockClear(int i, int j);
