--- libray/liblight/extended.c.orig	Mon Feb 10 04:03:43 1992
+++ libray/liblight/extended.c	Wed Feb  7 18:34:20 2007
@@ -54,7 +54,7 @@
 /*
  * Compute intensity ('color') of extended light source 'lp' from 'pos'.
  */
-static int
+int
 ExtendedIntens(lp, lcolor, cache, ray, dist, noshadow, color)
 Extended *lp;
 Color *lcolor, *color;
