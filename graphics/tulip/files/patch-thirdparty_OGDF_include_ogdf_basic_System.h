--- thirdparty/OGDF/include/ogdf/basic/System.h.orig	2025-03-31 21:30:23 UTC
+++ thirdparty/OGDF/include/ogdf/basic/System.h
@@ -34,7 +34,7 @@
 
 #include <ogdf/basic/basic.h>
 
-#if defined(OGDF_SYSTEM_OSX)
+#if defined(OGDF_SYSTEM_OSX) || defined(__FreeBSD__)
 #	include <stdlib.h>
 #elif defined(OGDF_SYSTEM_UNIX) || defined(__MINGW32__)
 #	include <malloc.h>
@@ -133,7 +133,7 @@ class OGDF_EXPORT System { (public)
 #	else
 		return _aligned_malloc(size, 16);
 #	endif
-#elif defined(OGDF_SYSTEM_OSX)
+#elif defined(OGDF_SYSTEM_OSX) || defined(__FreeBSD__)
 		// malloc returns 16 byte aligned memory on OS X.
 		return malloc(size);
 #else
