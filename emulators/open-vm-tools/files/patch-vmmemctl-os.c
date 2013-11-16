--- modules/freebsd/vmmemctl/os.c.orig	2013-09-23 15:51:10.000000000 +0000
+++ modules/freebsd/vmmemctl/os.c	2013-11-16 19:55:06.152925027 +0000
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
@@ -295,7 +297,13 @@
 Mapping
 OS_MapPageHandle(PageHandle handle)     // IN
 {
+
+#if __FreeBSD_version >= 1000042
+   vm_offset_t res = kva_alloc(PAGE_SIZE);
+#else
    vm_offset_t res = kmem_alloc_nofault(kernel_map, PAGE_SIZE);
+#endif
+
    vm_page_t page = (vm_page_t)handle;
 
    if (!res) {
@@ -352,7 +360,11 @@
 OS_UnmapPage(Mapping mapping)           // IN
 {
    pmap_qremove((vm_offset_t)mapping, 1);
+#if __FreeBSD_version >= 1000042
+   kva_free((vm_offset_t)mapping, PAGE_SIZE);
+#else
    kmem_free(kernel_map, (vm_offset_t)mapping, PAGE_SIZE);
+#endif
 }
 
 
@@ -369,14 +381,23 @@
    p->size = (p->size + sizeof(unsigned long) - 1) & 
                          ~(sizeof(unsigned long) - 1);
 
+#if __FreeBSD_version >= 1000042
+   p->bitmap = (unsigned long *)kmem_malloc(kernel_arena, p->size,
+                         M_WAITOK | M_ZERO);
+#else
    p->bitmap = (unsigned long *)kmem_alloc(kernel_map, p->size);
+#endif
 }
 
 
 static void
 os_pmap_free(os_pmap *p) // IN
 {
+#if __FreeBSD_version >= 1000042
+   kva_free((vm_offset_t)p->bitmap, p->size);
+#else
    kmem_free(kernel_map, (vm_offset_t)p->bitmap, p->size);
+#endif
    p->size = 0;
    p->bitmap = NULL;
 }
@@ -449,12 +470,31 @@
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
 
 
@@ -466,8 +506,19 @@
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
 
@@ -488,6 +539,11 @@
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
