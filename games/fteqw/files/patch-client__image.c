--- client/image.c.orig	2014-12-25 11:05:11 UTC
+++ client/image.c
@@ -551,6 +551,7 @@ return NULL;
 			#pragma comment(lib, "../libs/libpng.lib")
 		#else
 			#include <png.h>
+			#include <zlib.h>
 		#endif
 	#endif
 
@@ -573,7 +574,7 @@ void PNGAPI png_default_read_data(png_st
 
 void VARGS readpngdata(png_structp png_ptr,png_bytep data,png_size_t len)
 {
-	pngreadinfo_t *ri = (pngreadinfo_t*)png_ptr->io_ptr;
+	pngreadinfo_t *ri = (pngreadinfo_t*)png_get_io_ptr(png_ptr);
 	if (ri->readposition+len > ri->filelen)
 	{
 		png_error(png_ptr, "unexpected eof");
@@ -610,7 +611,7 @@ qbyte *ReadPNGFile(qbyte *buf, int lengt
 		return (png_rgba = NULL);
 	}
 
-	if (setjmp(png->jmpbuf))
+	if (setjmp(png_jmpbuf(png)))
 	{
 error:
 		if (data)
@@ -636,7 +637,7 @@ error:
 	}
 
 	if (colortype == PNG_COLOR_TYPE_GRAY && bitdepth < 8)
-		png_set_gray_1_2_4_to_8(png);
+		png_set_expand_gray_1_2_4_to_8(png);
 
 	if (png_get_valid( png, pnginfo, PNG_INFO_tRNS ))
 		png_set_tRNS_to_alpha(png);
@@ -712,7 +713,7 @@ int Image_WritePNG (char *filename, int 
 		return false;
     }
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
         png_destroy_write_struct(&png_ptr, &info_ptr);
         fclose(fp);
 		return false;
@@ -879,7 +880,7 @@ term_source (j_decompress_ptr cinfo)
 #define GLOBAL(x) x
 
 GLOBAL(void)
-jpeg_mem_src (j_decompress_ptr cinfo, qbyte * infile, int maxlen)
+local_jpeg_mem_src (j_decompress_ptr cinfo, qbyte * infile, int maxlen)
 {
   my_source_mgr *src;
 
@@ -945,7 +946,7 @@ badjpeg:
   }
   jpeg_create_decompress(&cinfo);
 
-  jpeg_mem_src(&cinfo, infile, length);
+  local_jpeg_mem_src(&cinfo, infile, length);
 
   (void) jpeg_read_header(&cinfo, TRUE);
 
@@ -1041,7 +1042,7 @@ METHODDEF(void) term_destination (j_comp
 	dest->pub.free_in_buffer = OUTPUT_BUF_SIZE;
 }
 
-void jpeg_mem_dest (j_compress_ptr cinfo, vfsfile_t *vfs)
+void local_jpeg_mem_dest (j_compress_ptr cinfo, vfsfile_t *vfs)
 {
   my_destination_mgr *dest;
 
@@ -1101,7 +1102,7 @@ void screenshotJPEG(char *filename, int 
 
 	buffer = screendata;
 
-	jpeg_mem_dest(&cinfo, outfile);
+	local_jpeg_mem_dest(&cinfo, outfile);
 	cinfo.image_width = screenwidth;
 	cinfo.image_height = screenheight;
 	cinfo.input_components = 3;
