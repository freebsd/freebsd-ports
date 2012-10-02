--- ./Sources/Core/System/Unix/init_linux.cpp.orig	2012-09-26 07:30:30.000000000 -0400
+++ ./Sources/Core/System/Unix/init_linux.cpp	2012-09-26 07:29:01.000000000 -0400
@@ -131,7 +131,7 @@
 
 #else
 #ifndef PROC_EXE_PATH
-#define PROC_EXE_PATH "/proc/self/exe"
+#define PROC_EXE_PATH "/proc/curproc/file"
 #endif
 	int size;
 	struct stat sb;
