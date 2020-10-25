--- qjs.c.orig	2020-09-06 09:31:51 UTC
+++ qjs.c
@@ -36,6 +36,8 @@
 #include <malloc/malloc.h>
 #elif defined(__linux__)
 #include <malloc.h>
+#elif defined(__FreeBSD__)
+#include <malloc_np.h>
 #endif
 
 #include "cutils.h"
