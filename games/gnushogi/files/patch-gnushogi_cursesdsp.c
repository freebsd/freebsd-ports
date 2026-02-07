--- gnushogi/cursesdsp.c.orig	2014-02-17 20:26:59 UTC
+++ gnushogi/cursesdsp.c
@@ -40,7 +40,6 @@

 #include <sys/param.h>
 #include <sys/types.h>
-#include <sys/file.h>
 #include <curses.h>

 #include "gnushogi.h"
@@ -62,17 +61,11 @@
 
 #define FLUSH_SCANW fflush(stdout), scanw
 
-int mycnt1, mycnt2;
-
 #define MARGIN (5)
 #define TAB (58)
 
 #define VIR_C(s)  ((flag.reverse) ? (NO_COLS - 1 - column(s)) : column(s))
 #define VIR_R(s)  ((flag.reverse) ? (NO_ROWS - 1 - row(s)) : row(s))
-
-unsigned short MV[MAXDEPTH];
-int MSCORE;
-char *DRAW;
 
 /* Forward declarations. */
 /* FIXME: change this name, puh-leeze! */
