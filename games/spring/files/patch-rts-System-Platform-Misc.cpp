--- rts/System/Platform/Misc.cpp.orig	2012-02-12 22:27:27.502768102 +0400
+++ rts/System/Platform/Misc.cpp	2012-02-13 01:50:43.365521912 +0400
@@ -2,7 +2,7 @@
 
 #include "Misc.h"
 
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <dlfcn.h> // for dladdr(), dlopen()
 
@@ -187,7 +187,7 @@
 		procExeFilePath = GetRealPath(path);
 	}
 #else
-	#error implement this
+	return "%%PREFIX%%/bin/spring";
 #endif
 
 	if (procExeFilePath.empty()) {
@@ -208,7 +208,7 @@
 	// this will only be used if moduleFilePath stays empty
 	const char* error = NULL;
 
-#if defined(linux) || defined(__APPLE__)
+#if defined(linux) || defined(__APPLE__) || defined(__FreeBSD__)
 #ifdef __APPLE__
 	#define SHARED_LIBRARY_EXTENSION "dylib"
 #else
