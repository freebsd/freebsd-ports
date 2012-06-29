--- modules/freebsd/vmmemctl/os.c.orig	2011-09-21 14:25:15.000000000 -0400
+++ modules/freebsd/vmmemctl/os.c	2012-06-20 09:44:40.434083000 -0400
@@ -344,12 +344,22 @@
    os_state *state = &global_state;
    os_pmap *pmap = &state->pmap;
 
-   if ( !vm_page_lookup(state->vmobject, page->pindex) ) {
-      return;
+   VM_OBJECT_LOCK(state->vmobject);
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
    }
-
-   os_pmap_putindex(pmap, page->pindex);
-   vm_page_free(page);
+   VM_OBJECT_UNLOCK(state->vmobject);
 }
 
 
@@ -361,8 +371,11 @@
    os_state *state = &global_state;
    os_pmap *pmap = &state->pmap;
 
+   VM_OBJECT_LOCK(state->vmobject);
+
    pindex = os_pmap_getindex(pmap);
    if (pindex == (vm_pindex_t)-1) {
+      VM_OBJECT_UNLOCK(state->vmobject);
       return NULL;
    }
 
@@ -383,6 +396,7 @@
    if (!page) {
       os_pmap_putindex(pmap, pindex);
    }
+   VM_OBJECT_UNLOCK(state->vmobject);
 
    return page;
 }
