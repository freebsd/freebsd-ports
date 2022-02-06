--- deps/QuickJS/qjs.c.orig	2022-01-30 05:00:00 UTC
+++ deps/QuickJS/qjs.c
@@ -37,6 +37,9 @@
 #elif defined(__linux__)
 #include <malloc.h>
 #endif
+#if defined(__FreeBSD__)
+#include <malloc_np.h> // for malloc_usable_size
+#endif
 
 #include "cutils.h"
 #include "quickjs-libc.h"
