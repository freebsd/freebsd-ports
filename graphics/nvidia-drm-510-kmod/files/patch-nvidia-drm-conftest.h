--- nvidia-drm-conftest.h.orig	2024-03-11 17:52:16 UTC
+++ nvidia-drm-conftest.h
@@ -122,11 +122,9 @@
  */
 #define drm_atomic_state_free drm_atomic_state_put
 
-#if __FreeBSD_version < 1300000
 /* redefine LIST_HEAD_INIT to the linux version */
 #include <linux/list.h>
 #define LIST_HEAD_INIT(name) LINUX_LIST_HEAD_INIT(name)
-#endif
 
 /*
  * FreeBSD currently has only vmf_insert_pfn_prot defined, and it has a
