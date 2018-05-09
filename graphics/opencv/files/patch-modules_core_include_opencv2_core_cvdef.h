--- modules/core/include/opencv2/core/cvdef.h.orig	2018-02-23 08:38:33 UTC
+++ modules/core/include/opencv2/core/cvdef.h
@@ -452,6 +452,7 @@ Cv64suf;
 #  endif
 #endif
 
+#if defined __cplusplus
 
 // Integer types portatibility
 #ifdef OPENCV_STDINT_HEADER
@@ -493,6 +494,9 @@ typedef ::int64_t int64_t;
 typedef ::uint64_t uint64_t;
 }
 #endif
+#endif
+#else
+#include <stdint.h>
 #endif
 
 
