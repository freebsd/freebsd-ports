--- modules/freebsd/vmmemctl/os.c.orig	2022-09-13 12:55:59 UTC
+++ modules/freebsd/vmmemctl/os.c
@@ -136,9 +136,11 @@ MALLOC_DEFINE(M_VMMEMCTL, BALLOON_NAME, "vmmemctl meta
 #endif
 
 #if __FreeBSD_version < 1000000
-   #define KMEM_FREE(offset, size) kmem_free(kernel_map, offset, size)
+   #define KMEM_FREE(offset, size) kmem_free(kernel_map, (vm_offset_t)offset, size)
 #elif __FreeBSD_version < 1200083
-   #define KMEM_FREE(offset, size) kmem_free(kernel_arena, offset, size)
+   #define KMEM_FREE(offset, size) kmem_free(kernel_arena, (vm_offset_t)offset, size)
+#elif __FreeBSD_version < 1400070
+   #define KMEM_FREE(offset, size) kmem_free((vm_offset_t)offset, size)
 #else
    #define KMEM_FREE(offset, size) kmem_free(offset, size)
 #endif
@@ -442,7 +444,7 @@ os_pmap_free(os_pmap *p) // IN
 static void
 os_pmap_free(os_pmap *p) // IN
 {
-   KMEM_FREE((vm_offset_t)p->bitmap, p->size);
+   KMEM_FREE(p->bitmap, p->size);
    p->size = 0;
    p->bitmap = NULL;
 }
