--- gl_image.c.orig	2005-05-19 20:56:13 UTC
+++ gl_image.c
@@ -555,7 +555,7 @@ typedef struct {
     size_t Pos;
 } TPngFileBuffer;
 
-void __cdecl PngReadFunc(png_struct *Png, png_bytep buf, png_size_t size)
+void PngReadFunc(png_struct *Png, png_bytep buf, png_size_t size)
 {
     TPngFileBuffer *PngFileBuffer=(TPngFileBuffer*)png_get_io_ptr(Png);
     memcpy(buf,PngFileBuffer->Buffer+PngFileBuffer->Pos,size);
@@ -621,7 +621,7 @@ void LoadPNG (const char *name, byte **p
 
 	png_read_info(png_ptr, info_ptr);
 
-	if (info_ptr->height > MAX_TEXTURE_DIMENSIONS)
+	if (png_get_image_height(png_ptr, info_ptr) > MAX_TEXTURE_DIMENSIONS)
 	{
         png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 		ri.FS_FreeFile (PngFileBuffer.Buffer);
@@ -629,28 +629,28 @@ void LoadPNG (const char *name, byte **p
 		return;
 	}
 
-	if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE)
+	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE)
 	{
 		png_set_palette_to_rgb (png_ptr);
 		png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
 	}
 
-	if (info_ptr->color_type == PNG_COLOR_TYPE_RGB)
+	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
 		png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
 
-	if ((info_ptr->color_type == PNG_COLOR_TYPE_GRAY) && info_ptr->bit_depth < 8)
+	if ((png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY) && png_get_bit_depth(png_ptr, info_ptr) < 8)
 		png_set_gray_1_2_4_to_8(png_ptr);
 
 	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
 		png_set_tRNS_to_alpha(png_ptr);
 
-	if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY || info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
+	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY || png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
 		png_set_gray_to_rgb(png_ptr);
 
-	if (info_ptr->bit_depth == 16)
+	if (png_get_bit_depth(png_ptr, info_ptr) == 16)
 		png_set_strip_16(png_ptr);
 
-	if (info_ptr->bit_depth < 8)
+	if (png_get_bit_depth(png_ptr, info_ptr) < 8)
         png_set_packing(png_ptr);
 
 	if (png_get_gAMA(png_ptr, info_ptr, &file_gamma))
@@ -660,15 +660,15 @@ void LoadPNG (const char *name, byte **p
 
 	rowbytes = png_get_rowbytes(png_ptr, info_ptr);
 
-	*pic = malloc (info_ptr->height * rowbytes);
+	*pic = malloc (png_get_image_height(png_ptr, info_ptr) * rowbytes);
 
-	for (i = 0; i < info_ptr->height; i++)
+	for (i = 0; i < png_get_image_height(png_ptr, info_ptr); i++)
 		row_pointers[i] = *pic + i*rowbytes;
 
 	png_read_image(png_ptr, row_pointers);
 
-	*width = info_ptr->width;
-	*height = info_ptr->height;
+	*width = png_get_image_width(png_ptr, info_ptr);
+	*height = png_get_image_height(png_ptr, info_ptr);
 
 	png_read_end(png_ptr, end_info);
 	png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
@@ -1007,24 +1007,24 @@ NiceAss: Code from Q2Ice
 =================================================================
 */
 
-void __cdecl jpg_null(j_decompress_ptr cinfo)
+void jpg_null(j_decompress_ptr cinfo)
 {
 }
 
-unsigned char __cdecl jpg_fill_input_buffer(j_decompress_ptr cinfo)
+unsigned char jpg_fill_input_buffer(j_decompress_ptr cinfo)
 {
     ri.Con_Printf(PRINT_ALL, "Premature end of JPEG data\n");
     return 1;
 }
 
-void __cdecl jpg_skip_input_data(j_decompress_ptr cinfo, long num_bytes)
+void jpg_skip_input_data(j_decompress_ptr cinfo, long num_bytes)
 {
         
     cinfo->src->next_input_byte += (size_t) num_bytes;
     cinfo->src->bytes_in_buffer -= (size_t) num_bytes;
 }
 
-void jpeg_mem_src(j_decompress_ptr cinfo, byte *mem, int len)
+void local_jpeg_mem_src(j_decompress_ptr cinfo, byte *mem, int len)
 {
     cinfo->src = (struct jpeg_source_mgr *)(*cinfo->mem->alloc_small)((j_common_ptr) cinfo, JPOOL_PERMANENT, sizeof(struct jpeg_source_mgr));
     cinfo->src->init_source = jpg_null;
@@ -1065,7 +1065,7 @@ void LoadJPG (const char *filename, byte
 
 	cinfo.err = jpeg_std_error(&jerr);
 	jpeg_create_decompress(&cinfo);
-	jpeg_mem_src(&cinfo, rawdata, rawsize);
+	local_jpeg_mem_src(&cinfo, rawdata, rawsize);
 	jpeg_read_header(&cinfo, true);
 	jpeg_start_decompress(&cinfo);
 
