--- camlibs/ax203/jpeg_memsrcdest.h.orig	2015-08-08 15:57:29 UTC
+++ camlibs/ax203/jpeg_memsrcdest.h
@@ -1,5 +1,7 @@
 #include <jpeglib.h>
 
+#if JPEG_LIB_VERSION < 80
+
 void
 jpeg_mem_src (j_decompress_ptr cinfo, unsigned char * buffer,
 	unsigned long bufsize);
@@ -7,3 +9,5 @@ jpeg_mem_src (j_decompress_ptr cinfo, un
 void
 jpeg_mem_dest (j_compress_ptr cinfo, unsigned char ** outbuffer,
 	unsigned long * outsize);
+
+#endif
