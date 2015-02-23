--- include/chipmunk/chipmunk.h.orig	2015-01-13 01:54:11 UTC
+++ include/chipmunk/chipmunk.h
@@ -32,6 +32,9 @@
 #ifdef WIN32
 	// For alloca().
 	#include <malloc.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__) \
+   || defined(__NetBSD__) || defined(__OpenBSD__) \
+	/* already included in <stdlib.h> */
 #else
 	#include <alloca.h>
 #endif
