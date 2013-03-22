--- ./src/compression/DecompressorGZIP.cpp.orig	2013-03-22 15:58:05.955397673 +0100
+++ ./src/compression/DecompressorGZIP.cpp	2013-03-22 15:59:20.987397134 +0100
@@ -57,11 +57,13 @@
 	
 bool DecompressorGZIP::decompress(const PPSystemString& outFileName, Hints hint)
 {
-    gzFile *gz_input_file = NULL;
+//    gzFile *gz_input_file = NULL;
+	gzFile gz_input_file = NULL;
 	int len = 0;
 	pp_uint8 *buf;
 	
-	if ((gz_input_file = (void **)gzopen (fileName.getStrBuffer(), "r")) == NULL)
+//	if ((gz_input_file = (void **)gzopen (fileName.getStrBuffer(), "r")) == NULL)
+	if ((gz_input_file = gzopen (fileName.getStrBuffer(), "r")) == NULL)
 		return false;
 	
 	if ((buf = new pp_uint8[0x10000]) == NULL)
