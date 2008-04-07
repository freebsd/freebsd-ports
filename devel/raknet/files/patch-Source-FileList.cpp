--- Source/FileList.cpp.orig	2008-03-17 07:58:04.000000000 +0100
+++ Source/FileList.cpp	2008-03-27 09:40:00.000000000 +0100
@@ -2,7 +2,7 @@
 #include <assert.h>
 #if defined(_WIN32) || defined(__CYGWIN__)
 	#include <io.h>
-#elif !defined ( __APPLE__ ) && !defined ( __APPLE_CC__ ) && !defined ( __PPC__ )
+#elif !defined ( __APPLE__ ) && !defined ( __APPLE_CC__ ) && !defined ( __PPC__ ) && !defined ( __FreeBSD__ )
 	#include <sys/io.h>
 #endif
 #include <stdio.h>
@@ -26,7 +26,9 @@
 #elif defined(_WIN32)
 #include <malloc.h>
 #else
+#if !defined ( __FreeBSD__ )
 #include <alloca.h>
+#endif
 #include <unistd.h>
 #include <stdlib.h>
 #include <sys/stat.h>
