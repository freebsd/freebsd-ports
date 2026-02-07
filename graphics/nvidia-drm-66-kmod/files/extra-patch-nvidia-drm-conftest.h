--- nvidia-drm-conftest.h.orig	2024-02-22 01:03:15 UTC
+++ nvidia-drm-conftest.h
@@ -85,7 +85,11 @@
 
 /* For nv_drm_gem_prime_force_fence_signal */
 #ifndef spin_is_locked
+#if ((__FreeBSD_version >= 1500000) && (__FreeBSD_version < 1500018)) || (__FreeBSD_version < 1401501)
 #define spin_is_locked(lock) mtx_owned(lock.m)
+#else
+#define spin_is_locked(lock) mtx_owned(lock)
+#endif
 #endif
 
 #ifndef rwsem_is_locked
