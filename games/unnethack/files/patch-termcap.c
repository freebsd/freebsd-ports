--- win/tty/termcap.c.orig	Thu Sep  2 23:20:27 2004
+++ win/tty/termcap.c	Thu Sep  2 23:20:46 2004
@@ -835,10 +835,6 @@
 
 #include <curses.h>
 
-#ifndef LINUX
-extern char *tparm();
-#endif
-
 #  ifdef COLOR_BLACK	/* trust include file */
 #undef COLOR_BLACK
 #  else
