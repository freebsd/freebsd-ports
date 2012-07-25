--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2012-06-20 15:18:10.000000000 +0200
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2012-07-25 18:04:01.534886951 +0200
@@ -5,6 +5,7 @@
 
 /*
  * Copyright (c) 2007 knut st. osmundsen <bird-src-spam@anduin.net>
+ * Copyright (c) 2011 Andriy Gapon <avg@FreeBSD.org>
  *
  * Permission is hereby granted, free of charge, to any person
  * obtaining a copy of this software and associated documentation
@@ -54,23 +55,8 @@
     /** The core structure. */
     RTR0MEMOBJINTERNAL  Core;
     /** Type dependent data */
-    union
-    {
-        /** Non physical memory allocations */
-        struct
-        {
-            /** The VM object associated with the allocation. */
-            vm_object_t         pObject;
-        } NonPhys;
-        /** Physical memory allocations */
-        struct
-        {
-            /** Number of pages */
-            uint32_t            cPages;
-            /** Array of pages - variable */
-            vm_page_t           apPages[1];
-        } Phys;
-    } u;
+    /** The VM object associated with the allocation. */
+    vm_object_t         pObject;
 } RTR0MEMOBJFREEBSD, *PRTR0MEMOBJFREEBSD;
 
 
@@ -125,25 +111,14 @@
 
     switch (pMemFreeBSD->Core.enmType)
     {
-        case RTR0MEMOBJTYPE_CONT:
-            contigfree(pMemFreeBSD->Core.pv, pMemFreeBSD->Core.cb, M_IPRTMOBJ);
-            break;
-
         case RTR0MEMOBJTYPE_PAGE:
+        case RTR0MEMOBJTYPE_LOW:
+        case RTR0MEMOBJTYPE_CONT:
         {
             rc = vm_map_remove(kernel_map,
                                 (vm_offset_t)pMemFreeBSD->Core.pv,
                                 (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb);
             AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
-
-            vm_page_lock_queues();
-            for (uint32_t iPage = 0; iPage < pMemFreeBSD->u.Phys.cPages; iPage++)
-            {
-                vm_page_t pPage = pMemFreeBSD->u.Phys.apPages[iPage];
-                vm_page_unwire(pPage, 0);
-                vm_page_free(pPage);
-            }
-            vm_page_unlock_queues();
             break;
         }
 
@@ -165,8 +140,8 @@
         case RTR0MEMOBJTYPE_RES_VIRT:
         {
             vm_map_t pMap = kernel_map;
-            if (pMemFreeBSD->Core.u.Lock.R0Process != NIL_RTR0PROCESS)
-                pMap = &((struct proc *)pMemFreeBSD->Core.u.Lock.R0Process)->p_vmspace->vm_map;
+            if (pMemFreeBSD->Core.u.ResVirt.R0Process != NIL_RTR0PROCESS)
+                pMap = &((struct proc *)pMemFreeBSD->Core.u.ResVirt.R0Process)->p_vmspace->vm_map;
             rc = vm_map_remove(pMap,
                                (vm_offset_t)pMemFreeBSD->Core.pv,
                                (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb);
@@ -180,7 +155,6 @@
 
             if (pMemFreeBSD->Core.u.Mapping.R0Process != NIL_RTR0PROCESS)
                 pMap = &((struct proc *)pMemFreeBSD->Core.u.Mapping.R0Process)->p_vmspace->vm_map;
-
             rc = vm_map_remove(pMap,
                                (vm_offset_t)pMemFreeBSD->Core.pv,
                                (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb);
@@ -191,26 +165,21 @@
         case RTR0MEMOBJTYPE_PHYS:
         case RTR0MEMOBJTYPE_PHYS_NC:
         {
+            VM_OBJECT_LOCK(pMemFreeBSD->pObject);
+            vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
             vm_page_lock_queues();
-            for (uint32_t iPage = 0; iPage < pMemFreeBSD->u.Phys.cPages; iPage++)
+            for (vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
+                 pPage != NULL;
+                 pPage = vm_page_next(pPage))
             {
-                vm_page_t pPage = pMemFreeBSD->u.Phys.apPages[iPage];
                 vm_page_unwire(pPage, 0);
-                vm_page_free(pPage);
             }
             vm_page_unlock_queues();
+            VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
+            vm_object_deallocate(pMemFreeBSD->pObject);
             break;
         }
 
-#ifdef USE_KMEM_ALLOC_ATTR
-        case RTR0MEMOBJTYPE_LOW:
-        {
-            kmem_free(kernel_map, (vm_offset_t)pMemFreeBSD->Core.pv, pMemFreeBSD->Core.cb);
-            break;
-        }
-#else
-        case RTR0MEMOBJTYPE_LOW: /* unused */
-#endif
         default:
             AssertMsgFailed(("enmType=%d\n", pMemFreeBSD->Core.enmType));
             return VERR_INTERNAL_ERROR;
@@ -220,183 +189,183 @@
 }
 
 
-DECLHIDDEN(int) rtR0MemObjNativeAllocPage(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable)
-{
-    int rc;
-    size_t cPages = cb >> PAGE_SHIFT;
-
-    /* create the object. */
-    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(RT_OFFSETOF(RTR0MEMOBJFREEBSD, u.Phys.apPages[cPages]),
-                                                                       RTR0MEMOBJTYPE_PAGE, NULL, cb);
-    if (!pMemFreeBSD)
-        return VERR_NO_MEMORY;
-
-    pMemFreeBSD->u.Phys.cPages = cPages;
+static vm_page_t FreeBSDContigPhysAllocHelper(vm_object_t pObject, vm_pindex_t iPIndex,
+                                              u_long cPages, vm_paddr_t VmPhysAddrHigh,
+                                              u_long uAlignment, bool fWire)
+{
+    vm_page_t pPages;
+    int tries = 0;
+#if __FreeBSD_version > 1000000
+    int flags = VM_ALLOC_INTERRUPT | VM_ALLOC_NOBUSY;
+
+    if (fWire)
+        flags |= VM_ALLOC_WIRED;
+    while (1)
+    {
+        VM_OBJECT_LOCK(pObject);
+        pPages = vm_page_alloc_contig(pObject, iPIndex, flags, cPages, 0, VmPhysAddrHigh, uAlignment, 0, VM_MEMATTR_DEFAULT);
+        VM_OBJECT_UNLOCK(pObject);
+        if (pPages || tries >= 1)
+            break;
+        vm_pageout_grow_cache(tries, 0, VmPhysAddrHigh);
+        tries++;
+    }
+    return pPages;
+#else
 
-    vm_offset_t MapAddress = vm_map_min(kernel_map);
-    rc = vm_map_find(kernel_map,                /* map */
-                     NULL,                      /* object */
-                     0,                         /* offset */
-                     &MapAddress,               /* addr (IN/OUT) */
-                     cb,                        /* length */
-                     TRUE,                      /* find_space */
-                     fExecutable                /* protection */
-                     ? VM_PROT_ALL
-                     : VM_PROT_RW,
-                     VM_PROT_ALL,               /* max(_prot) */
-                     0);                        /* cow (copy-on-write) */
-    if (rc == KERN_SUCCESS)
+    while (1)
     {
-        rc = VINF_SUCCESS;
-
-        for (size_t iPage = 0; iPage < cPages; iPage++)
+        pPages = vm_phys_alloc_contig(cPages, 0, VmPhysAddrHigh, uAlignment, 0);
+        if (pPages || tries >= 1)
+            break;
+        vm_contig_grow_cache(tries, 0, VmPhysAddrHigh);
+        tries++;
+    }
+    if (!pPages)
+        return pPages;
+    VM_OBJECT_LOCK(pObject);
+    for (vm_pindex_t iPage = 0; iPage < cPages; iPage++)
+    {
+        vm_page_t pPage = pPages + iPage;
+        vm_page_insert(pPage, pObject, iPIndex + iPage);
+        pPage->valid = VM_PAGE_BITS_ALL;
+        if (fWire)
         {
-            vm_page_t   pPage;
+            pPage->wire_count = 1;
+            atomic_add_int(&cnt.v_wire_count, 1);
+        }
+    }
+    VM_OBJECT_UNLOCK(pObject);
+    return pPages;
+#endif
+}
 
-            pPage = vm_page_alloc(NULL, iPage,
-                                  VM_ALLOC_SYSTEM |
-                                  VM_ALLOC_WIRED | VM_ALLOC_NOOBJ);
+static int FreeBSDPhysAllocHelper(vm_object_t pObject, u_long cPages,
+                                  vm_paddr_t VmPhysAddrHigh, u_long uAlignment,
+                                  bool fContiguous, bool fWire)
+{
+    if (fContiguous)
+    {
+        if (FreeBSDContigPhysAllocHelper(pObject, 0, cPages, VmPhysAddrHigh, uAlignment, fWire) != NULL)
+            return VINF_SUCCESS;
+        else
+            return VERR_NO_MEMORY;
+    }
 
-            if (!pPage)
+    for (vm_pindex_t iPage = 0; iPage < cPages; iPage++)
+    {
+        vm_page_t pPage = FreeBSDContigPhysAllocHelper(pObject, iPage, 1, VmPhysAddrHigh, uAlignment, fWire);
+        if (!pPage)
+        {
+            /* Free all allocated pages */
+            VM_OBJECT_LOCK(pObject);
+            while (iPage-- > 0)
             {
-                /*
-                    * Out of pages
-                    * Remove already allocated pages
-                    */
-                while (iPage-- > 0)
-                {
-                    pPage = pMemFreeBSD->u.Phys.apPages[iPage];
-                    vm_page_lock_queues();
+                pPage = vm_page_lookup(pObject, iPage);
+                vm_page_lock_queues();
+                if (fWire)
                     vm_page_unwire(pPage, 0);
-                    vm_page_free(pPage);
-                    vm_page_unlock_queues();
-                }
-                rc = VERR_NO_MEMORY;
-                break;
+                vm_page_free(pPage);
+                vm_page_unlock_queues();
             }
-
-            pPage->valid = VM_PAGE_BITS_ALL;
-            pMemFreeBSD->u.Phys.apPages[iPage] = pPage;
+            VM_OBJECT_UNLOCK(pObject);
+            return VERR_NO_MEMORY;
         }
+    }
+    return VINF_SUCCESS;
+}
 
-        if (rc == VINF_SUCCESS)
-        {
-            vm_offset_t AddressDst = MapAddress;
+static int FreeBSDAllocHelper(PRTR0MEMOBJFREEBSD pMemFreeBSD, bool fExecutable,
+                              vm_paddr_t VmPhysAddrHigh, bool fContiguous)
+{
+    int rc;
+    size_t cPages = atop(pMemFreeBSD->Core.cb);
 
-            for (size_t iPage = 0; iPage < cPages; iPage++)
-            {
-                vm_page_t pPage = pMemFreeBSD->u.Phys.apPages[iPage];
+    pMemFreeBSD->pObject = vm_object_allocate(OBJT_PHYS, cPages);
+    vm_offset_t MapAddress = vm_map_min(kernel_map);
 
-                MY_PMAP_ENTER(kernel_map->pmap, AddressDst, pPage,
-                              fExecutable
-                              ? VM_PROT_ALL
-                              : VM_PROT_RW,
-                              TRUE);
+    // no additional object reference for auto-deallocation upon unmapping
+    rc = vm_map_find(kernel_map, pMemFreeBSD->pObject, 0,
+                     &MapAddress, pMemFreeBSD->Core.cb, VMFS_ANY_SPACE,
+                     fExecutable ? VM_PROT_ALL : VM_PROT_RW, VM_PROT_ALL, 0);
 
-                AddressDst += PAGE_SIZE;
-            }
+    if (rc == KERN_SUCCESS)
+    {
+        rc = FreeBSDPhysAllocHelper(pMemFreeBSD->pObject, cPages, VmPhysAddrHigh, PAGE_SIZE, fContiguous, false);
+        if (RT_SUCCESS(rc))
+        {
+            vm_map_wire(kernel_map, MapAddress, MapAddress + pMemFreeBSD->Core.cb, VM_MAP_WIRE_SYSTEM|VM_MAP_WIRE_NOHOLES);
 
             /* Store start address */
             pMemFreeBSD->Core.pv = (void *)MapAddress;
-            *ppMem = &pMemFreeBSD->Core;
             return VINF_SUCCESS;
         }
-    }
-    rc = VERR_NO_MEMORY; /** @todo fix translation (borrow from darwin) */
 
-    rtR0MemObjDelete(&pMemFreeBSD->Core);
+        vm_map_remove(kernel_map, MapAddress, MapAddress + pMemFreeBSD->Core.cb);
+    }
+    else
+    {
+        rc = VERR_NO_MEMORY; /** @todo fix translation (borrow from darwin) */
+        vm_object_deallocate(pMemFreeBSD->pObject);
+    }
     return rc;
 }
 
-
-DECLHIDDEN(int) rtR0MemObjNativeAllocLow(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable)
+DECLHIDDEN(int) rtR0MemObjNativeAllocPage(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable)
 {
-#ifdef USE_KMEM_ALLOC_ATTR
-    /*
-     * Use kmem_alloc_attr, fExectuable is not needed because the
-     * memory will be executable by default
-     */
-    NOREF(fExecutable);
-
-    /* create the object. */
-    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_LOW, NULL, cb);
+    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD),
+                                                                       RTR0MEMOBJTYPE_PAGE, NULL, cb);
     if (!pMemFreeBSD)
         return VERR_NO_MEMORY;
 
-    pMemFreeBSD->Core.pv = (void *)kmem_alloc_attr(kernel_map,          /* Kernel */
-                                                   cb,                  /* Amount */
-                                                   M_ZERO,              /* Zero memory */
-                                                   0,                   /* Low physical address */
-                                                   _4G - PAGE_SIZE,     /* Highest physical address */
-                                                   VM_MEMATTR_DEFAULT); /* Default memory attributes */
-    if (!pMemFreeBSD->Core.pv)
-        return VERR_NO_MEMORY;
-
-    *ppMem = &pMemFreeBSD->Core;
-
-    return VINF_SUCCESS;
-#else
-    /*
-     * Try a Alloc first and see if we get luck, if not try contigmalloc.
-     * Might wish to try find our own pages or something later if this
-     * turns into a problemspot on AMD64 boxes.
-     */
-    int rc = rtR0MemObjNativeAllocPage(ppMem, cb, fExecutable);
-    if (RT_SUCCESS(rc))
+    int rc = FreeBSDAllocHelper(pMemFreeBSD, fExecutable, ~(vm_paddr_t)0, false);
+    if (RT_FAILURE(rc))
     {
-        size_t iPage = cb >> PAGE_SHIFT;
-        while (iPage-- > 0)
-            if (rtR0MemObjNativeGetPagePhysAddr(*ppMem, iPage) > (_4G - PAGE_SIZE))
-            {
-                RTR0MemObjFree(*ppMem, false);
-                *ppMem = NULL;
-                rc = VERR_NO_MEMORY;
-                break;
-            }
+        rtR0MemObjDelete(&pMemFreeBSD->Core);
+        return rc;
     }
-    if (RT_FAILURE(rc))
-        rc = rtR0MemObjNativeAllocCont(ppMem, cb, fExecutable);
+
+    *ppMem = &pMemFreeBSD->Core;
     return rc;
-#endif
 }
 
 
-DECLHIDDEN(int) rtR0MemObjNativeAllocCont(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable)
+DECLHIDDEN(int) rtR0MemObjNativeAllocLow(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable)
 {
-    /* create the object. */
-    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_CONT, NULL, cb);
+    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD),
+                                                                       RTR0MEMOBJTYPE_LOW, NULL, cb);
     if (!pMemFreeBSD)
         return VERR_NO_MEMORY;
 
-    /* do the allocation. */
-    pMemFreeBSD->Core.pv = contigmalloc(cb,                   /* size */
-                                        M_IPRTMOBJ,           /* type */
-                                        M_NOWAIT | M_ZERO,    /* flags */
-                                        0,                    /* lowest physical address*/
-                                        _4G-1,                /* highest physical address */
-                                        PAGE_SIZE,            /* alignment. */
-                                        0);                   /* boundary */
-    if (pMemFreeBSD->Core.pv)
+    int rc = FreeBSDAllocHelper(pMemFreeBSD, fExecutable, _4G - 1, false);
+    if (RT_FAILURE(rc))
     {
-        pMemFreeBSD->Core.u.Cont.Phys = vtophys(pMemFreeBSD->Core.pv);
-        *ppMem = &pMemFreeBSD->Core;
-        return VINF_SUCCESS;
+        rtR0MemObjDelete(&pMemFreeBSD->Core);
+        return rc;
     }
 
-    NOREF(fExecutable);
-    rtR0MemObjDelete(&pMemFreeBSD->Core);
-    return VERR_NO_MEMORY;
+    *ppMem = &pMemFreeBSD->Core;
+    return rc;
 }
 
 
-static void rtR0MemObjFreeBSDPhysPageInit(vm_page_t pPage, vm_pindex_t iPage)
+DECLHIDDEN(int) rtR0MemObjNativeAllocCont(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable)
 {
-    pPage->wire_count = 1;
-    pPage->pindex     = iPage;
-    pPage->act_count  = 0;
-    pPage->oflags     = 0;
-    pPage->flags      = PG_UNMANAGED;
-    atomic_add_int(&cnt.v_wire_count, 1);
+    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD),
+                                                                       RTR0MEMOBJTYPE_CONT, NULL, cb);
+    if (!pMemFreeBSD)
+        return VERR_NO_MEMORY;
+
+    int rc = FreeBSDAllocHelper(pMemFreeBSD, fExecutable, _4G - 1, true);
+    if (RT_FAILURE(rc))
+    {
+        rtR0MemObjDelete(&pMemFreeBSD->Core);
+        return rc;
+    }
+
+    pMemFreeBSD->Core.u.Cont.Phys = vtophys(pMemFreeBSD->Core.pv);
+    *ppMem = &pMemFreeBSD->Core;
+    return rc;
 }
 
 
@@ -405,69 +374,36 @@
                                            RTHCPHYS PhysHighest, size_t uAlignment,
                                            bool fContiguous)
 {
-    int        rc = VINF_SUCCESS;
-    uint32_t   cPages = cb >> PAGE_SHIFT;
+    uint32_t   cPages = atop(cb);
     vm_paddr_t VmPhysAddrHigh;
 
     /* create the object. */
-    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(RT_OFFSETOF(RTR0MEMOBJFREEBSD, u.Phys.apPages[cPages]),
+    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD),
                                                                        enmType, NULL, cb);
     if (!pMemFreeBSD)
         return VERR_NO_MEMORY;
 
-    pMemFreeBSD->u.Phys.cPages = cPages;
+    pMemFreeBSD->pObject = vm_object_allocate(OBJT_PHYS, atop(cb));
 
     if (PhysHighest != NIL_RTHCPHYS)
         VmPhysAddrHigh = PhysHighest;
     else
         VmPhysAddrHigh = ~(vm_paddr_t)0;
 
-    if (fContiguous)
-    {
-        vm_page_t pPage = vm_phys_alloc_contig(cPages, 0, VmPhysAddrHigh, uAlignment, 0);
-
-        if (pPage)
-            for (uint32_t iPage = 0; iPage < cPages; iPage++)
-            {
-                rtR0MemObjFreeBSDPhysPageInit(&pPage[iPage], iPage);
-                pMemFreeBSD->u.Phys.apPages[iPage] = &pPage[iPage];
-            }
-        else
-            rc = VERR_NO_MEMORY;
-    }
-    else
-    {
-        /* Allocate page by page */
-        for (uint32_t iPage = 0; iPage < cPages; iPage++)
-        {
-            vm_page_t pPage = vm_phys_alloc_contig(1, 0, VmPhysAddrHigh, uAlignment, 0);
-
-            if (!pPage)
-            {
-                /* Free all allocated pages */
-                while (iPage-- > 0)
-                {
-                    pPage = pMemFreeBSD->u.Phys.apPages[iPage];
-                    vm_page_lock_queues();
-                    vm_page_unwire(pPage, 0);
-                    vm_page_free(pPage);
-                    vm_page_unlock_queues();
-                }
-                rc = VERR_NO_MEMORY;
-                break;
-            }
-            rtR0MemObjFreeBSDPhysPageInit(pPage, iPage);
-            pMemFreeBSD->u.Phys.apPages[iPage] = pPage;
-        }
-    }
+    int rc = FreeBSDPhysAllocHelper(pMemFreeBSD->pObject, cPages, VmPhysAddrHigh, uAlignment, fContiguous, true);
 
-    if (RT_FAILURE(rc))
+    if (RT_FAILURE(rc)) {
+        vm_object_deallocate(pMemFreeBSD->pObject);
         rtR0MemObjDelete(&pMemFreeBSD->Core);
+    }
     else
     {
-        if (enmType == RTR0MEMOBJTYPE_PHYS)
+        if (fContiguous)
         {
-            pMemFreeBSD->Core.u.Phys.PhysBase = VM_PAGE_TO_PHYS(pMemFreeBSD->u.Phys.apPages[0]);
+            Assert(enmType == RTR0MEMOBJTYPE_PHYS);
+            VM_OBJECT_LOCK(pMemFreeBSD->pObject);
+            pMemFreeBSD->Core.u.Phys.PhysBase = VM_PAGE_TO_PHYS(vm_page_find_least(pMemFreeBSD->pObject, 0));
+            VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
             pMemFreeBSD->Core.u.Phys.fAllocated = true;
         }
 
@@ -480,42 +416,13 @@
 
 DECLHIDDEN(int) rtR0MemObjNativeAllocPhys(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, RTHCPHYS PhysHighest, size_t uAlignment)
 {
-#if 1
     return rtR0MemObjFreeBSDAllocPhysPages(ppMem, RTR0MEMOBJTYPE_PHYS, cb, PhysHighest, uAlignment, true);
-#else
-    /* create the object. */
-    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_CONT, NULL, cb);
-    if (!pMemFreeBSD)
-        return VERR_NO_MEMORY;
-
-    /* do the allocation. */
-    pMemFreeBSD->Core.pv = contigmalloc(cb,                   /* size */
-                                        M_IPRTMOBJ,           /* type */
-                                        M_NOWAIT | M_ZERO,    /* flags */
-                                        0,                    /* lowest physical address*/
-                                        _4G-1,                /* highest physical address */
-                                        uAlignment,           /* alignment. */
-                                        0);                   /* boundary */
-    if (pMemFreeBSD->Core.pv)
-    {
-        pMemFreeBSD->Core.u.Cont.Phys = vtophys(pMemFreeBSD->Core.pv);
-        *ppMem = &pMemFreeBSD->Core;
-        return VINF_SUCCESS;
-    }
-
-    rtR0MemObjDelete(&pMemFreeBSD->Core);
-    return VERR_NO_MEMORY;
-#endif
 }
 
 
 DECLHIDDEN(int) rtR0MemObjNativeAllocPhysNC(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, RTHCPHYS PhysHighest)
 {
-#if 1
     return rtR0MemObjFreeBSDAllocPhysPages(ppMem, RTR0MEMOBJTYPE_PHYS_NC, cb, PhysHighest, PAGE_SIZE, false);
-#else
-    return VERR_NOT_SUPPORTED;
-#endif
 }
 
 
@@ -625,49 +532,41 @@
     if (!pMemFreeBSD)
         return VERR_NO_MEMORY;
 
-    /*
-     * Allocate an empty VM object and map it into the requested map.
-     */
-    pMemFreeBSD->u.NonPhys.pObject = vm_object_allocate(OBJT_DEFAULT, cb >> PAGE_SHIFT);
-    if (pMemFreeBSD->u.NonPhys.pObject)
+    vm_offset_t MapAddress = pvFixed != (void *)-1
+                           ? (vm_offset_t)pvFixed
+                           : vm_map_min(pMap);
+    if (pvFixed != (void *)-1)
+        vm_map_remove(pMap,
+                      MapAddress,
+                      MapAddress + cb);
+
+    rc = vm_map_find(pMap,                          /* map */
+                     NULL,                          /* object */
+                     0,                             /* offset */
+                     &MapAddress,                   /* addr (IN/OUT) */
+                     cb,                            /* length */
+                     pvFixed == (void *)-1 ? VMFS_ANY_SPACE : VMFS_NO_SPACE,
+                                                    /* find_space */
+                     VM_PROT_NONE,                  /* protection */
+                     VM_PROT_ALL,                   /* max(_prot) ?? */
+                     0);                            /* cow (copy-on-write) */
+    if (rc == KERN_SUCCESS)
     {
-        vm_offset_t MapAddress = pvFixed != (void *)-1
-                               ? (vm_offset_t)pvFixed
-                               : vm_map_min(pMap);
-        if (pvFixed != (void *)-1)
-            vm_map_remove(pMap,
-                          MapAddress,
-                          MapAddress + cb);
-
-        rc = vm_map_find(pMap,                          /* map */
-                         pMemFreeBSD->u.NonPhys.pObject, /* object */
-                         0,                             /* offset */
-                         &MapAddress,                   /* addr (IN/OUT) */
-                         cb,                            /* length */
-                         pvFixed == (void *)-1,         /* find_space */
-                         VM_PROT_NONE,                  /* protection */
-                         VM_PROT_ALL,                   /* max(_prot) ?? */
-                         0);                            /* cow (copy-on-write) */
-        if (rc == KERN_SUCCESS)
+        if (R0Process != NIL_RTR0PROCESS)
         {
-            if (R0Process != NIL_RTR0PROCESS)
-            {
-                rc = vm_map_inherit(pMap,
-                                    MapAddress,
-                                    MapAddress + cb,
-                                    VM_INHERIT_SHARE);
-                AssertMsg(rc == KERN_SUCCESS, ("%#x\n", rc));
-            }
-            pMemFreeBSD->Core.pv = (void *)MapAddress;
-            pMemFreeBSD->Core.u.ResVirt.R0Process = R0Process;
-            *ppMem = &pMemFreeBSD->Core;
-            return VINF_SUCCESS;
+            rc = vm_map_inherit(pMap,
+                                MapAddress,
+                                MapAddress + cb,
+                                VM_INHERIT_SHARE);
+            AssertMsg(rc == KERN_SUCCESS, ("%#x\n", rc));
         }
-        vm_object_deallocate(pMemFreeBSD->u.NonPhys.pObject);
-        rc = VERR_NO_MEMORY; /** @todo fix translation (borrow from darwin) */
+        pMemFreeBSD->Core.pv = (void *)MapAddress;
+        pMemFreeBSD->Core.u.ResVirt.R0Process = R0Process;
+        *ppMem = &pMemFreeBSD->Core;
+        return VINF_SUCCESS;
     }
-    else
-        rc = VERR_NO_MEMORY;
+
+    rc = VERR_NO_MEMORY; /** @todo fix translation (borrow from darwin) */
     rtR0MemObjDelete(&pMemFreeBSD->Core);
     return rc;
 
@@ -690,7 +589,7 @@
 DECLHIDDEN(int) rtR0MemObjNativeMapKernel(PPRTR0MEMOBJINTERNAL ppMem, RTR0MEMOBJ pMemToMap, void *pvFixed, size_t uAlignment,
                                           unsigned fProt, size_t offSub, size_t cbSub)
 {
-    AssertMsgReturn(!offSub && !cbSub, ("%#x %#x\n", offSub, cbSub), VERR_NOT_SUPPORTED);
+//  AssertMsgReturn(!offSub && !cbSub, ("%#x %#x\n", offSub, cbSub), VERR_NOT_SUPPORTED);
     AssertMsgReturn(pvFixed == (void *)-1, ("%p\n", pvFixed), VERR_NOT_SUPPORTED);
 
     /*
@@ -699,21 +598,68 @@
     if (uAlignment > PAGE_SIZE)
         return VERR_NOT_SUPPORTED;
 
-/* Phys: see pmap_mapdev in i386/i386/pmap.c (http://fxr.watson.org/fxr/source/i386/i386/pmap.c?v=RELENG62#L2860) */
-/** @todo finish the implementation. */
+    int                rc;
+    PRTR0MEMOBJFREEBSD pMemToMapFreeBSD = (PRTR0MEMOBJFREEBSD)pMemToMap;
 
-    return VERR_NOT_SUPPORTED;
+    /* calc protection */
+    vm_prot_t       ProtectionFlags = 0;
+    if ((fProt & RTMEM_PROT_NONE) == RTMEM_PROT_NONE)
+        ProtectionFlags = VM_PROT_NONE;
+    if ((fProt & RTMEM_PROT_READ) == RTMEM_PROT_READ)
+        ProtectionFlags |= VM_PROT_READ;
+    if ((fProt & RTMEM_PROT_WRITE) == RTMEM_PROT_WRITE)
+        ProtectionFlags |= VM_PROT_WRITE;
+    if ((fProt & RTMEM_PROT_EXEC) == RTMEM_PROT_EXEC)
+        ProtectionFlags |= VM_PROT_EXECUTE;
+
+    vm_offset_t  Addr = vm_map_min(kernel_map);
+    if (cbSub == 0)
+        cbSub = pMemToMap->cb - offSub;
+
+    vm_object_reference(pMemToMapFreeBSD->pObject);
+    rc = vm_map_find(kernel_map,            /* Map to insert the object in */
+                     pMemToMapFreeBSD->pObject, /* Object to map */
+                     offSub,                /* Start offset in the object */
+                     &Addr,                 /* Start address IN/OUT */
+                     cbSub,                 /* Size of the mapping */
+                     VMFS_ANY_SPACE,        /* Whether a suitable address should be searched for first */
+                     ProtectionFlags,       /* protection flags */
+                     VM_PROT_ALL,           /* Maximum protection flags */
+                     0);                    /* copy-on-write and similar flags */
+
+    if (rc == KERN_SUCCESS)
+    {
+        rc = vm_map_wire(kernel_map, Addr, Addr + cbSub, VM_MAP_WIRE_SYSTEM|VM_MAP_WIRE_NOHOLES);
+        AssertMsg(rc == KERN_SUCCESS, ("%#x\n", rc));
+
+        PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(RTR0MEMOBJFREEBSD),
+                                                                           RTR0MEMOBJTYPE_MAPPING,
+                                                                           (void *)Addr,
+                                                                           cbSub);
+        if (pMemFreeBSD)
+        {
+            Assert((vm_offset_t)pMemFreeBSD->Core.pv == Addr);
+            pMemFreeBSD->Core.u.Mapping.R0Process = NIL_RTR0PROCESS;
+            *ppMem = &pMemFreeBSD->Core;
+            return VINF_SUCCESS;
+        }
+        rc = vm_map_remove(kernel_map, Addr, Addr + cbSub);
+        AssertMsg(rc == KERN_SUCCESS, ("Deleting mapping failed\n"));
+    }
+    else
+        vm_object_deallocate(pMemToMapFreeBSD->pObject);
+
+    return VERR_NO_MEMORY;
 }
 
 
-/* see http://markmail.org/message/udhq33tefgtyfozs */
-DECLHIDDEN(int) rtR0MemObjNativeMapUser(PPRTR0MEMOBJINTERNAL ppMem, RTR0MEMOBJ pMemToMap, RTR3PTR R3PtrFixed, size_t uAlignment, unsigned fProt, RTR0PROCESS R0Process)
+DECLHIDDEN(int) rtR0MemObjNativeMapUser(PPRTR0MEMOBJINTERNAL ppMem, RTR0MEMOBJ pMemToMap, RTR3PTR R3PtrFixed, size_t uAlignment,
+                                        unsigned fProt, RTR0PROCESS R0Process)
 {
     /*
      * Check for unsupported stuff.
      */
     AssertMsgReturn(R0Process == RTR0ProcHandleSelf(), ("%p != %p\n", R0Process, RTR0ProcHandleSelf()), VERR_NOT_SUPPORTED);
-    AssertMsgReturn(R3PtrFixed == (RTR3PTR)-1, ("%p\n", R3PtrFixed), VERR_NOT_SUPPORTED);
     if (uAlignment > PAGE_SIZE)
         return VERR_NOT_SUPPORTED;
 
@@ -734,62 +680,38 @@
         ProtectionFlags |= VM_PROT_EXECUTE;
 
     /* calc mapping address */
-    PROC_LOCK(pProc);
-    vm_offset_t AddrR3 = round_page((vm_offset_t)pProc->p_vmspace->vm_daddr + lim_max(pProc, RLIMIT_DATA));
-    PROC_UNLOCK(pProc);
+    vm_offset_t AddrR3;
+    if (R3PtrFixed == (RTR3PTR)-1)
+    {
+        // is this needed?
+        PROC_LOCK(pProc);
+        AddrR3 = round_page((vm_offset_t)pProc->p_vmspace->vm_daddr + lim_max(pProc, RLIMIT_DATA));
+        PROC_UNLOCK(pProc);
+    }
+    else
+        AddrR3 = (vm_offset_t)R3PtrFixed;
 
-    /* Insert the object in the map. */
+    /* Insert the pObject in the map. */
+    vm_object_reference(pMemToMapFreeBSD->pObject);
     rc = vm_map_find(pProcMap,              /* Map to insert the object in */
-                     NULL,                  /* Object to map */
+                     pMemToMapFreeBSD->pObject, /* Object to map */
                      0,                     /* Start offset in the object */
                      &AddrR3,               /* Start address IN/OUT */
                      pMemToMap->cb,         /* Size of the mapping */
-                     TRUE,                  /* Whether a suitable address should be searched for first */
+                     R3PtrFixed == (RTR3PTR)-1 ? VMFS_ANY_SPACE : VMFS_NO_SPACE,
+                                            /* Whether a suitable address should be searched for first */
                      ProtectionFlags,       /* protection flags */
                      VM_PROT_ALL,           /* Maximum protection flags */
-                     0);                    /* Copy on write */
+                     0);                    /* copy-on-write and similar flags */
 
-    /* Map the memory page by page into the destination map. */
     if (rc == KERN_SUCCESS)
     {
-        size_t         cPages       = pMemToMap->cb >> PAGE_SHIFT;;
-        pmap_t         pPhysicalMap = pProcMap->pmap;
-        vm_offset_t    AddrR3Dst    = AddrR3;
-
-        if (   pMemToMap->enmType == RTR0MEMOBJTYPE_PHYS
-            || pMemToMap->enmType == RTR0MEMOBJTYPE_PHYS_NC
-            || pMemToMap->enmType == RTR0MEMOBJTYPE_PAGE)
-        {
-            /* Mapping physical allocations */
-            Assert(cPages == pMemToMapFreeBSD->u.Phys.cPages);
+        rc = vm_map_wire(pProcMap, AddrR3, AddrR3 + pMemToMap->cb, VM_MAP_WIRE_USER|VM_MAP_WIRE_NOHOLES);
+        AssertMsg(rc == KERN_SUCCESS, ("%#x\n", rc));
 
-            /* Insert the memory page by page into the mapping. */
-            for (uint32_t iPage = 0; iPage < cPages; iPage++)
-            {
-                vm_page_t pPage = pMemToMapFreeBSD->u.Phys.apPages[iPage];
+        rc = vm_map_inherit(pProcMap, AddrR3, AddrR3 + pMemToMap->cb, VM_INHERIT_SHARE);
+        AssertMsg(rc == KERN_SUCCESS, ("%#x\n", rc));
 
-                MY_PMAP_ENTER(pPhysicalMap, AddrR3Dst, pPage, ProtectionFlags, TRUE);
-                AddrR3Dst += PAGE_SIZE;
-            }
-        }
-        else
-        {
-            /* Mapping cont or low memory types */
-            vm_offset_t AddrToMap = (vm_offset_t)pMemToMap->pv;
-
-            for (uint32_t iPage = 0; iPage < cPages; iPage++)
-            {
-                vm_page_t pPage = PHYS_TO_VM_PAGE(vtophys(AddrToMap));
-
-                MY_PMAP_ENTER(pPhysicalMap, AddrR3Dst, pPage, ProtectionFlags, TRUE);
-                AddrR3Dst += PAGE_SIZE;
-                AddrToMap += PAGE_SIZE;
-            }
-        }
-    }
-
-    if (RT_SUCCESS(rc))
-    {
         /*
          * Create a mapping object for it.
          */
@@ -805,9 +727,11 @@
             return VINF_SUCCESS;
         }
 
-        rc = vm_map_remove(pProcMap, ((vm_offset_t)AddrR3), ((vm_offset_t)AddrR3) + pMemToMap->cb);
+        rc = vm_map_remove(pProcMap, AddrR3, AddrR3 + pMemToMap->cb);
         AssertMsg(rc == KERN_SUCCESS, ("Deleting mapping failed\n"));
     }
+    else
+        vm_object_deallocate(pMemToMapFreeBSD->pObject);
 
     return VERR_NO_MEMORY;
 }
@@ -855,49 +779,47 @@
                 return NIL_RTHCPHYS;
             }
 
-            vm_offset_t pb = (vm_offset_t)pMemFreeBSD->Core.pv + (iPage << PAGE_SHIFT);
+            vm_offset_t pb = (vm_offset_t)pMemFreeBSD->Core.pv + ptoa(iPage);
 
             struct proc    *pProc     = (struct proc *)pMemFreeBSD->Core.u.Lock.R0Process;
             struct vm_map  *pProcMap  = &pProc->p_vmspace->vm_map;
-            pmap_t pPhysicalMap       = pProcMap->pmap;
+            pmap_t pPhysicalMap       = vm_map_pmap(pProcMap);
 
             return pmap_extract(pPhysicalMap, pb);
         }
 
         case RTR0MEMOBJTYPE_MAPPING:
         {
-            vm_offset_t pb = (vm_offset_t)pMemFreeBSD->Core.pv + (iPage << PAGE_SHIFT);
+            vm_offset_t pb = (vm_offset_t)pMemFreeBSD->Core.pv + ptoa(iPage);
 
             if (pMemFreeBSD->Core.u.Mapping.R0Process != NIL_RTR0PROCESS)
             {
                 struct proc    *pProc     = (struct proc *)pMemFreeBSD->Core.u.Mapping.R0Process;
                 struct vm_map  *pProcMap  = &pProc->p_vmspace->vm_map;
-                pmap_t pPhysicalMap       = pProcMap->pmap;
+                pmap_t pPhysicalMap       = vm_map_pmap(pProcMap);
 
                 return pmap_extract(pPhysicalMap, pb);
             }
             return vtophys(pb);
         }
 
-        case RTR0MEMOBJTYPE_CONT:
-            return pMemFreeBSD->Core.u.Cont.Phys + (iPage << PAGE_SHIFT);
-
-        case RTR0MEMOBJTYPE_PHYS:
-            return pMemFreeBSD->Core.u.Phys.PhysBase + (iPage << PAGE_SHIFT);
-
         case RTR0MEMOBJTYPE_PAGE:
-        case RTR0MEMOBJTYPE_PHYS_NC:
-            return VM_PAGE_TO_PHYS(pMemFreeBSD->u.Phys.apPages[iPage]);
-
-#ifdef USE_KMEM_ALLOC_ATTR
         case RTR0MEMOBJTYPE_LOW:
+        case RTR0MEMOBJTYPE_PHYS_NC:
         {
-            vm_offset_t pb = (vm_offset_t)pMemFreeBSD->Core.pv + (iPage << PAGE_SHIFT);
-            return vtophys(pb);
+            RTHCPHYS addr;
+            VM_OBJECT_LOCK(pMemFreeBSD->pObject);
+            addr = VM_PAGE_TO_PHYS(vm_page_lookup(pMemFreeBSD->pObject, iPage));
+            VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
+            return addr;
         }
-#else
-        case RTR0MEMOBJTYPE_LOW:
-#endif
+
+        case RTR0MEMOBJTYPE_PHYS:
+            return pMemFreeBSD->Core.u.Cont.Phys + ptoa(iPage);
+
+        case RTR0MEMOBJTYPE_CONT:
+            return pMemFreeBSD->Core.u.Phys.PhysBase + ptoa(iPage);
+
         case RTR0MEMOBJTYPE_RES_VIRT:
         default:
             return NIL_RTHCPHYS;
