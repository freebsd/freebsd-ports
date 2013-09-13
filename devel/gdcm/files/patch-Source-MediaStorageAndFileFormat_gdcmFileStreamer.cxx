--- Source/MediaStorageAndFileFormat/gdcmFileStreamer.cxx.orig	2013-09-11 14:54:55.000000000 +0200
+++ Source/MediaStorageAndFileFormat/gdcmFileStreamer.cxx	2013-09-11 14:55:27.000000000 +0200
@@ -32,7 +32,7 @@
 #include <io.h>
 typedef int64_t off64_t;
 #else
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #  define off64_t off_t
 #endif
 #include <unistd.h> // ftruncate
