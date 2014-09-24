--- kqemu-freebsd.c~	2014-02-07 20:00:33.656255395 +0200
+++ kqemu-freebsd.c	2014-02-08 08:43:19.209100708 +0200
@@ -105,17 +105,29 @@
  */
 struct kqemu_page *CDECL kqemu_alloc_zeroed_page(unsigned long *ppage_index)
 {
+#if __FreeBSD_version < 1000030
     pmap_t pmap;
+#endif
     vm_offset_t va;
     vm_paddr_t pa;
 
+#if __FreeBSD_version >= 1000030
+    va = kmem_malloc(kernel_arena, PAGE_SIZE, M_ZERO | M_WAITOK);
+#else
     va = kmem_alloc(kernel_map, PAGE_SIZE);
+#endif
+
     if (va == 0) {
 	kqemu_log("kqemu_alloc_zeroed_page: NULL\n");
 	return NULL;
     }
+
+#if __FreeBSD_version >= 1000030
+    pa = vtophys(va);
+#else
     pmap = vm_map_pmap(kernel_map);
     pa = pmap_extract(pmap, va);
+#endif
     /* kqemu_log("kqemu_alloc_zeroed_page: %08x\n", pa); */
     *ppage_index = pa >> PAGE_SHIFT;
     return (struct kqemu_page *)va;
@@ -125,7 +137,11 @@
 {
     if (kqemu_debug > 0)
     	kqemu_log("kqemu_free_page(%p)\n", page);
+#if __FreeBSD_version >= 1000030
+    kmem_free(kernel_arena, (vm_offset_t) page, PAGE_SIZE);
+#else
     kmem_free(kernel_map, (vm_offset_t) page, PAGE_SIZE);
+#endif
 }
 
 /* return kernel address of the physical page page_index */
