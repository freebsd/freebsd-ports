--- src/modules/loaders/loader_tiff.c.orig	Fri Jan  6 23:36:17 2006
+++ src/modules/loaders/loader_tiff.c	Wed Mar 15 13:57:03 2006
@@ -100,11 +100,11 @@
           {
 	     int a, r, g, b;
 	     
+             pixel_value = (*(pixel++));
 	     a = TIFFGetA(pixel_value);
 	     r = TIFFGetR(pixel_value);
 	     g = TIFFGetG(pixel_value);
 	     b = TIFFGetB(pixel_value);
-             pixel_value = (*(pixel++));
 	     if ((a > 0) && (a < 255) && (alpha_premult))
 	       {
 		  r = (r * 255) / a;
