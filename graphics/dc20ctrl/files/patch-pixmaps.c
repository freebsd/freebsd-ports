--- pixmaps.c.orig	1998-02-17 18:19:47.000000000 +0100
+++ pixmaps.c	2012-04-30 21:36:08.000000000 +0200
@@ -446,7 +446,7 @@
 	if (p) {
 		if ((png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL)) != NULL) {
 			if ((info_ptr = png_create_info_struct(png_ptr)) != NULL) {
-				if (setjmp(png_ptr->jmpbuf) == 0) {
+				if (setjmp(png_jmpbuf(png_ptr)) == 0) {
 					png_init_io(png_ptr, fp);
 					png_set_IHDR(png_ptr, info_ptr, p->width, p->height, 8, (p->components == 1) ? PNG_COLOR_TYPE_GRAY : PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
 					png_write_info(png_ptr, info_ptr);
@@ -504,26 +504,32 @@
 	 *	Build the image name
 	 */
 
-	strcpy(fname, name);
-	strcat(fname, ".");
+	if (strlcpy(fname, name, sizeof(fname)) >= sizeof(fname))
+		return -1;
+	if (strlcat(fname, ".", sizeof(fname)) >= sizeof(fname))
+		return -1;
 	switch (format & SAVE_FORMATS) {
 #ifdef USE_JPEG
 		case SAVE_JPEG:
-			strcat(fname, JPEG_EXT);
+			if (strlcat(fname, JPEG_EXT, sizeof(fname)) >= sizeof(fname))
+				return -1;
 			break;
 #endif /* USE_JPEG */
 #ifdef USE_TIFF
 		case SAVE_TIFF:
-			strcat(fname, TIFF_EXT);
+			if (strlcat(fname, TIFF_EXT, sizeof(fname)) >= sizeof(fname))
+				return -1;
 			break;
 #endif /* USE_TIFF */
 #ifdef USE_PNG
 		case SAVE_PNG:
-			strcat(fname, PNG_EXT);
+			if (strlcat(fname, PNG_EXT, sizeof(fname)) >= sizeof(fname))
+				return -1;
 			break;
 #endif /* USE_PNG */
 		default:
-			strcat(fname, (to_be_saved->components == 3) ? PPM_EXT : PGM_EXT );
+			if (strlcat(fname, (to_be_saved->components == 3) ? PPM_EXT : PGM_EXT, sizeof(fname)) >= sizeof(fname))
+				return -1;
 			break;
 	}
 
