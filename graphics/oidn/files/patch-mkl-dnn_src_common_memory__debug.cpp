--- mkl-dnn/src/common/memory_debug.cpp.orig	2020-09-12 19:21:13 UTC
+++ mkl-dnn/src/common/memory_debug.cpp
@@ -21,7 +21,7 @@
 #include <windows.h>
 #endif
 
-#if defined __linux__ || defined __APPLE__
+#if defined __linux__ || defined __APPLE__ || defined __FreeBSD__
 #include <unistd.h>
 #include <sys/mman.h>
 #endif
