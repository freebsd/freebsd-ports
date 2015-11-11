--- sope-core/NGStreams/NGByteCountStream.m.orig	2015-09-16 18:26:50 UTC
+++ sope-core/NGStreams/NGByteCountStream.m
@@ -87,7 +87,7 @@
   {
     register unsigned char *byteBuffer = _buf;
 
-    for (_len = result - 1; _len >= 0; _len--, byteBuffer++) {
+    for (NSInteger len = result - 1; len >= 0; len--, byteBuffer++) {
       if (*byteBuffer == byteToCount)
         byteReadCount++;
     }
@@ -106,7 +106,7 @@
   {
     register unsigned char *byteBuffer = (unsigned char *)_buf;
 
-    for (_len = result - 1; _len >= 0; _len--, byteBuffer++) {
+    for (NSInteger len = result - 1; len >= 0; len--, byteBuffer++) {
       if (*byteBuffer == byteToCount)
         byteWriteCount++;
     }
