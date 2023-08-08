--- libray/liblight/extended.c.orig	1992-02-10 03:03:43 UTC
+++ libray/liblight/extended.c
@@ -54,7 +54,7 @@ ExtendedMethods()
 /*
  * Compute intensity ('color') of extended light source 'lp' from 'pos'.
  */
-static int
+int
 ExtendedIntens(lp, lcolor, cache, ray, dist, noshadow, color)
 Extended *lp;
 Color *lcolor, *color;
