--- src/file_reader.cpp.orig	2018-07-11 01:18:06.970719000 +0000
+++ src/file_reader.cpp	2018-07-11 01:18:17.646078000 +0000
@@ -28,6 +28,7 @@
 #include <fcntl.h>
 #include <lzma.h>
 #include <pthread.h>
+#include <unistd.h>
 
 #if defined(ENABLE_ZLIB)
 #include <zlib.h>
