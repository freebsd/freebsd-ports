--- engine/unconditional.c.orig	2020-08-25 08:53:07 UTC
+++ engine/unconditional.c
@@ -29,6 +29,10 @@
 
 #include "liberty.h"
 
+/* Unconditionally meaningless moves. */
+int meaningless_black_moves[BOARDMAX];
+int meaningless_white_moves[BOARDMAX];
+
 /* Capture as many strings of the given color as we can. Played stones
  * are left on the board and the number of played stones is returned.
  * Strings marked in the exceptions array are excluded from capturing
