--- src/mp3transcode/mp3transcode.cpp.orig	2007-09-27 17:37:07.000000000 +0300
+++ src/mp3transcode/mp3transcode.cpp	2008-09-08 01:43:36.000000000 +0300
@@ -281,7 +281,7 @@
 {
     int length;
     int cnt;
-    length = qMin( numBytes, ssize_t( getDecodedBufferFilled() ) );
+    length = qMin( numBytes, getDecodedBufferFilled() );
 
     while (length > 0)
     {
