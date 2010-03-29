--- src/svg_image.c.orig	2005-04-11 17:45:32.000000000 +0200
+++ src/svg_image.c	2010-03-29 20:41:38.000000000 +0200
@@ -228,7 +228,7 @@
 	return SVG_STATUS_FILE_NOT_FOUND;
 
     sig_bytes = fread (png_sig, 1, PNG_SIG_SIZE, file);
-    if (png_check_sig (png_sig, sig_bytes) == 0) {
+    if (!png_sig_cmp (png_sig, 0, sig_bytes) == 0) {
 	fclose (file);
 	return SVGINT_STATUS_IMAGE_NOT_PNG;
     }
@@ -271,7 +271,7 @@
 
     /* expand gray bit depth if needed */
     if (color_type == PNG_COLOR_TYPE_GRAY && depth < 8)
-	png_set_gray_1_2_4_to_8 (png);
+	png_set_expand_gray_1_2_4_to_8 (png);
 
     /* transform transparency to alpha */
     if (png_get_valid(png, info, PNG_INFO_tRNS))
