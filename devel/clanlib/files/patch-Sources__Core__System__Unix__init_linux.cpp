--- ./Sources/Core/System/Unix/init_linux.cpp.orig	2012-03-05 06:24:31.000000000 -0500
+++ ./Sources/Core/System/Unix/init_linux.cpp	2012-09-25 07:42:19.000000000 -0400
@@ -111,7 +111,7 @@
 
 #else
 #ifndef PROC_EXE_PATH
-#define PROC_EXE_PATH "/proc/self/exe"
+#define PROC_EXE_PATH "/proc/curproc/file"
 #endif
 	int size;
 	struct stat sb;
