--- modules/freebsd/vmmemctl/os.c.orig	2023-03-07 22:57:07 UTC
+++ modules/freebsd/vmmemctl/os.c
@@ -103,7 +103,11 @@ MALLOC_DEFINE(M_VMMEMCTL, BALLOON_NAME, "vmmemctl meta
 #define KVA_FREE(offset, size) kva_free(offset, size)
 
 #define KMEM_ALLOC(size) kmem_malloc(size, M_WAITOK | M_ZERO)
-#define KMEM_FREE(offset, size) kmem_free(offset, size)
+#if __FreeBSD_version < 1400070
+   #define KMEM_FREE(offset, size) kmem_free((vm_offset_t)offset, size)
+#else
+   #define KMEM_FREE(offset, size) kmem_free(offset, size)
+#endif
 
 /*
  * Globals
@@ -404,7 +408,7 @@ os_pmap_free(os_pmap *p) // IN
 static void
 os_pmap_free(os_pmap *p) // IN
 {
-   KMEM_FREE((vm_offset_t)p->bitmap, p->size);
+   KMEM_FREE(p->bitmap, p->size);
    p->size = 0;
    p->bitmap = NULL;
 }
