--- thirdparty/quickjs/quickjs-2019-07-09-dust3d/quickjs.c.orig	2020-04-12 10:44:20 UTC
+++ thirdparty/quickjs/quickjs-2019-07-09-dust3d/quickjs.c
@@ -36,6 +36,8 @@
 #include <malloc/malloc.h>
 #elif defined(__linux__)
 #include <malloc.h>
+#elif defined(__FreeBSD__)
+#include <malloc_np.h>
 #endif
 
 #include "cutils.h"
