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
@@ -83,6 +85,30 @@ typedef struct {
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
+/*
  * Globals
  */
 
@@ -223,7 +249,7 @@ static __inline__ unsigned long os_ffz(unsigned long w
 unsigned long
 OS_ReservedPageGetLimit(void)
 {
-   return cnt.v_page_count;
+   return VM_SYS_PAGES;
 }
 
 
@@ -369,7 +395,7 @@ static void
 os_pmap_alloc(os_pmap *p) // IN
 {
    /* number of pages (div. 8) */
-   p->size = (cnt.v_page_count + 7) / 8;
+   p->size = (VM_SYS_PAGES + 7) / 8;
 
    /*
     * expand to nearest word boundary
@@ -466,12 +492,14 @@ os_kmem_free(vm_page_t page) // IN
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
 
 
@@ -483,8 +511,11 @@ os_kmem_alloc(int alloc_normal_failed) // IN
    os_state *state = &global_state;
    os_pmap *pmap = &state->pmap;
 
+   VM_OBJ_LOCK(state->vmobject);
+
    pindex = os_pmap_getindex(pmap);
    if (pindex == (vm_pindex_t)-1) {
+      VM_OBJ_UNLOCK(state->vmobject);
       return NULL;
    }
 
@@ -505,6 +536,7 @@ os_kmem_alloc(int alloc_normal_failed) // IN
    if (!page) {
       os_pmap_putindex(pmap, pindex);
    }
+   VM_OBJ_UNLOCK(state->vmobject);
 
    return page;
 }
@@ -847,7 +879,7 @@ vmmemctl_sysctl(SYSCTL_HANDLER_ARGS)
 static void
 vmmemctl_init_sysctl(void)
 {
-   oid =  sysctl_add_oid(NULL, SYSCTL_STATIC_CHILDREN(_vm), OID_AUTO,
+   oid =  SYSCTL_ADD_OID(NULL, SYSCTL_STATIC_CHILDREN(_vm), OID_AUTO,
                          BALLOON_NAME, CTLTYPE_STRING | CTLFLAG_RD,
                          0, 0, vmmemctl_sysctl, "A",
                          BALLOON_NAME_VERBOSE);
