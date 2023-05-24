--- IMG_png.c.orig	2012-01-21 01:51:33 UTC
+++ IMG_png.c
@@ -78,26 +78,26 @@
 static struct {
 	int loaded;
 	void *handle;
-	png_infop (*png_create_info_struct) (png_structp png_ptr);
+	png_infop (*png_create_info_struct) (png_const_structp png_ptr);
 	png_structp (*png_create_read_struct) (png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn);
 	void (*png_destroy_read_struct) (png_structpp png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr);
-	png_uint_32 (*png_get_IHDR) (png_structp png_ptr, png_infop info_ptr, png_uint_32 *width, png_uint_32 *height, int *bit_depth, int *color_type, int *interlace_method, int *compression_method, int *filter_method);
-	png_voidp (*png_get_io_ptr) (png_structp png_ptr);
-	png_byte (*png_get_channels) (png_structp png_ptr, png_infop info_ptr);
-	png_uint_32 (*png_get_PLTE) (png_structp png_ptr, png_infop info_ptr, png_colorp *palette, int *num_palette);
-	png_uint_32 (*png_get_tRNS) (png_structp png_ptr, png_infop info_ptr, png_bytep *trans, int *num_trans, png_color_16p *trans_values);
-	png_uint_32 (*png_get_valid) (png_structp png_ptr, png_infop info_ptr, png_uint_32 flag);
-	void (*png_read_image) (png_structp png_ptr, png_bytepp image);
-	void (*png_read_info) (png_structp png_ptr, png_infop info_ptr);
-	void (*png_read_update_info) (png_structp png_ptr, png_infop info_ptr);
-	void (*png_set_expand) (png_structp png_ptr);
-	void (*png_set_gray_to_rgb) (png_structp png_ptr);
-	void (*png_set_packing) (png_structp png_ptr);
-	void (*png_set_read_fn) (png_structp png_ptr, png_voidp io_ptr, png_rw_ptr read_data_fn);
-	void (*png_set_strip_16) (png_structp png_ptr);
-	int (*png_sig_cmp) (png_bytep sig, png_size_t start, png_size_t num_to_check);
+	png_uint_32 (*png_get_IHDR) (png_const_structrp png_ptr, png_const_inforp info_ptr, png_uint_32 *width, png_uint_32 *height, int *bit_depth, int *color_type, int *interlace_method, int *compression_method, int *filter_method);
+	png_voidp (*png_get_io_ptr) (png_const_structrp png_ptr);
+	png_byte (*png_get_channels) (png_const_structrp png_ptr, png_const_inforp info_ptr);
+	png_uint_32 (*png_get_PLTE) (png_const_structrp png_ptr, png_infop info_ptr, png_colorp *palette, int *num_palette);
+	png_uint_32 (*png_get_tRNS) (png_const_structrp png_ptr, png_infop info_ptr, png_bytep *trans, int *num_trans, png_color_16p *trans_values);
+	png_uint_32 (*png_get_valid) (png_const_structrp png_ptr, png_const_inforp info_ptr, png_uint_32 flag);
+	void (*png_read_image) (png_structrp png_ptr, png_bytepp image);
+	void (*png_read_info) (png_structrp png_ptr, png_infop info_ptr);
+	void (*png_read_update_info) (png_structrp png_ptr, png_infop info_ptr);
+	void (*png_set_expand) (png_structrp png_ptr);
+	void (*png_set_gray_to_rgb) (png_structrp png_ptr);
+	void (*png_set_packing) (png_structrp png_ptr);
+	void (*png_set_read_fn) (png_structrp png_ptr, png_voidp io_ptr, png_rw_ptr read_data_fn);
+	void (*png_set_strip_16) (png_structrp png_ptr);
+	int (*png_sig_cmp) (png_const_bytep sig, png_size_t start, png_size_t num_to_check);
 #ifndef LIBPNG_VERSION_12
-	jmp_buf* (*png_set_longjmp_fn) (png_structp, png_longjmp_ptr, size_t);
+	jmp_buf* (*png_set_longjmp_fn) (png_structrp, png_longjmp_ptr, size_t);
 #endif
 } lib;
 
@@ -237,7 +237,7 @@ int IMG_InitPNG()
 		}
 #ifndef LIBPNG_VERSION_12
 		lib.png_set_longjmp_fn =
-			(jmp_buf * (*) (png_structp, png_longjmp_ptr, size_t))
+			(jmp_buf * (*) (png_structrp, png_longjmp_ptr, size_t))
 			SDL_LoadFunction(lib.handle, "png_set_longjmp_fn");
 		if ( lib.png_set_longjmp_fn == NULL ) {
 			SDL_UnloadObject(lib.handle);
