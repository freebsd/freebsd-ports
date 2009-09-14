--- src/FileChannel.cpp.orig	2009-09-12 13:08:28.000000000 +0400
+++ src/FileChannel.cpp	2009-09-12 13:08:41.000000000 +0400
@@ -248,7 +248,7 @@
 
 QString FileChannel::errorString()
 {
-    strcpy(lastErrorString, strerror_r(errno, lastErrorString, 0));
+    strcpy(lastErrorString, strerror(errno));
     return QString(trUtf8(lastErrorString));
 }
 
