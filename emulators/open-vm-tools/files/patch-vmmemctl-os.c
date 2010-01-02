--- modules/freebsd/vmmemctl/os.c.orig	2009-04-09 15:18:08.000000000 -0400
+++ modules/freebsd/vmmemctl/os.c	2009-04-09 15:34:06.000000000 -0400
@@ -413,12 +413,14 @@
    os_state *state = &global_state;
    os_pmap *pmap = &state->pmap;
 
-   if ( !vm_page_lookup(state->vmobject, page->pindex) ) {
-      return;
+   VM_OBJECT_LOCK(state->vmobject);
+   if ( vm_page_lookup(state->vmobject, page->pindex) ) {
+   	os_pmap_putindex(pmap, page->pindex);
+	vm_page_lock_queues();
+   	vm_page_free(page);
+	vm_page_unlock_queues();
    }
-
-   os_pmap_putindex(pmap, page->pindex);
-   vm_page_free(page);
+   VM_OBJECT_UNLOCK(state->vmobject);
 }
 
 static vm_page_t os_kmem_alloc(int alloc_normal_failed)
@@ -430,8 +432,11 @@
    os_state *state = &global_state;
    os_pmap *pmap = &state->pmap;
 
+   VM_OBJECT_LOCK(state->vmobject);
+
    pindex = os_pmap_getindex(pmap);
    if (pindex == (vm_pindex_t)-1) {
+      VM_OBJECT_UNLOCK(state->vmobject);
       return NULL;
    }
 
@@ -452,6 +457,7 @@
    if (!page) {
       os_pmap_putindex(pmap, pindex);
    }
+   VM_OBJECT_UNLOCK(state->vmobject);
 
    return page;
 }
