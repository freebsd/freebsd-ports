--- lib/xwin.c.orig	2012-03-24 18:00:49 UTC
+++ lib/xwin.c
@@ -841,13 +841,13 @@ build_image (image *src)
   png_ptr = png_create_read_struct (PNG_LIBPNG_VER_STRING, 0, 0, 0);
   info_ptr = png_create_info_struct (png_ptr);
 
-  if (setjmp (png_ptr->jmpbuf)) {
+  if (setjmp (png_jmpbuf(png_ptr))) {
     fprintf(stderr, "Invalid PNG image!\n");
     return;
   }
 
   file_bytes = src->file_data;
-  png_set_read_fn (png_ptr, (voidp)&file_bytes, (png_rw_ptr)png_reader);
+  png_set_read_fn (png_ptr, (png_voidp)&file_bytes, (png_rw_ptr)png_reader);
 
   png_read_info (png_ptr, info_ptr);
 
