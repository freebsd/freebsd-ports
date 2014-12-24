$OpenBSD: patch-converter_other_pamrgbatopng_c,v 1.1 2011/07/08 20:36:09 naddy Exp $

Fix build with png-1.5.

--- converter/other/pamrgbatopng.c.orig	Fri Aug 18 21:12:28 2006
+++ converter/other/pamrgbatopng.c	Mon Jul  4 14:21:23 2011
@@ -101,10 +101,8 @@ writePng(const struct pam * const pamP,
     if (!infoP)
         pm_error("Could not allocate PNG info structure");
     else {
-        infoP->width      = pamP->width;
-        infoP->height     = pamP->height;
-        infoP->bit_depth  = 8;
-        infoP->color_type = PNG_COLOR_TYPE_RGB_ALPHA;
+        png_set_IHDR(pngP, infoP, pamP->width, pamP->height,
+                     8, PNG_COLOR_TYPE_RGB_ALPHA, 0, 0, 0);
         
         png_init_io(pngP, ofP);
 
