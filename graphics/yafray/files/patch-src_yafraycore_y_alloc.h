--- src/yafraycore/y_alloc.h.orig	Thu Jul 13 12:35:02 2006
+++ src/yafraycore/y_alloc.h	Tue Oct 17 14:55:47 2006
@@ -5,7 +5,7 @@
 #include<config.h>
 #endif
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined (__FreeBSD__)
 #include <stdlib.h>
 #else
 #include <malloc.h>
@@ -13,6 +13,10 @@
 #include <vector>
 #include <algorithm>
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
+
 __BEGIN_YAFRAY
 
 typedef unsigned int u_int32;
@@ -26,6 +30,16 @@
 	// however, malloc is supposed to return at least SSE2 compatible alignment, which has to be enough.
 	// alternative would be valloc, but i have no good info on its effects.
 	return malloc(size);
+#elif defined(__FreeBSD__)
+#if (__FreeBSD_version < 700014)
+	return malloc(size);
+#else
+	void *ret;
+	if (posix_memalign(&ret, bound, size) != 0)
+		return (NULL);
+	else
+		return (ret);
+#endif
 #else 
 	return memalign(bound, size);
 #endif
