--- include/screen.h.orig	2011-04-29 17:21:18.000000000 +0900
+++ include/screen.h	2013-03-11 23:30:07.063088471 +0900
@@ -47,6 +47,7 @@
 #define ST_NOTHING      -1
 #define ST_SCREEN       0
 #define ST_XTERM        1
+#define ST_TMUX         2
 
 /* This is here because it happens in so many places */
 #define curr_scr_win	current_screen->current_window
