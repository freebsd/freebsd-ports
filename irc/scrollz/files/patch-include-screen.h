--- include/screen.h.orig	2021-05-06 08:04:55 UTC
+++ include/screen.h
@@ -47,6 +47,7 @@
 #define ST_NOTHING      -1
 #define ST_SCREEN       0
 #define ST_XTERM        1
+#define ST_TMUX         2
 
 /* This is here because it happens in so many places */
 #define curr_scr_win	current_screen->current_window
