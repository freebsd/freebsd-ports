--- sope-core/EOControl/EOObserver.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOObserver.m
@@ -21,6 +21,10 @@
 
 #include "EOObserver.h"
 #include "common.h"
+#ifdef __GNUSTEP_RUNTIME__
+#define objc_malloc(x) malloc(x)
+#define objc_free(x) free(x)
+#endif
 
 // THREAD, MT
 
