--- libs/vkd3d-common/debug.c.orig	2023-06-28 19:40:40 UTC
+++ libs/vkd3d-common/debug.c
@@ -35,6 +35,11 @@
 #ifdef HAVE_PTHREAD_H
 #include <pthread.h>
 #endif
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <pthread_np.h>
+#elif defined(__NetBSD__)
+#include <lwp.h>
+#endif
 
 #include "vkd3d_memory.h"
 
@@ -108,6 +113,12 @@ void vkd3d_dbg_printf(enum vkd3d_dbg_level level, cons
 
 #ifdef _WIN32
     vkd3d_dbg_output("vkd3d:%04lx:%s:%s ", GetCurrentThreadId(), debug_level_names[level], function);
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+    vkd3d_dbg_output("vkd3d:%u:%s:%s ", pthread_getthreadid_np(), debug_level_names[level], function);
+#elif defined(__NetBSD__)
+    vkd3d_dbg_output("vkd3d:%u:%s:%s ", _lwp_self(), debug_level_names[level], function);
+#elif defined(__OpenBSD__)
+    vkd3d_dbg_output("vkd3d:%u:%s:%s ", getthrid(), debug_level_names[level], function);
 #elif HAVE_GETTID
     vkd3d_dbg_output("vkd3d:%u:%s:%s ", gettid(), debug_level_names[level], function);
 #else
