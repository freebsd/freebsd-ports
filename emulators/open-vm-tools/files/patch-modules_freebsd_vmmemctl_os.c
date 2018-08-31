--- modules/freebsd/vmmemctl/os.c.orig	2017-07-28 21:59:15 UTC
+++ modules/freebsd/vmmemctl/os.c
@@ -37,9 +37,11 @@
 #include <sys/param.h>
 #include <sys/systm.h>
 #include <sys/kernel.h>
+#include <sys/lock.h>
 #include <sys/malloc.h>
 #include <sys/module.h>
 #include <sys/conf.h>
+#include <sys/rwlock.h>
 #include <sys/sysctl.h>
 
 #include <vm/vm.h>
@@ -83,6 +85,55 @@ typedef struct {
 MALLOC_DEFINE(M_VMMEMCTL, BALLOON_NAME, "vmmemctl metadata");
 
 /*
+ * FreeBSD version specific MACROS
+ */
+#if __FreeBSD_version >= 900000
+   #define VM_PAGE_LOCK(page) vm_page_lock(page);
+   #define VM_PAGE_UNLOCK(page) vm_page_unlock(page)
+#else
+   #define VM_PAGE_LOCK(page) vm_page_lock_queues()
+   #define VM_PAGE_UNLOCK(page) vm_page_unlock_queues()
+#endif
+
+#if __FreeBSD_version > 1000029
+   #define VM_OBJ_LOCK(object) VM_OBJECT_WLOCK(object)
+   #define VM_OBJ_UNLOCK(object) VM_OBJECT_WUNLOCK(object);
+#else
+   #define VM_OBJ_LOCK(object) VM_OBJECT_LOCK(object);
+   #define VM_OBJ_UNLOCK(object) VM_OBJECT_UNLOCK(object);
+#endif
+
+#if __FreeBSD_version < 1100015
+   #define VM_SYS_PAGES cnt.v_page_count
+#else
+   #define VM_SYS_PAGES vm_cnt.v_page_count
+#endif
+
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
+/*
  * Globals
  */
 
@@ -223,7 +274,7 @@ static __inline__ unsigned long os_ffz(unsigned long w
 unsigned long
 OS_ReservedPageGetLimit(void)
 {
-   return cnt.v_page_count;
+   return VM_SYS_PAGES;
 }
 
 
@@ -295,11 +346,7 @@ OS_ReservedPageGetHandle(PA64 pa)     // IN
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
 
@@ -357,11 +404,7 @@ void
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
 
 
@@ -369,7 +412,7 @@ static void
 os_pmap_alloc(os_pmap *p) // IN
 {
    /* number of pages (div. 8) */
-   p->size = (cnt.v_page_count + 7) / 8;
+   p->size = (VM_SYS_PAGES + 7) / 8;
 
    /*
     * expand to nearest word boundary
@@ -378,22 +421,14 @@ os_pmap_alloc(os_pmap *p) // IN
    p->size = (p->size + sizeof(unsigned long) - 1) &
                          ~(sizeof(unsigned long) - 1);
 
-#if __FreeBSD_version < 1000000
-   p->bitmap = (unsigned long *)kmem_alloc(kernel_map, p->size);
-#else
-   p->bitmap = (unsigned long *)kmem_malloc(kernel_arena, p->size, M_WAITOK | M_ZERO);
-#endif
+   p->bitmap = (unsigned long *)KMEM_ALLOC(p->size);
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
@@ -466,12 +501,14 @@ os_kmem_free(vm_page_t page) // IN
    os_state *state = &global_state;
    os_pmap *pmap = &state->pmap;
 
-   if ( !vm_page_lookup(state->vmobject, page->pindex) ) {
-      return;
+   VM_OBJ_LOCK(state->vmobject);
+   if ( vm_page_lookup(state->vmobject, page->pindex) ) {
+      os_pmap_putindex(pmap, page->pindex);
+      VM_PAGE_LOCK(page);
+      vm_page_free(page);
+      VM_PAGE_UNLOCK(page);
    }
-
-   os_pmap_putindex(pmap, page->pindex);
-   vm_page_free(page);
+   VM_OBJ_UNLOCK(state->vmobject);
 }
 
 
@@ -483,8 +520,11 @@ os_kmem_alloc(int alloc_normal_failed) // IN
    os_state *state = &global_state;
    os_pmap *pmap = &state->pmap;
 
+   VM_OBJ_LOCK(state->vmobject);
+
    pindex = os_pmap_getindex(pmap);
    if (pindex == (vm_pindex_t)-1) {
+      VM_OBJ_UNLOCK(state->vmobject);
       return NULL;
    }
 
@@ -505,6 +545,7 @@ os_kmem_alloc(int alloc_normal_failed) // IN
    if (!page) {
       os_pmap_putindex(pmap, pindex);
    }
+   VM_OBJ_UNLOCK(state->vmobject);
 
    return page;
 }
@@ -847,7 +888,7 @@ vmmemctl_sysctl(SYSCTL_HANDLER_ARGS)
 static void
 vmmemctl_init_sysctl(void)
 {
-   oid =  sysctl_add_oid(NULL, SYSCTL_STATIC_CHILDREN(_vm), OID_AUTO,
+   oid =  SYSCTL_ADD_OID(NULL, SYSCTL_STATIC_CHILDREN(_vm), OID_AUTO,
                          BALLOON_NAME, CTLTYPE_STRING | CTLFLAG_RD,
                          0, 0, vmmemctl_sysctl, "A",
                          BALLOON_NAME_VERBOSE);
