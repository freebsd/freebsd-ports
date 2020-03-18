--- batt.h.orig	1997-05-13 19:58:17 UTC
+++ batt.h
@@ -2,7 +2,7 @@
  * batt.h     Part of the SEABATTLE game by Vince Weaver                 *
  ************************************************************************/
 
-#include <curses.h>     /* Slang support is good for rxvt in linux */
+#include <ncurses.h>     /* Slang support is good for rxvt in linux */
 #include <stdio.h>
 #include <ctype.h>
 #include <stdlib.h>
@@ -54,7 +54,7 @@ DATA *current_player;
 
 /* binp.c */
 void init_curses(void);              /* All the function declarations */
-void exit_curses(void);
+void exit_curses_(void);
 void set_color(int color,int bold);
 void printxy(int x,int y,char *tempst);
 void draw_opening(void);
