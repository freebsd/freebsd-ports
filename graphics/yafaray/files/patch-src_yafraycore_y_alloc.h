--- src/yafraycore/y_alloc.h.orig	Thu Jul 13 12:35:02 2006
+++ src/yafraycore/y_alloc.h	Tue Sep 19 03:33:32 2006
@@ -5,7 +5,7 @@
 #include<config.h>
 #endif
 
-#ifdef __APPLE__
+#ifdef __FreeBSD__
 #include <stdlib.h>
 #else
 #include <malloc.h>
@@ -26,6 +26,12 @@
 	// however, malloc is supposed to return at least SSE2 compatible alignment, which has to be enough.
 	// alternative would be valloc, but i have no good info on its effects.
 	return malloc(size);
+#elif defined(__FreeBSD__)
+	void *ret;
+	if (posix_memalign(&ret, bound, size) != 0)
+		return (NULL);
+	else
+		return (ret);
 #else 
 	return memalign(bound, size);
 #endif
