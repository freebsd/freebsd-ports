--- gnushogi/cursesdsp.c.orig	2021-02-05 15:24:17 UTC
+++ gnushogi/cursesdsp.c
@@ -61,17 +61,11 @@
 
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
