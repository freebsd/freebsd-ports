libs/vkd3d/device.c:2615:27: error: initializing 'struct vkd3d_mutex' with an expression of incompatible type 'void *'
 2615 | static struct vkd3d_mutex cache_list_mutex = VKD3D_MUTEX_INITIALIZER;
      |                           ^                  ~~~~~~~~~~~~~~~~~~~~~~~

--- include/private/vkd3d_common.h.orig	2024-04-24 21:49:15 UTC
+++ include/private/vkd3d_common.h
@@ -506,7 +506,7 @@ struct vkd3d_mutex
 #ifdef _WIN32
 #define VKD3D_MUTEX_INITIALIZER {{NULL, -1, 0, 0, 0, 0}}
 #else
-#define VKD3D_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
+#define VKD3D_MUTEX_INITIALIZER {{{0}}}
 #endif
 
 static inline void vkd3d_mutex_init(struct vkd3d_mutex *lock)
