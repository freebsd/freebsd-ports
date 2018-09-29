--- modules/freebsd/vmmemctl/os.c.orig	2018-09-29 03:58:10 UTC
+++ modules/freebsd/vmmemctl/os.c
@@ -109,6 +109,30 @@ MALLOC_DEFINE(M_VMMEMCTL, BALLOON_NAME, "vmmemctl meta
    #define VM_SYS_PAGES vm_cnt.v_page_count
 #endif
 
+#if __FreeBSD_version < 1000000
+   #define KVA_ALLOC(size) kmem_alloc_nofault(kernel_map, size)
+   #define KVA_FREE(offset, size) kmem_free(kernel_map, offset, size)
+#else
+   #define KVA_ALLOC(size) kva_alloc(size);
+   #define KVA_FREE(offset, size) kva_free(offset, size)
+#endif
+
+#if __FreeBSD_version < 1000000
+   #define KMEM_ALLOC(size) kmem_alloc(kernel_map, size)
+#elif  __FreeBSD_version < 1200080
+   #define KMEM_ALLOC(size) kmem_malloc(kernel_arena, size, M_WAITOK | M_ZERO)
+#else
+   #define KMEM_ALLOC(size) kmem_malloc(size, M_WAITOK | M_ZERO)
+#endif
+
+#if __FreeBSD_version < 1000000
+   #define KMEM_FREE(offset, size) kmem_free(kernel_map, offset, size)
+#elif __FreeBSD_version < 1200083
+   #define KMEM_FREE(offset, size) kmem_free(kernel_arena, offset, size)
+#else
+   #define KMEM_FREE(offset, size) kmem_free(offset, size)
+#endif
+
 /*
  * Globals
  */
@@ -322,11 +346,7 @@ OS_ReservedPageGetHandle(PA64 pa)     // IN
 Mapping
 OS_MapPageHandle(PageHandle handle)     // IN
 {
-#if __FreeBSD_version < 1000000
-   vm_offset_t res = kmem_alloc_nofault(kernel_map, PAGE_SIZE);
-#else
-   vm_offset_t res = kva_alloc(PAGE_SIZE);
-#endif
+   vm_offset_t res = KVA_ALLOC(PAGE_SIZE);
 
    vm_page_t page = (vm_page_t)handle;
 
@@ -384,11 +404,7 @@ void
 OS_UnmapPage(Mapping mapping)           // IN
 {
    pmap_qremove((vm_offset_t)mapping, 1);
-#if __FreeBSD_version < 1000000
-   kmem_free(kernel_map, (vm_offset_t)mapping, PAGE_SIZE);
-#else
-   kva_free((vm_offset_t)mapping, PAGE_SIZE);
-#endif
+   KVA_FREE((vm_offset_t)mapping, PAGE_SIZE);
 }
 
 
@@ -405,22 +421,14 @@ os_pmap_alloc(os_pmap *p) // IN
    p->size = (p->size + sizeof(unsigned long) - 1) &
                          ~(sizeof(unsigned long) - 1);
 
-#if __FreeBSD_version < 1000000
-   p->bitmap = (unsigned long *)kmem_alloc(kernel_map, p->size);
-#else
-   p->bitmap = (unsigned long *)kmem_malloc(kernel_arena, p->size, M_WAITOK | M_ZERO);
-#endif
+  p->bitmap = (unsigned long *)KMEM_ALLOC(p->size);
 }
 
 
 static void
 os_pmap_free(os_pmap *p) // IN
 {
-#if __FreeBSD_version < 1000000
-   kmem_free(kernel_map, (vm_offset_t)p->bitmap, p->size);
-#else
-   kmem_free(kernel_arena, (vm_offset_t)p->bitmap, p->size);
-#endif
+   KMEM_FREE((vm_offset_t)p->bitmap, p->size);
    p->size = 0;
    p->bitmap = NULL;
 }
