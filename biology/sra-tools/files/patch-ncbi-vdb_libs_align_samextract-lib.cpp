--- ncbi-vdb/libs/align/samextract-lib.cpp.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/libs/align/samextract-lib.cpp
@@ -48,7 +48,7 @@
 #include <stdlib.h>
 #include <string.h>
 
-#if LINUX
+#if BSD || LINUX
 #include <unistd.h>
 #define DFL_THREAD_COUNT ((int)sysconf( _SC_NPROCESSORS_ONLN ) - 1)
 #else
