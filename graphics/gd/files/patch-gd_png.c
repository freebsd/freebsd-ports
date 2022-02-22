--- src/gd_png.c.orig	2021-09-11 04:43:11 UTC
+++ src/gd_png.c
@@ -276,6 +276,14 @@ BGD_DECLARE(gdImagePtr) gdImageCreateFromPngCtx (gdIOC
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
