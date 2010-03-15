Index: src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
===================================================================
--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	(Revision 58727)
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	(Arbeitskopie)
@@ -43,6 +43,16 @@
 #include <iprt/process.h>
 #include "internal/memobj.h"
 
+/**
+ * Our pmap_enter version
+ */
+#if __FreeBSD_version >= 701105
+# define MY_PMAP_ENTER(pPhysMap, AddrR3, pPage, fProt, fWired) \
+    pmap_enter(pPhysMap, AddrR3, VM_PROT_NONE, pPage, fProt, fWired)
+#else
+# define MY_PMAP_ENTER(pPhysMap, AddrR3, pPage, fProt, fWired) \
+    pmap_enter(pPhysMap, AddrR3, pPage, fProt, fWired)
+#endif
 
 /*******************************************************************************
 *   Structures and Typedefs                                                    *
@@ -54,12 +64,24 @@
 {
     /** The core structure. */
     RTR0MEMOBJINTERNAL  Core;
-    /** The VM object associated with the allocation. */
-    vm_object_t         pObject;
-    /** the VM object associated with the mapping.
-     * In mapping mem object, this is the shadow object?
-     * In a allocation/enter mem object, this is the shared object we constructed (contig, perhaps alloc). */
-    vm_object_t         pMappingObject;
+    /** Type dependent data */
+    union
+    {
+        /** Non physical memory allocations */
+        struct
+        {
+            /** The VM object associated with the allocation. */
+            vm_object_t         pObject;
+        } NonPhys;
+        /** Physical memory allocations */
+        struct
+        {
+            /** Number of pages */
+            uint32_t            cPages;
+            /** Array of pages - variable */
+            vm_page_t           apPages[1];
+        } Phys;
+    } u;
 } RTR0MEMOBJFREEBSD, *PRTR0MEMOBJFREEBSD;
 
 
@@ -69,7 +91,45 @@
 *   Internal Functions                                                         *
 *******************************************************************************/
 
+/**
+ * Gets the virtual memory map the specified object is mapped into.
+ *
+ * @returns VM map handle on success, NULL if no map.
+ * @param   pMem                The memory object.
+ */
+static vm_map_t rtR0MemObjFreeBSDGetMap(PRTR0MEMOBJINTERNAL pMem)
+{
+    switch (pMem->enmType)
+    {
+        case RTR0MEMOBJTYPE_PAGE:
+        case RTR0MEMOBJTYPE_LOW:
+        case RTR0MEMOBJTYPE_CONT:
+            return kernel_map;
 
+        case RTR0MEMOBJTYPE_PHYS:
+        case RTR0MEMOBJTYPE_PHYS_NC:
+            return NULL; /* pretend these have no mapping atm. */
+
+        case RTR0MEMOBJTYPE_LOCK:
+            return pMem->u.Lock.R0Process == NIL_RTR0PROCESS
+                ? kernel_map
+                : &((struct proc *)pMem->u.Lock.R0Process)->p_vmspace->vm_map;
+
+        case RTR0MEMOBJTYPE_RES_VIRT:
+            return pMem->u.ResVirt.R0Process == NIL_RTR0PROCESS
+                ? kernel_map
+                : &((struct proc *)pMem->u.ResVirt.R0Process)->p_vmspace->vm_map;
+
+        case RTR0MEMOBJTYPE_MAPPING:
+            return pMem->u.Mapping.R0Process == NIL_RTR0PROCESS
+                ? kernel_map
+                : &((struct proc *)pMem->u.Mapping.R0Process)->p_vmspace->vm_map;
+
+        default:
+            return NULL;
+    }
+}
+
 int rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
 {
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)pMem;
@@ -79,53 +139,37 @@
     {
         case RTR0MEMOBJTYPE_CONT:
             contigfree(pMemFreeBSD->Core.pv, pMemFreeBSD->Core.cb, M_IPRTMOBJ);
-            if (pMemFreeBSD->pMappingObject)
-            {
-                rc = vm_map_remove(kernel_map,
-                                   (vm_offset_t)pMemFreeBSD->Core.pv,
-                                   (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb);
-                AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
-            }
             break;
 
         case RTR0MEMOBJTYPE_PAGE:
-            if (pMemFreeBSD->pObject)
+        {
+            rc = vm_map_remove(kernel_map,
+                                (vm_offset_t)pMemFreeBSD->Core.pv,
+                                (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb);
+            AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
+
+            vm_page_lock_queues();
+            for (uint32_t iPage = 0; iPage < pMemFreeBSD->u.Phys.cPages; iPage++)
             {
-                rc = vm_map_remove(kernel_map,
-                                   (vm_offset_t)pMemFreeBSD->Core.pv,
-                                   (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb);
-                AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
+                vm_page_t pPage = pMemFreeBSD->u.Phys.apPages[iPage];
+                vm_page_unwire(pPage, 0);
+                vm_page_free(pPage);
             }
-            else
-            {
-                contigfree(pMemFreeBSD->Core.pv, pMemFreeBSD->Core.cb, M_IPRTMOBJ);
-                if (pMemFreeBSD->pMappingObject)
-                {
-                    rc = vm_map_remove(kernel_map,
-                                       (vm_offset_t)pMemFreeBSD->Core.pv,
-                                       (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb);
-                    AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
-                }
-            }
+            vm_page_unlock_queues();
             break;
+        }
 
         case RTR0MEMOBJTYPE_LOCK:
         {
-            int fFlags = VM_MAP_WIRE_NOHOLES;
             vm_map_t pMap = kernel_map;
 
             if (pMemFreeBSD->Core.u.Lock.R0Process != NIL_RTR0PROCESS)
-            {
                 pMap = &((struct proc *)pMemFreeBSD->Core.u.Lock.R0Process)->p_vmspace->vm_map;
-                fFlags |= VM_MAP_WIRE_USER;
-            }
-            else
-                fFlags |= VM_MAP_WIRE_SYSTEM;
 
             rc = vm_map_unwire(pMap,
                                (vm_offset_t)pMemFreeBSD->Core.pv,
                                (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb,
-                               fFlags);
+                               VM_MAP_WIRE_SYSTEM | VM_MAP_WIRE_NOHOLES);
             AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
             break;
         }
@@ -146,8 +190,6 @@
         {
             vm_map_t pMap = kernel_map;
 
-            /* vm_map_remove will unmap the pages we inserted with pmap_enter */
-            AssertMsg(pMemFreeBSD->pMappingObject != NULL, ("MappingObject is NULL\n"));
             if (pMemFreeBSD->Core.u.Mapping.R0Process != NIL_RTR0PROCESS)
                 pMap = &((struct proc *)pMemFreeBSD->Core.u.Mapping.R0Process)->p_vmspace->vm_map;
 
@@ -158,10 +200,22 @@
             break;
         }
 
+        case RTR0MEMOBJTYPE_PHYS:
+        case RTR0MEMOBJTYPE_PHYS_NC:
+        {
+            vm_page_lock_queues();
+            for (uint32_t iPage = 0; iPage < pMemFreeBSD->u.Phys.cPages; iPage++)
+            {
+                vm_page_t pPage = pMemFreeBSD->u.Phys.apPages[iPage];
+                vm_page_unwire(pPage, 0);
+                vm_page_free(pPage);
+            }
+            vm_page_unlock_queues();
+            break;
+        }
+
         /* unused: */
         case RTR0MEMOBJTYPE_LOW:
-        case RTR0MEMOBJTYPE_PHYS:
-        case RTR0MEMOBJTYPE_PHYS_NC:
         default:
             AssertMsgFailed(("enmType=%d\n", pMemFreeBSD->Core.enmType));
             return VERR_INTERNAL_ERROR;
@@ -177,95 +231,83 @@
     size_t cPages = cb >> PAGE_SHIFT;
 
     /* create the object. */
-    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_PAGE, NULL, cb);
+    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(RT_OFFSETOF(RTR0MEMOBJFREEBSD, u.Phys.apPages[cPages]),
+                                                                       RTR0MEMOBJTYPE_PAGE, NULL, cb);
     if (!pMemFreeBSD)
         return VERR_NO_MEMORY;
 
-    pMemFreeBSD->pObject = vm_object_allocate(OBJT_DEFAULT, cPages);
-    if (pMemFreeBSD->pObject)
+    pMemFreeBSD->u.Phys.cPages = cPages;
+
+    vm_offset_t MapAddress = vm_map_min(kernel_map);
+    rc = vm_map_find(kernel_map,                /* map */
+                     NULL,                      /* object */
+                     0,                         /* offset */
+                     &MapAddress,               /* addr (IN/OUT) */
+                     cb,                        /* length */
+                     TRUE,                      /* find_space */
+                     fExecutable                /* protection */
+                     ? VM_PROT_ALL
+                     : VM_PROT_RW,
+                     VM_PROT_ALL,               /* max(_prot) */
+                     0);                        /* cow (copy-on-write) */
+    if (rc == KERN_SUCCESS)
     {
-        vm_offset_t MapAddress = vm_map_min(kernel_map);
-        rc = vm_map_find(kernel_map,                    /* map */
-                         pMemFreeBSD->pObject,          /* object */
-                         0,                             /* offset */
-                         &MapAddress,                   /* addr (IN/OUT) */
-                         cb,                            /* length */
-                         TRUE,                          /* find_space */
-                         fExecutable                    /* protection */
-                         ? VM_PROT_ALL
-                         : VM_PROT_RW,
-                         VM_PROT_ALL,                   /* max(_prot) */
-                         FALSE);                        /* cow (copy-on-write) */
-        if (rc == KERN_SUCCESS)
+        rc = VINF_SUCCESS;
+
+        for (size_t iPage = 0; iPage < cPages; iPage++)
         {
-            vm_offset_t AddressDst = MapAddress;
+            vm_page_t   pPage;
 
-            rc = VINF_SUCCESS;
+            pPage = vm_page_alloc(NULL, iPage,
+                                  VM_ALLOC_SYSTEM |
+                                  VM_ALLOC_WIRED | VM_ALLOC_NOOBJ);
 
-            VM_OBJECT_LOCK(pMemFreeBSD->pObject);
-            for (size_t iPage = 0; iPage < cPages; iPage++)
+            if (!pPage)
             {
-                vm_pindex_t PageIndex = OFF_TO_IDX(AddressDst);
-                vm_page_t   pPage;
-
-                pPage = vm_page_alloc(pMemFreeBSD->pObject, PageIndex,
-                                      VM_ALLOC_NOBUSY | VM_ALLOC_SYSTEM |
-                                      VM_ALLOC_WIRED);
-
-#if __FreeBSD_version >= 800000 /** @todo Find exact version number */
-                /* Fixes crashes during VM termination on FreeBSD8-CURRENT amd64
-                 * with kernel debugging enabled. */
-                vm_page_set_valid(pPage, 0, PAGE_SIZE);
-#endif
-
-                if (pPage)
+                /*
+                    * Out of pages
+                    * Remove already allocated pages
+                    */
+                while (iPage-- > 0)
                 {
+                    pPage = pMemFreeBSD->u.Phys.apPages[iPage];
                     vm_page_lock_queues();
-                    vm_page_wire(pPage);
+                    vm_page_unwire(pPage, 0);
+                    vm_page_free(pPage);
                     vm_page_unlock_queues();
-                    /* Put the page into the page table now. */
-#if __FreeBSD_version >= 701105
-                    pmap_enter(kernel_map->pmap, AddressDst, VM_PROT_NONE, pPage,
-                               fExecutable
-                               ? VM_PROT_ALL
-                               : VM_PROT_RW,
-                               TRUE);
-#else
-                    pmap_enter(kernel_map->pmap, AddressDst, pPage,
-                               fExecutable
-                               ? VM_PROT_ALL
-                               : VM_PROT_RW,
-                               TRUE);
-#endif
                 }
-                else
-                {
-                    /*
-                     * Allocation failed. vm_map_remove will remove any
-                     * page already alocated.
-                     */
-                    rc = VERR_NO_MEMORY;
-                    break;
-                }
-                AddressDst += PAGE_SIZE;
+                rc = VERR_NO_MEMORY;
+                break;
             }
-            VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
 
-            if (rc == VINF_SUCCESS)
+            pPage->valid = VM_PAGE_BITS_ALL;
+            pMemFreeBSD->u.Phys.apPages[iPage] = pPage;
+        }
+
+        if (rc == VINF_SUCCESS)
+        {
+            vm_offset_t AddressDst = MapAddress;
+
+            for (size_t iPage = 0; iPage < cPages; iPage++)
             {
-                pMemFreeBSD->Core.pv = (void *)MapAddress;
-                *ppMem = &pMemFreeBSD->Core;
-                return VINF_SUCCESS;
+                vm_page_t pPage = pMemFreeBSD->u.Phys.apPages[iPage];
+
+                MY_PMAP_ENTER(kernel_map->pmap, AddressDst, pPage,
+                              fExecutable
+                              ? VM_PROT_ALL
+                              : VM_PROT_RW,
+                              TRUE);
+
+                AddressDst += PAGE_SIZE;
             }
 
-            vm_map_remove(kernel_map,
-                          MapAddress,
-                          MapAddress + cb);
+            /* Store start address */
+            pMemFreeBSD->Core.pv = (void *)MapAddress;
+            *ppMem = &pMemFreeBSD->Core;
+            return VINF_SUCCESS;
         }
-        rc = VERR_NO_MEMORY; /** @todo fix translation (borrow from darwin) */
     }
-    else
-        rc = VERR_NO_MEMORY;
+    rc = VERR_NO_MEMORY; /** @todo fix translation (borrow from darwin) */
 
     rtR0MemObjDelete(&pMemFreeBSD->Core);
     return rc;
@@ -325,12 +367,99 @@
     return VERR_NO_MEMORY;
 }
 
+static void rtR0MemObjFreeBSDPhysPageInit(vm_page_t pPage, vm_pindex_t iPage)
+{
+    pPage->wire_count = 1;
+    pPage->pindex     = iPage;
+    pPage->act_count  = 0;
+    pPage->oflags     = 0;
+    pPage->flags      = PG_UNMANAGED;
+    atomic_add_int(&cnt.v_wire_count, 1);
+}
 
-int rtR0MemObjNativeAllocPhys(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, RTHCPHYS PhysHighest)
+static int rtR0MemObjFreeBSDAllocPhysPages(PPRTR0MEMOBJINTERNAL ppMem, RTR0MEMOBJTYPE enmType,
+                                           size_t cb,
+                                           RTHCPHYS PhysHighest, size_t uAlignment,
+                                           bool fContiguous)
 {
-    /** @todo check if there is a more appropriate API somewhere.. */
+    int        rc = VINF_SUCCESS;
+    uint32_t   cPages = cb >> PAGE_SHIFT;
+    vm_paddr_t VmPhysAddrHigh;
 
     /* create the object. */
+    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(RT_OFFSETOF(RTR0MEMOBJFREEBSD, u.Phys.apPages[cPages]),
+                                                                       enmType, NULL, cb);
+    if (!pMemFreeBSD)
+        return VERR_NO_MEMORY;
+
+    pMemFreeBSD->u.Phys.cPages = cPages;
+
+    if (PhysHighest != NIL_RTHCPHYS)
+        VmPhysAddrHigh = PhysHighest;
+    else
+        VmPhysAddrHigh = ~(vm_paddr_t)0;
+
+    if (fContiguous)
+    {
+        vm_page_t pPage = vm_phys_alloc_contig(cPages, 0, VmPhysAddrHigh, uAlignment, 0);
+
+        if (pPage)
+            for (uint32_t iPage = 0; iPage < cPages; iPage++)
+            {
+                rtR0MemObjFreeBSDPhysPageInit(&pPage[iPage], iPage);
+                pMemFreeBSD->u.Phys.apPages[iPage] = &pPage[iPage];
+            }
+        else
+            rc = VERR_NO_MEMORY;
+    }
+    else
+    {
+        /* Allocate page by page */
+        for (uint32_t iPage = 0; iPage < cPages; iPage++)
+        {
+            vm_page_t pPage = vm_phys_alloc_contig(1, 0, VmPhysAddrHigh, uAlignment, 0);
+
+            if (!pPage)
+            {
+                /* Free all allocated pages */
+                while (iPage-- > 0)
+                {
+                    pPage = pMemFreeBSD->u.Phys.apPages[iPage];
+                    vm_page_lock_queues();
+                    vm_page_unwire(pPage, 0);
+                    vm_page_free(pPage);
+                    vm_page_unlock_queues();
+                }
+                rc = VERR_NO_MEMORY;
+                break;
+            }
+            rtR0MemObjFreeBSDPhysPageInit(pPage, iPage);
+            pMemFreeBSD->u.Phys.apPages[iPage] = pPage;
+        }
+    }
+
+    if (RT_FAILURE(rc))
+        rtR0MemObjDelete(&pMemFreeBSD->Core);
+    else
+    {
+        if (enmType == RTR0MEMOBJTYPE_PHYS)
+        {
+            pMemFreeBSD->Core.u.Phys.PhysBase = VM_PAGE_TO_PHYS(pMemFreeBSD->u.Phys.apPages[0]);
+            pMemFreeBSD->Core.u.Phys.fAllocated = true;
+        }
+
+        *ppMem = &pMemFreeBSD->Core;
+    }
+
+    return rc;
+}
+
+int rtR0MemObjNativeAllocPhys(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, RTHCPHYS PhysHighest)
+{
+#if 1
+    return rtR0MemObjFreeBSDAllocPhysPages(ppMem, RTR0MEMOBJTYPE_PHYS, cb, PhysHighest, PAGE_SIZE, true);
+#else
+    /* create the object. */
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_CONT, NULL, cb);
     if (!pMemFreeBSD)
         return VERR_NO_MEMORY;
@@ -340,7 +469,7 @@
                                         M_IPRTMOBJ,           /* type */
                                         M_NOWAIT | M_ZERO,    /* flags */
                                         0,                    /* lowest physical address*/
-                                        PhysHighest,          /* highest physical address */
+                                        _4G-1,                /* highest physical address */
                                         PAGE_SIZE,            /* alignment. */
                                         0);                   /* boundrary */
     if (pMemFreeBSD->Core.pv)
@@ -352,13 +481,17 @@
 
     rtR0MemObjDelete(&pMemFreeBSD->Core);
     return VERR_NO_MEMORY;
+#endif
 }
 
 
 int rtR0MemObjNativeAllocPhysNC(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, RTHCPHYS PhysHighest)
 {
-    /** @todo rtR0MemObjNativeAllocPhys / freebsd */
+#if 1
+    return rtR0MemObjFreeBSDAllocPhysPages(ppMem, RTR0MEMOBJTYPE_PHYS_NC, cb, PhysHighest, PAGE_SIZE, false);
+#else
     return VERR_NOT_SUPPORTED;
+#endif
 }
 
 
@@ -377,13 +510,18 @@
 }
 
 
-int rtR0MemObjNativeLockUser(PPRTR0MEMOBJINTERNAL ppMem, RTR3PTR R3Ptr, size_t cb, uint32_t fAccess, RTR0PROCESS R0Process)
+/**
+ * Worker locking the memory in either kernel or user maps.
+ */
+static int rtR0MemObjNativeLockInMap(PPRTR0MEMOBJINTERNAL ppMem, vm_map_t pVmMap,
+                                     vm_offset_t AddrStart, size_t cb, uint32_t fAccess,
+                                     RTR0PROCESS R0Process)
 {
     int rc;
     NOREF(fAccess);
 
     /* create the object. */
-    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_LOCK, (void *)R3Ptr, cb);
+    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_LOCK, (void *)AddrStart, cb);
     if (!pMemFreeBSD)
         return VERR_NO_MEMORY;
 
@@ -391,10 +529,10 @@
      * We could've used vslock here, but we don't wish to be subject to
      * resource usage restrictions, so we'll call vm_map_wire directly.
      */
-    rc = vm_map_wire(&((struct proc *)R0Process)->p_vmspace->vm_map, /* the map */
-                     (vm_offset_t)R3Ptr,                             /* start */
-                     (vm_offset_t)R3Ptr + cb,                        /* end */
-                     VM_MAP_WIRE_USER | VM_MAP_WIRE_NOHOLES);        /* flags */
+    rc = vm_map_wire(pVmMap,                                         /* the map */
+                     AddrStart,                                      /* start */
+                     AddrStart + cb,                                 /* end */
+                     VM_MAP_WIRE_SYSTEM | VM_MAP_WIRE_NOHOLES);      /* flags */
     if (rc == KERN_SUCCESS)
     {
         pMemFreeBSD->Core.u.Lock.R0Process = R0Process;
@@ -406,29 +544,25 @@
 }
 
 
-int rtR0MemObjNativeLockKernel(PPRTR0MEMOBJINTERNAL ppMem, void *pv, size_t cb, uint32_t fAccess)
+int rtR0MemObjNativeLockUser(PPRTR0MEMOBJINTERNAL ppMem, RTR3PTR R3Ptr, size_t cb, uint32_t fAccess, RTR0PROCESS R0Process)
 {
-    int rc;
-    NOREF(fAccess);
+    return rtR0MemObjNativeLockInMap(ppMem,
+                                     &((struct proc *)R0Process)->p_vmspace->vm_map,
+                                     (vm_offset_t)R3Ptr,
+                                     cb,
+                                     fAccess,
+                                     R0Process);
+}
 
-    /* create the object. */
-    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_LOCK, pv, cb);
-    if (!pMemFreeBSD)
-        return VERR_NO_MEMORY;
 
-    /* lock the memory */
-    rc = vm_map_wire(kernel_map,                                    /* the map */
-                     (vm_offset_t)pv,                               /* start */
-                     (vm_offset_t)pv + cb,                          /* end */
-                     VM_MAP_WIRE_SYSTEM | VM_MAP_WIRE_NOHOLES);     /* flags - SYSTEM? */
-    if (rc == KERN_SUCCESS)
-    {
-        pMemFreeBSD->Core.u.Lock.R0Process = NIL_RTR0PROCESS;
-        *ppMem = &pMemFreeBSD->Core;
-        return VINF_SUCCESS;
-    }
-    rtR0MemObjDelete(&pMemFreeBSD->Core);
-    return VERR_NO_MEMORY;/** @todo fix mach -> vbox error conversion for freebsd. */
+int rtR0MemObjNativeLockKernel(PPRTR0MEMOBJINTERNAL ppMem, void *pv, size_t cb, uint32_t fAccess)
+{
+    return rtR0MemObjNativeLockInMap(ppMem,
+                                     kernel_map,
+                                     (vm_offset_t)pv,
+                                     cb,
+                                     fAccess,
+                                     NIL_RTR0PROCESS);
 }
 
 
@@ -465,8 +599,8 @@
     /*
      * Allocate an empty VM object and map it into the requested map.
      */
-    pMemFreeBSD->pObject = vm_object_allocate(OBJT_DEFAULT, cb >> PAGE_SHIFT);
-    if (pMemFreeBSD->pObject)
+    pMemFreeBSD->u.NonPhys.pObject = vm_object_allocate(OBJT_DEFAULT, cb >> PAGE_SHIFT);
+    if (pMemFreeBSD->u.NonPhys.pObject)
     {
         vm_offset_t MapAddress = pvFixed != (void *)-1
                                ? (vm_offset_t)pvFixed
@@ -477,7 +611,7 @@
                           MapAddress + cb);
 
         rc = vm_map_find(pMap,                          /* map */
-                         pMemFreeBSD->pObject,          /* object */
+                         pMemFreeBSD->u.NonPhys.pObject, /* object */
                          0,                             /* offset */
                          &MapAddress,                   /* addr (IN/OUT) */
                          cb,                            /* length */
@@ -500,7 +634,7 @@
             *ppMem = &pMemFreeBSD->Core;
             return VINF_SUCCESS;
         }
-        vm_object_deallocate(pMemFreeBSD->pObject);
+        vm_object_deallocate(pMemFreeBSD->u.NonPhys.pObject);
         rc = VERR_NO_MEMORY; /** @todo fix translation (borrow from darwin) */
     }
     else
@@ -535,74 +669,9 @@
     if (uAlignment > PAGE_SIZE)
         return VERR_NOT_SUPPORTED;
 
-
-
 /* Phys: see pmap_mapdev in i386/i386/pmap.c (http://fxr.watson.org/fxr/source/i386/i386/pmap.c?v=RELENG62#L2860) */
-
-#if 0
 /** @todo finish the implementation. */
 
-    int rc;
-    void *pvR0 = NULL;
-    PRTR0MEMOBJFREEBSD pMemToMapOs2 = (PRTR0MEMOBJFREEBSD)pMemToMap;
-    switch (pMemToMapOs2->Core.enmType)
-    {
-        /*
-         * These has kernel mappings.
-         */
-        case RTR0MEMOBJTYPE_PAGE:
-        case RTR0MEMOBJTYPE_LOW:
-        case RTR0MEMOBJTYPE_CONT:
-            pvR0 = pMemToMapOs2->Core.pv;
-            break;
-
-        case RTR0MEMOBJTYPE_PHYS_NC:
-        case RTR0MEMOBJTYPE_PHYS:
-            pvR0 = pMemToMapOs2->Core.pv;
-            if (!pvR0)
-            {
-                /* no ring-0 mapping, so allocate a mapping in the process. */
-                AssertMsgReturn(uAlignment == PAGE_SIZE, ("%#zx\n", uAlignment), VERR_NOT_SUPPORTED);
-                AssertMsgReturn(fProt & RTMEM_PROT_WRITE, ("%#x\n", fProt), VERR_NOT_SUPPORTED);
-                Assert(!pMemToMapOs2->Core.u.Phys.fAllocated);
-                ULONG ulPhys = pMemToMapOs2->Core.u.Phys.PhysBase;
-                rc = KernVMAlloc(pMemToMapOs2->Core.cb, VMDHA_PHYS, &pvR0, (PPVOID)&ulPhys, NULL);
-                if (rc)
-                    return RTErrConvertFromOS2(rc);
-                pMemToMapOs2->Core.pv = pvR0;
-            }
-            break;
-
-        case RTR0MEMOBJTYPE_LOCK:
-            if (pMemToMapOs2->Core.u.Lock.R0Process != NIL_RTR0PROCESS)
-                return VERR_NOT_SUPPORTED; /** @todo implement this... */
-            pvR0 = pMemToMapOs2->Core.pv;
-            break;
-
-        case RTR0MEMOBJTYPE_RES_VIRT:
-        case RTR0MEMOBJTYPE_MAPPING:
-        default:
-            AssertMsgFailed(("enmType=%d\n", pMemToMapOs2->Core.enmType));
-            return VERR_INTERNAL_ERROR;
-    }
-
-    /*
-     * Create a dummy mapping object for it.
-     *
-     * All mappings are read/write/execute in OS/2 and there isn't
-     * any cache options, so sharing is ok. And the main memory object
-     * isn't actually freed until all the mappings have been freed up
-     * (reference counting).
-     */
-    PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(RT_OFFSETOF(RTR0MEMOBJOS2, Lock), RTR0MEMOBJTYPE_MAPPING, pvR0, pMemToMapOs2->Core.cb);
-    if (pMemFreeBSD)
-    {
-        pMemFreeBSD->Core.u.Mapping.R0Process = NIL_RTR0PROCESS;
-        *ppMem = &pMemFreeBSD->Core;
-        return VINF_SUCCESS;
-    }
-    return VERR_NO_MEMORY;
-#endif
     return VERR_NOT_IMPLEMENTED;
 }
 
@@ -618,10 +687,10 @@
     if (uAlignment > PAGE_SIZE)
         return VERR_NOT_SUPPORTED;
 
-    int             rc;
-    vm_object_t     pObjectToMap = ((PRTR0MEMOBJFREEBSD)pMemToMap)->pObject;
-    struct proc    *pProc     = (struct proc *)R0Process;
-    struct vm_map  *pProcMap  = &pProc->p_vmspace->vm_map;
+    int                rc;
+    PRTR0MEMOBJFREEBSD pMemToMapFreeBSD = (PRTR0MEMOBJFREEBSD)pMemToMap;
+    struct proc       *pProc            = (struct proc *)R0Process;
+    struct vm_map     *pProcMap         = &pProc->p_vmspace->vm_map;
 
     /* calc protection */
     vm_prot_t       ProtectionFlags = 0;
@@ -639,48 +708,57 @@
     vm_offset_t AddrR3 = round_page((vm_offset_t)pProc->p_vmspace->vm_daddr + lim_max(pProc, RLIMIT_DATA));
     PROC_UNLOCK(pProc);
 
-    vm_object_t pObjectNew = vm_object_allocate(OBJT_PHYS, pMemToMap->cb >> PAGE_SHIFT);
-    if (!RT_UNLIKELY(pObjectNew))
-        return VERR_NO_MEMORY;
-
     /* Insert the object in the map. */
     rc = vm_map_find(pProcMap,              /* Map to insert the object in */
-                        pObjectNew  ,          /* Object to map */
-                        0,                     /* Start offset in the object */
-                        &AddrR3,               /* Start address IN/OUT */
-                        pMemToMap->cb,         /* Size of the mapping */
-                        TRUE,                  /* Whether a suitable address should be searched for first */
-                        ProtectionFlags,       /* protection flags */
-                        VM_PROT_ALL,           /* Maximum protection flags */
-                        0);                    /* Copy on write */
+                     NULL,                  /* Object to map */
+                     0,                     /* Start offset in the object */
+                     &AddrR3,               /* Start address IN/OUT */
+                     pMemToMap->cb,         /* Size of the mapping */
+                     TRUE,                  /* Whether a suitable address should be searched for first */
+                     ProtectionFlags,       /* protection flags */
+                     VM_PROT_ALL,           /* Maximum protection flags */
+                     0);                    /* Copy on write */
 
     /* Map the memory page by page into the destination map. */
     if (rc == KERN_SUCCESS)
     {
-        size_t         cLeft        = pMemToMap->cb >> PAGE_SHIFT;
-        vm_offset_t    AddrToMap    = (vm_offset_t)pMemToMap->pv;
+        size_t         cPages       = pMemToMap->cb >> PAGE_SHIFT;;
         pmap_t         pPhysicalMap = pProcMap->pmap;
         vm_offset_t    AddrR3Dst    = AddrR3;
 
-        /* Insert the memory page by page into the mapping. */
-        while (cLeft-- > 0)
+        if (   pMemToMap->enmType == RTR0MEMOBJTYPE_PHYS
+            || pMemToMap->enmType == RTR0MEMOBJTYPE_PHYS_NC
+            || pMemToMap->enmType == RTR0MEMOBJTYPE_PAGE)
         {
-            vm_page_t Page = PHYS_TO_VM_PAGE(vtophys(AddrToMap));
+            /* Mapping physical allocations */
+            Assert(cPages == pMemToMapFreeBSD->u.Phys.cPages);
 
-#if __FreeBSD_version >= 701105
-            pmap_enter(pPhysicalMap, AddrR3Dst, VM_PROT_NONE, Page, ProtectionFlags, TRUE);
-#else
-            pmap_enter(pPhysicalMap, AddrR3Dst, Page, ProtectionFlags, TRUE);
-#endif
-            AddrToMap += PAGE_SIZE;
-            AddrR3Dst += PAGE_SIZE;
+            /* Insert the memory page by page into the mapping. */
+            for (uint32_t iPage = 0; iPage < cPages; iPage++)
+            {
+                vm_page_t pPage = pMemToMapFreeBSD->u.Phys.apPages[iPage];
+
+                MY_PMAP_ENTER(pPhysicalMap, AddrR3Dst, pPage, ProtectionFlags, TRUE);
+                AddrR3Dst += PAGE_SIZE;
+            }
         }
-        pObjectToMap = pObjectNew;
+        else
+        {
+            /* Mapping cont or low memory types */
+            vm_offset_t AddrToMap = (vm_offset_t)pMemToMap->pv;
+
+            for (uint32_t iPage = 0; iPage < cPages; iPage++)
+            {
+                vm_page_t pPage = PHYS_TO_VM_PAGE(vtophys(AddrToMap));
+
+                MY_PMAP_ENTER(pPhysicalMap, AddrR3Dst, pPage, ProtectionFlags, TRUE);
+                AddrR3Dst += PAGE_SIZE;
+                AddrToMap += PAGE_SIZE;
+            }
+        }
     }
-    else
-        vm_object_deallocate(pObjectNew);
 
-    if (rc == KERN_SUCCESS)
+    if (RT_SUCCESS(rc))
     {
         /*
          * Create a mapping object for it.
@@ -693,7 +771,6 @@
         {
             Assert((vm_offset_t)pMemFreeBSD->Core.pv == AddrR3);
             pMemFreeBSD->Core.u.Mapping.R0Process = R0Process;
-            pMemFreeBSD->pMappingObject = pObjectToMap;
             *ppMem = &pMemFreeBSD->Core;
             return VINF_SUCCESS;
         }
@@ -702,19 +779,33 @@
         AssertMsg(rc == KERN_SUCCESS, ("Deleting mapping failed\n"));
     }
 
-    if (pObjectToMap)
-        vm_object_deallocate(pObjectToMap);
-
     return VERR_NO_MEMORY;
 }
 
 
 int rtR0MemObjNativeProtect(PRTR0MEMOBJINTERNAL pMem, size_t offSub, size_t cbSub, uint32_t fProt)
 {
-    NOREF(pMem);
-    NOREF(offSub);
-    NOREF(cbSub);
-    NOREF(fProt);
+    vm_prot_t          ProtectionFlags = 0;
+    vm_offset_t        AddrStart       = (uintptr_t)pMem->pv + offSub;
+    vm_offset_t        AddrEnd         = AddrStart + cbSub;
+    vm_map_t           pVmMap          = rtR0MemObjFreeBSDGetMap(pMem);
+
+    if (!pVmMap)
+        return VERR_NOT_SUPPORTED;
+
+    if ((fProt & RTMEM_PROT_NONE) == RTMEM_PROT_NONE)
+        ProtectionFlags = VM_PROT_NONE;
+    if ((fProt & RTMEM_PROT_READ) == RTMEM_PROT_READ)
+        ProtectionFlags |= VM_PROT_READ;
+    if ((fProt & RTMEM_PROT_WRITE) == RTMEM_PROT_WRITE)
+        ProtectionFlags |= VM_PROT_WRITE;
+    if ((fProt & RTMEM_PROT_EXEC) == RTMEM_PROT_EXEC)
+        ProtectionFlags |= VM_PROT_EXECUTE;
+
+    int krc = vm_map_protect(pVmMap, AddrStart, AddrEnd, ProtectionFlags, FALSE);
+    if (krc == KERN_SUCCESS)
+        return VINF_SUCCESS;
+
     return VERR_NOT_SUPPORTED;
 }
 
@@ -726,17 +817,35 @@
     switch (pMemFreeBSD->Core.enmType)
     {
         case RTR0MEMOBJTYPE_LOCK:
+        {
             if (    pMemFreeBSD->Core.u.Lock.R0Process != NIL_RTR0PROCESS
                 &&  pMemFreeBSD->Core.u.Lock.R0Process != (RTR0PROCESS)curproc)
             {
                 /* later */
                 return NIL_RTHCPHYS;
             }
-            /* fall thru*/
-        case RTR0MEMOBJTYPE_PAGE:
+
+            vm_offset_t pb = (vm_offset_t)pMemFreeBSD->Core.pv + (iPage << PAGE_SHIFT);
+
+            struct proc    *pProc     = (struct proc *)pMemFreeBSD->Core.u.Lock.R0Process;
+            struct vm_map  *pProcMap  = &pProc->p_vmspace->vm_map;
+            pmap_t pPhysicalMap       = pProcMap->pmap;
+
+            return pmap_extract(pPhysicalMap, pb);
+        }
+
         case RTR0MEMOBJTYPE_MAPPING:
         {
-            uint8_t *pb = (uint8_t *)pMemFreeBSD->Core.pv + (iPage << PAGE_SHIFT);
+            vm_offset_t pb = (vm_offset_t)pMemFreeBSD->Core.pv + (iPage << PAGE_SHIFT);
+
+            if (pMemFreeBSD->Core.u.Mapping.R0Process != NIL_RTR0PROCESS)
+            {
+                struct proc    *pProc     = (struct proc *)pMemFreeBSD->Core.u.Mapping.R0Process;
+                struct vm_map  *pProcMap  = &pProc->p_vmspace->vm_map;
+                pmap_t pPhysicalMap       = pProcMap->pmap;
+
+                return pmap_extract(pPhysicalMap, pb);
+            }
             return vtophys(pb);
         }
 
@@ -746,7 +855,10 @@
         case RTR0MEMOBJTYPE_PHYS:
             return pMemFreeBSD->Core.u.Phys.PhysBase + (iPage << PAGE_SHIFT);
 
+        case RTR0MEMOBJTYPE_PAGE:
         case RTR0MEMOBJTYPE_PHYS_NC:
+            return VM_PAGE_TO_PHYS(pMemFreeBSD->u.Phys.apPages[iPage]);
+
         case RTR0MEMOBJTYPE_RES_VIRT:
         case RTR0MEMOBJTYPE_LOW:
         default:
