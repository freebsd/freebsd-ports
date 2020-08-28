--- ctris.h.orig	2015-08-24 12:06:35 UTC
+++ ctris.h
@@ -15,7 +15,7 @@
 #include <limits.h>
 #include <time.h>
 
-#define VERSION "v0.42" // version info
+#define VERSION "v0.42.1" // version info
 #define HEIGHT 24 // height of the screen
 #define WIDTH 80 // width of the screen
 #define BOARD_HEIGHT (HEIGHT - 5) // height of the board
@@ -44,9 +44,9 @@ void handle_quit_signal(const int);
 unsigned char get_rand(const unsigned char);
 int main(int, char *[]);
 
-char game_state, old_style_keys, counterclockwise_rotation, hide_cursor_workaround, highscore_file_path[256], default_name[40];
+extern char game_state, old_style_keys, counterclockwise_rotation, hide_cursor_workaround, highscore_file_path[256], default_name[40];
 
-unsigned long rseed;
+extern unsigned long rseed;
 
 #endif
 
