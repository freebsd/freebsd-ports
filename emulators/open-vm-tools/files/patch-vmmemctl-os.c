--- modules/freebsd/vmmemctl/os.c.orig	2011-09-21 20:25:15.000000000 +0200
+++ modules/freebsd/vmmemctl/os.c	2013-10-19 11:01:27.000000000 +0200
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
@@ -264,14 +266,23 @@
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
+   kmem_free(kernel_arena, (vm_offset_t)p->bitmap, p->size);
+#else
    kmem_free(kernel_map, (vm_offset_t)p->bitmap, p->size);
+#endif
    p->size = 0;
    p->bitmap = NULL;
 }
@@ -344,12 +355,31 @@
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
 
 
@@ -361,8 +391,19 @@
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
 
@@ -383,6 +424,11 @@
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
