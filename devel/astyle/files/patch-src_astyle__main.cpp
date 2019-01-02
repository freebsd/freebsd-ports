--- ../../src/astyle_main.cpp.orig	2018-11-28 00:32:16.924868000 +0100
+++ ../../src/astyle_main.cpp	2018-11-28 00:33:36.071105000 +0100
@@ -46,6 +46,10 @@
 #ifdef _WIN32
 	#undef UNICODE		// use ASCII windows functions
 	#include <windows.h>
+#elif defined(__FreeBSD__)
+	#include <dirent.h>
+	#include <sys/syslimits.h>
+	#include <unistd.h>
 #else
 	#include <dirent.h>
 	#include <unistd.h>
