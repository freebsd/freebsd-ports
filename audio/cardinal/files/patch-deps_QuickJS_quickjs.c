--- deps/QuickJS/quickjs.c.orig	2022-01-30 04:37:43 UTC
+++ deps/QuickJS/quickjs.c
@@ -37,6 +37,9 @@
 #elif defined(__linux__)
 #include <malloc.h>
 #endif
+#if defined(__FreeBSD__)
+#include <malloc_np.h> // for malloc_usable_size
+#endif
 
 #include "cutils.h"
 #include "list.h"
