--- libs/vkd3d/vkd3d_private.h.orig	2018-10-01 14:41:12 UTC
+++ libs/vkd3d/vkd3d_private.h
@@ -37,6 +37,10 @@
 #include <pthread.h>
 #include <stdbool.h>
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#include <pthread_np.h>
+#endif
+
 #define VK_CALL(f) (vk_procs->f)
 
 #define VKD3D_DESCRIPTOR_MAGIC_FREE    0x00000000u
@@ -894,6 +898,10 @@ static inline void vkd3d_set_thread_name(const char *n
     pthread_setname_np(pthread_self(), name);
 #elif defined(HAVE_PTHREAD_SETNAME_NP_1)
     pthread_setname_np(name);
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+    pthread_set_name_np(pthread_self(), name);
+#elif defined(__NetBSD__) /* XXX Convert to HAVE_PTHREAD_SETNAME_NP_3 */
+    pthread_setname_np(pthread_self(), "%s", (void*)name);
 #endif
 }
 
