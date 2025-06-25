--- vmmemctl/os.c.orig	2025-05-15 19:16:07 UTC
+++ vmmemctl/os.c
@@ -91,8 +91,13 @@ MALLOC_DEFINE(M_VMMEMCTL, BALLOON_NAME, "vmmemctl meta
 /*
  * FreeBSD specific MACROS
  */
-#define VM_PAGE_LOCK(page) vm_page_lock(page);
-#define VM_PAGE_UNLOCK(page) vm_page_unlock(page)
+#if __FreeBSD_version < 1500046
+#define VM_PAGE_LOCK(page) vm_page_tryxbusy(page);
+#define VM_PAGE_UNLOCK(page) vm_page_xunbusy(page)
+#else
+#define VM_PAGE_LOCK(page) vm_page_tryxbusy(page);
+#define VM_PAGE_UNLOCK(page) vm_page_xunbusy(page)
+#endif
 
 #define VM_OBJ_LOCK(object) VM_OBJECT_WLOCK(object)
 #define VM_OBJ_UNLOCK(object) VM_OBJECT_WUNLOCK(object);
@@ -103,7 +108,11 @@ MALLOC_DEFINE(M_VMMEMCTL, BALLOON_NAME, "vmmemctl meta
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
@@ -404,7 +413,7 @@ os_pmap_free(os_pmap *p) // IN
 static void
 os_pmap_free(os_pmap *p) // IN
 {
-   KMEM_FREE((vm_offset_t)p->bitmap, p->size);
+   KMEM_FREE(p->bitmap, p->size);
    p->size = 0;
    p->bitmap = NULL;
 }
