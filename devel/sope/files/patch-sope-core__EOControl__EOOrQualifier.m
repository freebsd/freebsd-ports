--- sope-core/EOControl/EOOrQualifier.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOOrQualifier.m
@@ -22,6 +22,12 @@
 #include <EOControl/EOQualifier.h>
 #include "common.h"
 
+#ifdef __GNUSTEP_RUNTIME__
+#define objc_calloc(x,y) calloc(x,y)
+#define objc_free(x) free(x)
+#endif
+
+
 @interface EOQualifier(EvalContext)
 - (BOOL)evaluateWithObject:(id)_object inEvalContext:(id)_ctx;
 @end
