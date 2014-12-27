$NetBSD: patch-input-png.c,v 1.1 2011/02/07 00:37:54 wiz Exp $

Fix build with png-1.5.

--- input-png.c.orig	2002-10-10 20:44:14.000000000 +0000
+++ input-png.c
@@ -42,17 +42,17 @@ static png_bytep * read_png(png_structp 
 
 static void handle_warning(png_structp png, const at_string message) {
         LOG1("PNG warning: %s", message);
-	at_exception_warning((at_exception_type *)png->error_ptr,
+	at_exception_warning((at_exception_type *)png_get_error_ptr(png),
 			     message);
-	/* at_exception_fatal((at_exception_type *)at_png->error_ptr,
+	/* at_exception_fatal((at_exception_type *)png_get_error_ptr(at_png),
 	   "PNG warning"); */
 }
 
 static void handle_error(png_structp png, const at_string message) {
 	LOG1("PNG error: %s", message);
-	at_exception_fatal((at_exception_type *)png->error_ptr,
+	at_exception_fatal((at_exception_type *)png_get_error_ptr(png),
 			   message);
-	/* at_exception_fatal((at_exception_type *)at_png->error_ptr,
+	/* at_exception_fatal((at_exception_type *)png_get_error_ptr(at_png),
 	   "PNG error"); */
 	
 }
@@ -106,7 +106,8 @@ static int load_image(at_bitmap_type *im
 	png_init_io(png, stream);
 	CHECK_ERROR();
 	
-	rows = read_png(png, info, opts);
+	png_read_png(png, info, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, 0);
+	rows = png_get_rows(png, info);
 
 	width = (unsigned short)png_get_image_width(png, info);
 	height = (unsigned short)png_get_image_height(png, info);
@@ -145,56 +146,3 @@ at_bitmap_type input_png_reader(at_strin
 
 	return image;
 }
-
-static png_bytep *
-read_png(png_structp png_ptr, png_infop info_ptr, at_input_opts_type * opts)
-{
-	int row;
-	png_color_16p original_bg;
-	png_color_16  my_bg;
-
-	png_read_info(png_ptr, info_ptr);
-
-	png_set_strip_16(png_ptr);
-	png_set_packing(png_ptr);
-	if ((png_ptr->bit_depth < 8) ||
-	    (png_ptr->color_type == PNG_COLOR_TYPE_PALETTE) ||
-	    (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)))
-		png_set_expand(png_ptr);
-
-	if (png_get_bKGD(png_ptr, info_ptr, &original_bg)) {
-		/* Fill transparent region with ... */
-		my_bg.index = 0;
-
-		if (opts && opts->background_color) {
-			my_bg.red   = 256 * opts->background_color->r;
-			my_bg.green = 256 * opts->background_color->g;
-			my_bg.blue  = 256 * opts->background_color->b;
-			my_bg.gray  = 256* ((opts->background_color->r
-					     + opts->background_color->g
-					     + opts->background_color->b) / 3);
-		} else
-			  /* else, use white */
-			  my_bg.red = my_bg.green = my_bg.blue = my_bg.gray = 0xFFFF;
-		
-		png_set_background(png_ptr, &my_bg,
-				   PNG_BACKGROUND_GAMMA_FILE, 1, 1.0);
-	} else
-		png_set_strip_alpha(png_ptr);
-	png_read_update_info(png_ptr, info_ptr);
-
-
-	info_ptr->row_pointers = (png_bytepp)png_malloc(png_ptr,
-							info_ptr->height * sizeof(png_bytep));
-#ifdef PNG_FREE_ME_SUPPORTED
-	info_ptr->free_me |= PNG_FREE_ROWS;
-#endif
-	for (row = 0; row < (int)info_ptr->height; row++)
-		info_ptr->row_pointers[row] = (png_bytep)png_malloc(png_ptr,
-								    png_get_rowbytes(png_ptr, info_ptr));
-	
-	png_read_image(png_ptr, info_ptr->row_pointers);
-	info_ptr->valid |= PNG_INFO_IDAT;
-	png_read_end(png_ptr, info_ptr);
-	return png_get_rows(png_ptr, info_ptr);
-}
