--- src/ref_gl/gl_image.c.orig	2006-06-02 18:14:31 UTC
+++ src/ref_gl/gl_image.c
@@ -477,7 +477,7 @@ Scrap_Upload(void)
 /*
  * ============== LoadPCX ==============
  */
-void
+static void
 LoadPCX(char *filename, byte ** pic, byte ** palette, int *width, int *height)
 {
 	byte           *raw;
@@ -602,7 +602,7 @@ typedef struct _TargaHeader {
  * ============= LoadTGA NiceAss: LoadTGA() from Q2Ice, it supports more
  * formats =============
  */
-void
+static void
 LoadTGA(char *filename, byte ** pic, int *width, int *height)
 {
 	int		w, h, x, y, i, temp1, temp2;
@@ -888,19 +888,19 @@ LoadTGA(char *filename, byte ** pic, int *width, int *
  * =================================================================
  */
 
-void
+static void
 jpg_null(j_decompress_ptr cinfo)
 {
 }
 
-boolean
+static boolean
 jpg_fill_input_buffer(j_decompress_ptr cinfo)
 {
 	ri.Con_Printf(PRINT_ALL, "Premature end of JPEG data\n");
 	return 1;
 }
 
-void
+static void
 jpg_skip_input_data(j_decompress_ptr cinfo, long num_bytes)
 {
 
@@ -911,8 +911,8 @@ jpg_skip_input_data(j_decompress_ptr cinfo, long num_b
 		ri.Con_Printf(PRINT_ALL, "Premature end of JPEG data\n");
 }
 
-void
-jpeg_mem_src(j_decompress_ptr cinfo, byte * mem, int len)
+static void
+local_jpeg_mem_src(j_decompress_ptr cinfo, byte *mem, int len)
 {
 	cinfo->src = (struct jpeg_source_mgr *)(*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT, sizeof(struct jpeg_source_mgr));
 	cinfo->src->init_source = jpg_null;
@@ -927,7 +927,7 @@ jpeg_mem_src(j_decompress_ptr cinfo, byte * mem, int l
 /*
  * ============== LoadJPG ==============
  */
-void
+static void
 LoadJPG(char *filename, byte ** pic, int *width, int *height)
 {
 	struct jpeg_decompress_struct cinfo;
@@ -956,7 +956,7 @@ LoadJPG(char *filename, byte ** pic, int *width, int *
 	jpeg_create_decompress(&cinfo);
 
 	/* Feed JPEG memory into the libJpeg Object */
-	jpeg_mem_src(&cinfo, rawdata, rawsize);
+	local_jpeg_mem_src(&cinfo, rawdata, rawsize);
 
 	/* Process JPEG header */
 	jpeg_read_header(&cinfo, true);
@@ -1139,7 +1139,7 @@ fReadData(png_structp png, png_bytep data, png_size_t 
  * =============================================================
  */
 
-void
+static void
 LoadPNG(char *filename, byte ** pic, int *width, int *height)
 {
 	png_structp	png;
@@ -1186,7 +1186,7 @@ LoadPNG(char *filename, byte ** pic, int *width, int *
 	if (my_png->ColorType == PNG_COLOR_TYPE_PALETTE)
 		png_set_palette_to_rgb(png);
 	if (my_png->ColorType == PNG_COLOR_TYPE_GRAY && my_png->BitDepth < 8)
-		png_set_gray_1_2_4_to_8(png);
+		png_set_expand_gray_1_2_4_to_8(png);
 
 	/* Add alpha channel if present */
 	if (png_get_valid(png, pnginfo, PNG_INFO_tRNS))
