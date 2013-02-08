--- tools/clock/rleClock.c.orig	1992-04-30 23:19:39.000000000 +0900
+++ tools/clock/rleClock.c	2012-10-16 00:38:03.000000000 +0900
@@ -33,6 +33,7 @@
 */
 
 #include <stdio.h>
+#include <string.h>
 #include <math.h>
 #include <ctype.h>
 #include "rle.h"
@@ -133,7 +134,7 @@
  */
 
 #ifdef USE_PROTOTYPES
-void main(int argc, char *argv[]);
+int main(int argc, char *argv[]);
 void ifImageSet(int i, int j, int value, color_t *color);
 void drawHand(double place, double scale, double radius, int mask, int edge);
 void rasterAddBits(int mask, int match, int value);
@@ -156,7 +157,7 @@
 void stackPush(int x, int y, int dir);
 int stackPop(void);
 #else
-void main();
+int main();
 void ifImageSet();
 void drawHand();
 void rasterAddBits();
@@ -181,7 +182,7 @@
 #endif
 char **gargv;
 
-void
+int
 main (argc, argv)
 int	argc;
 char	*argv[];
