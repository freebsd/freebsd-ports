
--- renderer/rf_image.c.orig	2010-07-08 22:47:22.720284451 +0200
+++ renderer/rf_image.c	2010-07-08 22:53:00.496664288 +0200
@@ -44,7 +44,7 @@
 image_t			*r_lmTextures[R_MAX_LIGHTMAPS];
 static image_t	r_imageList[MAX_IMAGES];
 static image_t	*r_imageHashTree[MAX_IMAGE_HASH];
-static uint32	r_numImages;
+uint32	r_numImages;
 
 static byte		r_intensityTable[256];
 static byte		r_gammaTable[256];
@@ -261,21 +261,6 @@
     cinfo->src->bytes_in_buffer -= (size_t) num_bytes;
 }
 
-static void jpeg_mem_src (j_decompress_ptr cinfo, byte *mem, int len)
-{
-    cinfo->src = (struct jpeg_source_mgr *)
-	(*cinfo->mem->alloc_small)((j_common_ptr) cinfo,
-				   JPOOL_PERMANENT,
-				   sizeof(struct jpeg_source_mgr));
-    cinfo->src->init_source = jpg_noop;
-    cinfo->src->fill_input_buffer = jpg_fill_input_buffer;
-    cinfo->src->skip_input_data = jpg_skip_input_data;
-    cinfo->src->resync_to_restart = jpeg_resync_to_restart;
-    cinfo->src->term_source = jpg_noop;
-    cinfo->src->bytes_in_buffer = len;
-    cinfo->src->next_input_byte = mem;
-}
-
 /*
 =============
 R_LoadJPG
@@ -610,7 +595,7 @@
 		png_set_filler (png_ptr, 0xFF, PNG_FILLER_AFTER);
 
 	if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY && info_ptr->bit_depth < 8)
-		png_set_gray_1_2_4_to_8 (png_ptr);
+		png_set_expand_gray_1_2_4_to_8 (png_ptr);
 
 	if (png_get_valid (png_ptr, info_ptr, PNG_INFO_tRNS))
 		png_set_tRNS_to_alpha (png_ptr);


