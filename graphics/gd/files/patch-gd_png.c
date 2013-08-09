--- src/gd_png.c.orig	2013-06-25 11:58:23.000000000 +0200
+++ src/gd_png.c	2013-08-01 07:08:18.000000000 +0200
@@ -196,6 +196,14 @@
 	png_read_info (png_ptr, info_ptr);	/* read all PNG info up to image data */
 
 	png_get_IHDR (png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_type, NULL, NULL);
+
+	if (overflow2(sizeof (int), width)) {
+		return NULL;
+	}
+	if (overflow2(sizeof (int) * width, height)) {
+		return NULL;
+	}
+
 	if ((color_type == PNG_COLOR_TYPE_RGB) || (color_type == PNG_COLOR_TYPE_RGB_ALPHA)
 	        || color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
 		im = gdImageCreateTrueColor ((int) width, (int) height);
