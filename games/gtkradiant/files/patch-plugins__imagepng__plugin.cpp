--- plugins/imagepng/plugin.cpp.orig	2006-02-10 23:01:20.000000000 +0100
+++ plugins/imagepng/plugin.cpp	2012-05-26 20:07:52.000000000 +0200
@@ -41,7 +41,7 @@
 void user_error_fn(png_structp png_ptr, png_const_charp error_msg)
 {
   globalErrorStream() << "libpng error: " << error_msg << "\n";
-  longjmp(png_ptr->jmpbuf, 0);
+  longjmp(png_jmpbuf(png_ptr), 0);
 }
 
 void user_read_data(png_structp png_ptr, png_bytep data, png_uint_32 length)
@@ -87,9 +87,9 @@
   }
 
   // configure the read function
-  png_set_read_fn(png_ptr, (voidp)&p_fbuffer, (png_rw_ptr)&user_read_data);
+  png_set_read_fn(png_ptr, &p_fbuffer, (png_rw_ptr)&user_read_data);
 
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_read_struct(&png_ptr, &info_ptr,
       &end_info);
     return 0;
@@ -108,7 +108,7 @@
    png_set_palette_to_rgb(png_ptr);
 
   if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
-    png_set_gray_1_2_4_to_8(png_ptr);
+    png_set_expand_gray_1_2_4_to_8(png_ptr);
 
   if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
     png_set_tRNS_to_alpha(png_ptr);
@@ -153,7 +153,7 @@
   png_read_end(png_ptr, info_ptr);
 
   /* free up the memory structure */
-  png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
+  png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 
   free(row_pointers);
 
