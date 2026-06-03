--- vmmemctl/os.c.orig	2026-01-22 06:30:37 UTC
+++ vmmemctl/os.c
@@ -91,8 +91,13 @@ MALLOC_DEFINE(M_VMMEMCTL, BALLOON_NAME, "vmmemctl meta
 /*
  * FreeBSD specific MACROS
  */
+#if __FreeBSD_version < 1500046
 #define VM_PAGE_LOCK(page) vm_page_lock(page);
 #define VM_PAGE_UNLOCK(page) vm_page_unlock(page)
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
@@ -322,7 +331,11 @@ OS_MapPageHandle(PageHandle handle)     // IN
 Mapping
 OS_MapPageHandle(PageHandle handle)     // IN
 {
+#if __FreeBSD_version > 1600015
+   void * res = KVA_ALLOC(PAGE_SIZE);
+#else
    vm_offset_t res = KVA_ALLOC(PAGE_SIZE);
+#endif
 
    vm_page_t page = (vm_page_t)handle;
 
@@ -379,8 +392,13 @@ OS_UnmapPage(Mapping mapping)           // IN
 void
 OS_UnmapPage(Mapping mapping)           // IN
 {
-   pmap_qremove((vm_offset_t)mapping, 1);
-   KVA_FREE((vm_offset_t)mapping, PAGE_SIZE);
+#if __FreeBSD_version > 1600015
+   pmap_qremove((void *)mapping, 1);
+   KVA_FREE((void *)mapping, PAGE_SIZE);
+#else
+   pmap_qremove(mapping, 1);
+   KVA_FREE(mapping, PAGE_SIZE);
+#endif
 }
 
 
@@ -404,7 +422,7 @@ os_pmap_free(os_pmap *p) // IN
 static void
 os_pmap_free(os_pmap *p) // IN
 {
-   KMEM_FREE((vm_offset_t)p->bitmap, p->size);
+   KMEM_FREE(p->bitmap, p->size);
    p->size = 0;
    p->bitmap = NULL;
 }
