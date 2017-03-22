--- modules/freebsd/vmmemctl/os.c.orig	2016-09-29 06:07:23.000000000 -0400
+++ modules/freebsd/vmmemctl/os.c	2017-02-22 12:15:23.708060000 -0500
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
@@ -223,7 +225,11 @@ static __inline__ unsigned long os_ffz(u
 unsigned long
 OS_ReservedPageGetLimit(void)
 {
+#if __FreeBSD_version < 1100015
    return cnt.v_page_count;
+#else
+   return vm_cnt.v_page_count;
+#endif
 }
 
 
@@ -369,7 +375,11 @@ static void
 os_pmap_alloc(os_pmap *p) // IN
 {
    /* number of pages (div. 8) */
+#if __FreeBSD_version < 1100015
    p->size = (cnt.v_page_count + 7) / 8;
+#else
+   p->size = (vm_cnt.v_page_count + 7) / 8;
+#endif
 
    /*
     * expand to nearest word boundary
@@ -466,12 +476,31 @@ os_kmem_free(vm_page_t page) // IN
    os_state *state = &global_state;
    os_pmap *pmap = &state->pmap;
 
-   if ( !vm_page_lookup(state->vmobject, page->pindex) ) {
-      return;
-   }
 
-   os_pmap_putindex(pmap, page->pindex);
-   vm_page_free(page);
+#if __FreeBSD_version > 1000029
+   VM_OBJECT_WLOCK(state->vmobject);
+#else
+   VM_OBJECT_LOCK(state->vmobject);
+#endif
+   if ( vm_page_lookup(state->vmobject, page->pindex) ) {
+   	os_pmap_putindex(pmap, page->pindex);
+#if __FreeBSD_version >= 900000
+	vm_page_lock(page);
+#else
+	vm_page_lock_queues();
+#endif
+   	vm_page_free(page);
+#if __FreeBSD_version >= 900000
+	vm_page_unlock(page);
+#else
+	vm_page_unlock_queues();
+#endif
+   }
+#if __FreeBSD_version > 1000029
+   VM_OBJECT_WUNLOCK(state->vmobject);
+#else
+   VM_OBJECT_UNLOCK(state->vmobject);
+#endif
 }
 
 
@@ -483,8 +512,19 @@ os_kmem_alloc(int alloc_normal_failed) /
    os_state *state = &global_state;
    os_pmap *pmap = &state->pmap;
 
+#if __FreeBSD_version > 1000029
+   VM_OBJECT_WLOCK(state->vmobject);
+#else
+   VM_OBJECT_LOCK(state->vmobject);
+#endif
+
    pindex = os_pmap_getindex(pmap);
    if (pindex == (vm_pindex_t)-1) {
+#if __FreeBSD_version > 1000029
+      VM_OBJECT_WUNLOCK(state->vmobject);
+#else
+      VM_OBJECT_UNLOCK(state->vmobject);
+#endif
       return NULL;
    }
 
@@ -505,6 +545,11 @@ os_kmem_alloc(int alloc_normal_failed) /
    if (!page) {
       os_pmap_putindex(pmap, pindex);
    }
+#if __FreeBSD_version > 1000029
+   VM_OBJECT_WUNLOCK(state->vmobject);
+#else
+   VM_OBJECT_UNLOCK(state->vmobject);
+#endif
 
    return page;
 }
@@ -847,7 +892,7 @@ vmmemctl_sysctl(SYSCTL_HANDLER_ARGS)
 static void
 vmmemctl_init_sysctl(void)
 {
-   oid =  sysctl_add_oid(NULL, SYSCTL_STATIC_CHILDREN(_vm), OID_AUTO,
+   oid =  SYSCTL_ADD_OID(NULL, SYSCTL_STATIC_CHILDREN(_vm), OID_AUTO,
                          BALLOON_NAME, CTLTYPE_STRING | CTLFLAG_RD,
                          0, 0, vmmemctl_sysctl, "A",
                          BALLOON_NAME_VERBOSE);
