--- platforms/Cross/plugins/JPEGReadWriter2Plugin/JPEGReadWriter2Plugin.h.orig	Thu May 13 16:09:52 2004
+++ platforms/Cross/plugins/JPEGReadWriter2Plugin/JPEGReadWriter2Plugin.h	Thu May 13 16:10:08 2004
@@ -14,4 +14,5 @@
 void error_exit (j_common_ptr cinfo);
 GLOBAL(void) jpeg_mem_src (j_decompress_ptr cinfo, char * pSourceData, unsigned sourceDataSize);
 GLOBAL(int) jpeg_mem_src_newLocationOfData (j_decompress_ptr cinfo, char * pSourceData, unsigned sourceDataSize);
-GLOBAL(void) jpeg_mem_dest (j_compress_ptr cinfo, char * pDestination, unsigned *pDestinationSize);
\ No newline at end of file
+GLOBAL(void) jpeg_mem_dest (j_compress_ptr cinfo, char * pDestination, unsigned *pDestinationSize);
+
