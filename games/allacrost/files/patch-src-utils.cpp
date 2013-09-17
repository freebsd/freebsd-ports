--- src/utils.cpp.orig	2010-05-17 03:38:35.000000000 +0400
+++ src/utils.cpp	2013-09-17 03:18:36.343226027 +0400
@@ -21,6 +21,7 @@
 #else
 	#include <dirent.h>
 	#include <sys/types.h>
+	#include <unistd.h>
 	#include <pwd.h>
 #endif
 
@@ -337,7 +338,7 @@
 	}
 
 	const char *source_char = reinterpret_cast<const char *>(source);
-	#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109)
+	#if 1
 	// We are using an iconv API that uses const char*
 	const char *sourceChar = source_char;
 	#else
@@ -369,7 +370,7 @@
 		return false;
 	}
 
-	#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109)
+	#if 1
 		// We are using an iconv API that uses const char*
 		const char *sourceChar = source;
 	#else
