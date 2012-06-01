--- gl_image.c.orig	2005-05-19 22:56:13.000000000 +0200
+++ gl_image.c	2012-04-29 07:01:09.000000000 +0200
@@ -20,6 +20,7 @@
 
 #include "gl_local.h"
 #include <png.h>
+#include <pngpriv.h>
 #include <jpeglib.h>
 #include "redblack.h"
 
@@ -555,7 +556,7 @@
     size_t Pos;
 } TPngFileBuffer;
 
-void __cdecl PngReadFunc(png_struct *Png, png_bytep buf, png_size_t size)
+void PngReadFunc(png_struct *Png, png_bytep buf, png_size_t size)
 {
     TPngFileBuffer *PngFileBuffer=(TPngFileBuffer*)png_get_io_ptr(Png);
     memcpy(buf,PngFileBuffer->Buffer+PngFileBuffer->Pos,size);
@@ -1007,24 +1008,24 @@
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
@@ -1065,7 +1066,7 @@
 
 	cinfo.err = jpeg_std_error(&jerr);
 	jpeg_create_decompress(&cinfo);
-	jpeg_mem_src(&cinfo, rawdata, rawsize);
+	local_jpeg_mem_src(&cinfo, rawdata, rawsize);
 	jpeg_read_header(&cinfo, true);
 	jpeg_start_decompress(&cinfo);
 
