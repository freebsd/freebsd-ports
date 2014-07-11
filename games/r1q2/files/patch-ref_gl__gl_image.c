--- ref_gl/gl_image.c.orig	2012-04-29 06:56:19.000000000 +0200
+++ ref_gl/gl_image.c	2012-04-29 06:56:40.000000000 +0200
@@ -20,6 +20,7 @@ Foundation, Inc., 59 Temple Place - Suit
 
 #include "gl_local.h"
 #include <png.h>
+#include <pngpriv.h>
 #include <jpeglib.h>
 
 image_t		gltextures[MAX_GLTEXTURES];
@@ -739,7 +740,7 @@ void LoadPNG (const char *name, byte **p
 		png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
 
 	if ((info_ptr->color_type == PNG_COLOR_TYPE_GRAY) && info_ptr->bit_depth < 8)
-		png_set_gray_1_2_4_to_8(png_ptr);
+		png_set_expand_gray_1_2_4_to_8(png_ptr);
 
 	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
 		png_set_tRNS_to_alpha(png_ptr);
@@ -1520,7 +1521,7 @@ void EXPORT jpg_skip_input_data(j_decomp
     cinfo->src->bytes_in_buffer -= (size_t) num_bytes;
 }
 
-void jpeg_mem_src (j_decompress_ptr cinfo, byte *mem, int len)
+void local_jpeg_mem_src (j_decompress_ptr cinfo, byte *mem, int len)
 {
     cinfo->src = (struct jpeg_source_mgr *)(*cinfo->mem->alloc_small)((j_common_ptr) cinfo, JPOOL_PERMANENT, sizeof(struct jpeg_source_mgr));
     cinfo->src->init_source = jpg_null;
@@ -1561,7 +1562,7 @@ void LoadJPG (const char *filename, byte
 
 	cinfo.err = jpeg_std_error(&jerr);
 	jpeg_create_decompress(&cinfo);
-	jpeg_mem_src(&cinfo, rawdata, rawsize);
+	local_jpeg_mem_src(&cinfo, rawdata, rawsize);
 	jpeg_read_header(&cinfo, true);
 	jpeg_start_decompress(&cinfo);
 
