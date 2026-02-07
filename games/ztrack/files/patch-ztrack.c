--- ./ztrack.c.orig	1995-12-01 03:34:36.000000000 +0100
+++ ./ztrack.c	2014-04-02 01:51:02.785307003 +0200
@@ -9,7 +9,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <time.h>
-#include <curses.h>
+#include <ncurses.h>
 
 
 #ifdef HAVE_RANDOM
