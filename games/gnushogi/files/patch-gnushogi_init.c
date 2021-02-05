--- gnushogi/init.c.orig	2014-02-17 20:26:59 UTC
+++ gnushogi/init.c
@@ -63,7 +63,7 @@ short nolist          = 1;  /* Don't list the game aft
  * or DISPLAY_X; the default is DISPLAY_X to make life easier for xshogi.
  */
 
-display_t display_type = DISPLAY_X;
+display_t display_type = DISPLAY_CURSES;
 
 /* .... MOVE GENERATION VARIABLES AND INITIALIZATIONS .... */
 
@@ -100,7 +100,7 @@ distance(short a, short b)
 short
 distance(short a, short b)
 {
-    return (use_distdata
+    return (use_distdata && a < NO_SQUARES && b < NO_SQUARES
             ? (short)(*distdata)[(int)a][(int)b]
             : (short)computed_distance(a, b));
 }
