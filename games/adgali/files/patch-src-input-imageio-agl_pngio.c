--- src/input/imageio/agl_pngio.c.orig	2003-06-24 01:58:47.000000000 +0200
+++ src/input/imageio/agl_pngio.c	2012-05-01 09:02:25.000000000 +0200
@@ -65,7 +65,7 @@
 	unsigned char buf[8];
 
 	if (agl_ios_read(ops, buf, 1, 8, NULL) == 8)
-		return png_check_sig(buf, 8);
+		return !png_sig_cmp(buf, 0, 8);
 	return 0;
 }
 
@@ -106,7 +106,7 @@
 	}
 
 	/* standard png error handler */
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		agl_error("Error reading the PNG file");
 		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
@@ -131,7 +131,7 @@
 	/* see pnglib for these calls */
 
 	if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
-		png_set_gray_1_2_4_to_8(png_ptr);
+		png_set_expand_gray_1_2_4_to_8(png_ptr);
 
 	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
 		png_set_tRNS_to_alpha(png_ptr);
@@ -171,7 +171,7 @@
 		*rowp = (png_bytep) pixelp;
 	/* standard png error handler redeclared to free the agl image if an
 	 * error occurs */
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		agl_error("Error reading the PNG file");
 		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
