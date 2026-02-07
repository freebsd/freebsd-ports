--- win/vulture/vulture_gfl.cpp.orig
+++ win/vulture/vulture_gfl.cpp
@@ -21,12 +21,17 @@
 
 #define PNG_BYTES_TO_CHECK 4
 
+struct readbuff {char *buff; unsigned int len;};
 
 static void vulture_png_read_callback(png_structp png_ptr, png_bytep area, png_size_t size)
 {
-	char *mem = (char *)png_ptr->io_ptr;
-	memcpy(area, mem, size);
-	png_ptr->io_ptr = (mem + size);
+    unsigned int readlen;
+    struct readbuff *readfrom = (struct readbuff *)png_get_io_ptr(png_ptr);
+    readlen = (readfrom->len > size) ? size : readfrom->len;
+    memcpy(area, readfrom->buff, readlen);
+    size = readlen;
+    readfrom->len -= readlen;
+    readfrom->buff += readlen;
 }
 
 /*--------------------------------------------------------------------------
@@ -44,6 +49,7 @@
 	int bit_depth, color_type, row;
 	png_bytep * row_pointers = NULL;
 	SDL_Surface *img, *convert;
+	struct readbuff readfrom;
 
 	/* vulture_load_surface converts everything to screen format for faster blitting
 	* so we can't continue if we don't have a screen yet */
@@ -54,6 +60,9 @@
 	if (!srcbuf)
 		return NULL;
 
+	if (buflen < PNG_BYTES_TO_CHECK)
+         return NULL;
+
 	img = NULL;
 
 	/* memory region must contain a png file */
@@ -71,10 +80,13 @@
 		goto out;
 
 	/* Set up error handling */
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 		goto out;
 
-	png_set_read_fn(png_ptr, (char *)srcbuf, vulture_png_read_callback);
+	readfrom.buff = (char *)srcbuf;
+	readfrom.len = buflen;
+
+	png_set_read_fn(png_ptr, &readfrom, vulture_png_read_callback);
 
 	/* Read PNG header info */
 	png_read_info(png_ptr, info_ptr);
@@ -92,8 +104,9 @@
 	png_set_gray_to_rgb(png_ptr);
 
 	/* add an opaque alpha channel to anything that doesn't have one yet */
-	png_set_filler(png_ptr, 0xff, PNG_FILLER_AFTER);
-	info_ptr->color_type |= PNG_COLOR_MASK_ALPHA;
+	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB ||
+            png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY)
+            png_set_add_alpha(png_ptr, 0xff, PNG_FILLER_AFTER);
 
 	/* get the component mask for the surface */
 	if ( SDL_BYTEORDER == SDL_LIL_ENDIAN )
