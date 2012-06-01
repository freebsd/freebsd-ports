--- client/image.c.orig	2012-05-26 14:26:41.000000000 +0200
+++ client/image.c	2012-05-26 14:27:18.000000000 +0200
@@ -551,6 +551,8 @@
 			#pragma comment(lib, "../libs/libpng.lib")
 		#else
 			#include <png.h>
+			#include <pngpriv.h>
+			#include <zlib.h>
 		#endif
 	#endif
 
@@ -610,7 +612,7 @@
 		return (png_rgba = NULL);
 	}
 
-	if (setjmp(png->jmpbuf))
+	if (setjmp(png_jmpbuf(png)))
 	{
 error:
 		if (data)
@@ -636,7 +638,7 @@
 	}
 
 	if (colortype == PNG_COLOR_TYPE_GRAY && bitdepth < 8)
-		png_set_gray_1_2_4_to_8(png);
+		png_set_expand_gray_1_2_4_to_8(png);
 
 	if (png_get_valid( png, pnginfo, PNG_INFO_tRNS ))
 		png_set_tRNS_to_alpha(png);
@@ -712,7 +714,7 @@
 		return false;
     }
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
         png_destroy_write_struct(&png_ptr, &info_ptr);
         fclose(fp);
 		return false;
@@ -879,7 +881,7 @@
 #define GLOBAL(x) x
 
 GLOBAL(void)
-jpeg_mem_src (j_decompress_ptr cinfo, qbyte * infile, int maxlen)
+local_jpeg_mem_src (j_decompress_ptr cinfo, qbyte * infile, int maxlen)
 {
   my_source_mgr *src;
 
@@ -945,7 +947,7 @@
   }
   jpeg_create_decompress(&cinfo);
 
-  jpeg_mem_src(&cinfo, infile, length);
+  local_jpeg_mem_src(&cinfo, infile, length);
 
   (void) jpeg_read_header(&cinfo, TRUE);
 
@@ -1041,7 +1043,7 @@
 	dest->pub.free_in_buffer = OUTPUT_BUF_SIZE;
 }
 
-void jpeg_mem_dest (j_compress_ptr cinfo, vfsfile_t *vfs)
+void local_jpeg_mem_dest (j_compress_ptr cinfo, vfsfile_t *vfs)
 {
   my_destination_mgr *dest;
 
@@ -1101,7 +1103,7 @@
 
 	buffer = screendata;
 
-	jpeg_mem_dest(&cinfo, outfile);
+	local_jpeg_mem_dest(&cinfo, outfile);
 	cinfo.image_width = screenwidth;
 	cinfo.image_height = screenheight;
 	cinfo.input_components = 3;
