Remove explicit initialization of m->flags and m->oflags because per
default vm_phys_alloc_contig() already initializes the page as unmanaged.
Chase move of PG_UNMANAGED flag from m->flags to m->oflags and renaming
to VPO_UNMANAGED for an additional assert.

Reviewed by:	kib
See:		http://svnweb.freebsd.org/base?view=revision&revision=224746
--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2011-11-04 07:19:54.000000000 -0400
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2011-11-29 18:13:32.000000000 -0500
@@ -391,12 +391,18 @@
 
 static void rtR0MemObjFreeBSDPhysPageInit(vm_page_t pPage, vm_pindex_t iPage)
 {
+#if __FreeBSD_version <= 1000000
     pPage->wire_count = 1;
     pPage->pindex     = iPage;
     pPage->act_count  = 0;
-    pPage->oflags     = 0;
-    pPage->flags      = PG_UNMANAGED;
     atomic_add_int(&cnt.v_wire_count, 1);
+
+#if __FreeBSD_version >= 900040
+    Assert(pPage->oflags & VPO_UNMANAGED != 0);
+#else
+    Assert(pPage->flags & PG_UNMANAGED != 0);
+#endif
+#endif
 }
 
 
@@ -408,6 +414,9 @@
     int        rc = VINF_SUCCESS;
     uint32_t   cPages = cb >> PAGE_SHIFT;
     vm_paddr_t VmPhysAddrHigh;
+#if __FreeBSD_version >= 1000001
+    int        pFlags = VM_ALLOC_INTERRUPT | VM_ALLOC_NOOBJ | VM_ALLOC_WIRED;
+#endif
 
     /* create the object. */
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(RT_OFFSETOF(RTR0MEMOBJFREEBSD, u.Phys.apPages[cPages]),
@@ -424,7 +433,11 @@
 
     if (fContiguous)
     {
+#if __FreeBSD_version >= 1000001
+        vm_page_t pPage = vm_page_alloc_contig(NULL, 0, pFlags, cPages, 0, VmPhysAddrHigh, uAlignment, 0, VM_MEMATTR_DEFAULT);
+#else
         vm_page_t pPage = vm_phys_alloc_contig(cPages, 0, VmPhysAddrHigh, uAlignment, 0);
+#endif
 
         if (pPage)
             for (uint32_t iPage = 0; iPage < cPages; iPage++)
@@ -440,7 +453,11 @@
         /* Allocate page by page */
         for (uint32_t iPage = 0; iPage < cPages; iPage++)
         {
+#if __FreeBSD_version >= 1000001
+            vm_page_t pPage = vm_page_alloc_contig(NULL, iPage, pFlags, 1, 0, VmPhysAddrHigh, uAlignment, 0, VM_MEMATTR_DEFAULT);
+#else
             vm_page_t pPage = vm_phys_alloc_contig(1, 0, VmPhysAddrHigh, uAlignment, 0);
+#endif
 
             if (!pPage)
             {
