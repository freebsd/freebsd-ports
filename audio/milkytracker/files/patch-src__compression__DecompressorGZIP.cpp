--- ./src/compression/DecompressorGZIP.cpp.orig	2013-03-22 17:21:02.000000000 +0100
+++ ./src/compression/DecompressorGZIP.cpp	2013-03-22 17:21:46.000000000 +0100
@@ -57,11 +57,11 @@
 	
 bool DecompressorGZIP::decompress(const PPSystemString& outFileName, Hints hint)
 {
-    gzFile *gz_input_file = NULL;
+	gzFile gz_input_file = NULL;
 	int len = 0;
 	pp_uint8 *buf;
 	
-	if ((gz_input_file = (void **)gzopen (fileName.getStrBuffer(), "r")) == NULL)
+	if ((gz_input_file = gzopen (fileName.getStrBuffer(), "r")) == NULL)
 		return false;
 	
 	if ((buf = new pp_uint8[0x10000]) == NULL)
