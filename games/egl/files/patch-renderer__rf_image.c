--- renderer/rf_image.c.orig	2014-12-25 10:53:09 UTC
+++ renderer/rf_image.c
@@ -32,6 +32,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #else
 # include <jpeglib.h>
 # include <png.h>
+# include <zlib.h>
 #endif
 
 #define MAX_IMAGE_HASH			(MAX_IMAGES/4)
@@ -44,7 +45,7 @@ static uint32	*r_imageResampleScratch;
 image_t			*r_lmTextures[R_MAX_LIGHTMAPS];
 static image_t	r_imageList[MAX_IMAGES];
 static image_t	*r_imageHashTree[MAX_IMAGE_HASH];
-static uint32	r_numImages;
+uint32	r_numImages;
 
 static byte		r_intensityTable[256];
 static byte		r_gammaTable[256];
@@ -261,21 +262,6 @@ static void jpg_skip_input_data(j_decomp
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
@@ -601,46 +587,46 @@ static void R_LoadPNG (char *name, byte 
 	png_read_info (png_ptr, info_ptr);
 
 	// Color
-	if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
+	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE) {
 		png_set_palette_to_rgb (png_ptr);
 		png_read_update_info (png_ptr, info_ptr);
 	}
 
-	if (info_ptr->color_type == PNG_COLOR_TYPE_RGB)
+	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
 		png_set_filler (png_ptr, 0xFF, PNG_FILLER_AFTER);
 
-	if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY && info_ptr->bit_depth < 8)
-		png_set_gray_1_2_4_to_8 (png_ptr);
+	if (png_get_color_type(png_ptr, info_ptr)  == PNG_COLOR_TYPE_GRAY && png_get_bit_depth(png_ptr, info_ptr) < 8)
+		png_set_expand_gray_1_2_4_to_8 (png_ptr);
 
 	if (png_get_valid (png_ptr, info_ptr, PNG_INFO_tRNS))
 		png_set_tRNS_to_alpha (png_ptr);
 
-	if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY || info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
+	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY || png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
 		png_set_gray_to_rgb (png_ptr);
 
-	if (info_ptr->bit_depth == 16)
+	if (png_get_bit_depth(png_ptr, info_ptr) == 16)
 		png_set_strip_16 (png_ptr);
 
-	if (info_ptr->bit_depth < 8)
+	if (png_get_bit_depth(png_ptr, info_ptr) < 8)
         png_set_packing (png_ptr);
 
 	png_read_update_info (png_ptr, info_ptr);
 
 	rowbytes = png_get_rowbytes (png_ptr, info_ptr);
 
-	if (!info_ptr->channels) {
+	if (!png_get_channels(png_ptr, info_ptr)) {
 		png_destroy_read_struct (&png_ptr, &info_ptr, (png_infopp)NULL);
 		Com_Printf (PRNT_WARNING, "R_LoadPNG: Bad PNG file: %s\n", name);
 		FS_FreeFile (PngFileBuffer.buffer);
 	}
 
-	pic_ptr = Mem_PoolAllocExt (info_ptr->height * rowbytes, qFalse, ri.imageSysPool, r_imageAllocTag);
+	pic_ptr = Mem_PoolAllocExt (png_get_image_height(png_ptr, info_ptr) * rowbytes, qFalse, ri.imageSysPool, r_imageAllocTag);
 	if (pic)
 		*pic = pic_ptr;
 
-	row_pointers = Mem_PoolAllocExt (sizeof (png_bytep) * info_ptr->height, qFalse, ri.imageSysPool, r_imageAllocTag);
+	row_pointers = Mem_PoolAllocExt (sizeof (png_bytep) * png_get_image_height(png_ptr, info_ptr), qFalse, ri.imageSysPool, r_imageAllocTag);
 
-	for (i=0 ; i<info_ptr->height ; i++) {
+	for (i=0 ; i<png_get_image_height(png_ptr, info_ptr) ; i++) {
 		row_pointers[i] = pic_ptr;
 		pic_ptr += rowbytes;
 	}
@@ -648,11 +634,11 @@ static void R_LoadPNG (char *name, byte 
 	png_read_image (png_ptr, row_pointers);
 
 	if (width)
-		*width = info_ptr->width;
+		*width = png_get_image_width(png_ptr, info_ptr);
 	if (height)
-		*height = info_ptr->height;
+		*height = png_get_image_height(png_ptr, info_ptr);
 	if (samples)
-		*samples = info_ptr->channels;
+		*samples = png_get_channels(png_ptr, info_ptr);
 
 	png_read_end (png_ptr, end_info);
 	png_destroy_read_struct (&png_ptr, &info_ptr, &end_info);
