--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2025-04-11 12:12:39 UTC
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
@@ -139,8 +139,10 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
 
 DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)pMem;
     int rc;
+    vm_map_t pMap;
 
     switch (pMemFreeBSD->Core.enmType)
     {
@@ -155,9 +157,7 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
 
         case RTR0MEMOBJTYPE_LOCK:
         {
-            vm_map_t pMap = kernel_map;
-
-            if (pMemFreeBSD->Core.u.Lock.R0Process != NIL_RTR0PROCESS)
+            if (pMemFreeBSD->Core.u.Lock.R0Process != NIL_RTR0PROCESS) {
                 pMap = &((struct proc *)pMemFreeBSD->Core.u.Lock.R0Process)->p_vmspace->vm_map;
 
             rc = vm_map_unwire(pMap,
@@ -165,6 +165,7 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
                                (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb,
                                VM_MAP_WIRE_SYSTEM | VM_MAP_WIRE_NOHOLES);
             AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
+	   }
             break;
         }
 
@@ -197,6 +198,7 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
         case RTR0MEMOBJTYPE_PHYS_NC:
         {
             VM_OBJECT_WLOCK(pMemFreeBSD->pObject);
+#if __FreeBSD_version < 1500038
             vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
 #if __FreeBSD_version < 1000000
             vm_page_lock_queues();
@@ -210,6 +212,14 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
 #if __FreeBSD_version < 1000000
             vm_page_unlock_queues();
 #endif
+#else /* __FreeBSD_version >= 1500038 */
+            struct pctrie_iter pages;
+            vm_page_t page;
+
+            vm_page_iter_init(&pages, pMemFreeBSD->pObject);
+            VM_RADIX_FORALL(page, &pages)
+                (void)vm_page_unwire_noq(page);
+#endif
             VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
             vm_object_deallocate(pMemFreeBSD->pObject);
             break;
@@ -220,6 +230,7 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
             return VERR_INTERNAL_ERROR;
     }
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -329,7 +340,8 @@ static int rtR0MemObjFreeBSDAllocHelper(PRTR0MEMOBJFRE
     size_t      cPages = atop(pMemFreeBSD->Core.cb);
     int         rc;
 
-    pMemFreeBSD->pObject = vm_object_allocate(OBJT_PHYS, cPages);
+    pMemFreeBSD->pObject = vm_pager_allocate(OBJT_PHYS, NULL,
+            pMemFreeBSD->Core.cb, VM_PROT_ALL, 0, curthread->td_ucred);
 
     /* No additional object reference for auto-deallocation upon unmapping. */
 #if __FreeBSD_version >= 1000055
@@ -371,6 +383,7 @@ DECLHIDDEN(int) rtR0MemObjNativeAllocPage(PPRTR0MEMOBJ
 
 DECLHIDDEN(int) rtR0MemObjNativeAllocPage(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable, const char *pszTag)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_PAGE,
                                                                        NULL, cb, pszTag);
     if (pMemFreeBSD)
@@ -380,8 +393,10 @@ DECLHIDDEN(int) rtR0MemObjNativeAllocPage(PPRTR0MEMOBJ
             *ppMem = &pMemFreeBSD->Core;
         else
             rtR0MemObjDelete(&pMemFreeBSD->Core);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return rc;
     }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
@@ -395,6 +410,7 @@ DECLHIDDEN(int) rtR0MemObjNativeAllocLow(PPRTR0MEMOBJI
 
 DECLHIDDEN(int) rtR0MemObjNativeAllocLow(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable, const char *pszTag)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_LOW, NULL, cb, pszTag);
     if (pMemFreeBSD)
     {
@@ -403,14 +419,17 @@ DECLHIDDEN(int) rtR0MemObjNativeAllocLow(PPRTR0MEMOBJI
             *ppMem = &pMemFreeBSD->Core;
         else
             rtR0MemObjDelete(&pMemFreeBSD->Core);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return rc;
     }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
 
 DECLHIDDEN(int) rtR0MemObjNativeAllocCont(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable, const char *pszTag)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_CONT,
                                                                        NULL, cb, pszTag);
     if (pMemFreeBSD)
@@ -423,8 +442,10 @@ DECLHIDDEN(int) rtR0MemObjNativeAllocCont(PPRTR0MEMOBJ
         }
         else
             rtR0MemObjDelete(&pMemFreeBSD->Core);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return rc;
     }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
@@ -432,6 +453,7 @@ static int rtR0MemObjFreeBSDAllocPhysPages(PPRTR0MEMOB
 static int rtR0MemObjFreeBSDAllocPhysPages(PPRTR0MEMOBJINTERNAL ppMem, RTR0MEMOBJTYPE enmType, size_t cb,  RTHCPHYS PhysHighest,
                                            size_t uAlignment, bool fContiguous, int rcNoMem, const char *pszTag)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     /* create the object. */
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), enmType, NULL, cb, pszTag);
     if (pMemFreeBSD)
@@ -439,7 +461,8 @@ static int rtR0MemObjFreeBSDAllocPhysPages(PPRTR0MEMOB
         vm_paddr_t const VmPhysAddrHigh = PhysHighest != NIL_RTHCPHYS ? PhysHighest : ~(vm_paddr_t)0;
         u_long const     cPages         = atop(cb);
 
-        pMemFreeBSD->pObject = vm_object_allocate(OBJT_PHYS, cPages);
+        pMemFreeBSD->pObject = vm_pager_allocate(OBJT_PHYS, NULL,
+            pMemFreeBSD->Core.cb, VM_PROT_ALL, 0, curthread->td_ucred);
 
         int rc = rtR0MemObjFreeBSDPhysAllocHelper(pMemFreeBSD->pObject, cPages, VmPhysAddrHigh,
                                                   uAlignment, fContiguous, true, rcNoMem);
@@ -449,7 +472,7 @@ static int rtR0MemObjFreeBSDAllocPhysPages(PPRTR0MEMOB
             {
                 Assert(enmType == RTR0MEMOBJTYPE_PHYS);
                 VM_OBJECT_WLOCK(pMemFreeBSD->pObject);
-                pMemFreeBSD->Core.u.Phys.PhysBase = VM_PAGE_TO_PHYS(vm_page_find_least(pMemFreeBSD->pObject, 0));
+                pMemFreeBSD->Core.u.Phys.PhysBase = VM_PAGE_TO_PHYS(vm_radix_lookup_ge(&pMemFreeBSD->pObject->rtree, 0));
                 VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
                 pMemFreeBSD->Core.u.Phys.fAllocated = true;
             }
@@ -462,8 +485,10 @@ static int rtR0MemObjFreeBSDAllocPhysPages(PPRTR0MEMOB
             vm_object_deallocate(pMemFreeBSD->pObject);
             rtR0MemObjDelete(&pMemFreeBSD->Core);
         }
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return rc;
     }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
@@ -486,6 +511,7 @@ DECLHIDDEN(int) rtR0MemObjNativeEnterPhys(PPRTR0MEMOBJ
                                           const char *pszTag)
 {
     AssertReturn(uCachePolicy == RTMEM_CACHE_POLICY_DONT_CARE, VERR_NOT_SUPPORTED);
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     /* create the object. */
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_PHYS,
@@ -497,8 +523,10 @@ DECLHIDDEN(int) rtR0MemObjNativeEnterPhys(PPRTR0MEMOBJ
         pMemFreeBSD->Core.u.Phys.PhysBase = Phys;
         pMemFreeBSD->Core.u.Phys.uCachePolicy = uCachePolicy;
         *ppMem = &pMemFreeBSD->Core;
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VINF_SUCCESS;
     }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
@@ -510,6 +538,7 @@ static int rtR0MemObjNativeLockInMap(PPRTR0MEMOBJINTER
                                      vm_offset_t AddrStart, size_t cb, uint32_t fAccess,
                                      RTR0PROCESS R0Process, int fFlags, const char *pszTag)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc;
     NOREF(fAccess);
 
@@ -519,21 +548,28 @@ static int rtR0MemObjNativeLockInMap(PPRTR0MEMOBJINTER
     if (!pMemFreeBSD)
         return VERR_NO_MEMORY;
 
-    /*
-     * We could've used vslock here, but we don't wish to be subject to
-     * resource usage restrictions, so we'll call vm_map_wire directly.
-     */
-    rc = vm_map_wire(pVmMap,                                         /* the map */
-                     AddrStart,                                      /* start */
-                     AddrStart + cb,                                 /* end */
-                     fFlags);                                        /* flags */
+    if (pVmMap != kernel_map) {
+        /*
+         * We could've used vslock here, but we don't wish to be subject to
+         * resource usage restrictions, so we'll call vm_map_wire directly.
+         */
+        rc = vm_map_wire(pVmMap,                                         /* the map */
+                         AddrStart,                                      /* start */
+                         AddrStart + cb,                                 /* end */
+                         fFlags);                                        /* flags */
+    }
+    else
+        rc = KERN_SUCCESS;
+
     if (rc == KERN_SUCCESS)
     {
         pMemFreeBSD->Core.u.Lock.R0Process = R0Process;
         *ppMem = &pMemFreeBSD->Core;
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VINF_SUCCESS;
     }
     rtR0MemObjDelete(&pMemFreeBSD->Core);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;/** @todo fix mach -> vbox error conversion for freebsd. */
 }
 
@@ -573,6 +609,7 @@ static int rtR0MemObjNativeReserveInMap(PPRTR0MEMOBJIN
 static int rtR0MemObjNativeReserveInMap(PPRTR0MEMOBJINTERNAL ppMem, void *pvFixed, size_t cb, size_t uAlignment,
                                         RTR0PROCESS R0Process, vm_map_t pMap, const char *pszTag)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc;
 
     /*
@@ -631,11 +668,13 @@ static int rtR0MemObjNativeReserveInMap(PPRTR0MEMOBJIN
         pMemFreeBSD->Core.pv = (void *)MapAddress;
         pMemFreeBSD->Core.u.ResVirt.R0Process = R0Process;
         *ppMem = &pMemFreeBSD->Core;
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VINF_SUCCESS;
     }
 
     rc = VERR_NO_MEMORY; /** @todo fix translation (borrow from darwin) */
     rtR0MemObjDelete(&pMemFreeBSD->Core);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 
 }
@@ -659,6 +698,8 @@ DECLHIDDEN(int) rtR0MemObjNativeMapKernel(PPRTR0MEMOBJ
 DECLHIDDEN(int) rtR0MemObjNativeMapKernel(PPRTR0MEMOBJINTERNAL ppMem, RTR0MEMOBJ pMemToMap, void *pvFixed, size_t uAlignment,
                                           unsigned fProt, size_t offSub, size_t cbSub, const char *pszTag)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
 //  AssertMsgReturn(!offSub && !cbSub, ("%#x %#x\n", offSub, cbSub), VERR_NOT_SUPPORTED);
     AssertMsgReturn(pvFixed == (void *)-1, ("%p\n", pvFixed), VERR_NOT_SUPPORTED);
 
@@ -713,6 +754,7 @@ DECLHIDDEN(int) rtR0MemObjNativeMapKernel(PPRTR0MEMOBJ
             Assert((vm_offset_t)pMemFreeBSD->Core.pv == Addr);
             pMemFreeBSD->Core.u.Mapping.R0Process = NIL_RTR0PROCESS;
             *ppMem = &pMemFreeBSD->Core;
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VINF_SUCCESS;
         }
         rc = vm_map_remove(kernel_map, Addr, Addr + cbSub);
@@ -721,6 +763,7 @@ DECLHIDDEN(int) rtR0MemObjNativeMapKernel(PPRTR0MEMOBJ
     else
         vm_object_deallocate(pMemToMapFreeBSD->pObject);
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
@@ -728,6 +771,8 @@ DECLHIDDEN(int) rtR0MemObjNativeMapUser(PPRTR0MEMOBJIN
 DECLHIDDEN(int) rtR0MemObjNativeMapUser(PPRTR0MEMOBJINTERNAL ppMem, RTR0MEMOBJ pMemToMap, RTR3PTR R3PtrFixed, size_t uAlignment,
                                         unsigned fProt, RTR0PROCESS R0Process, size_t offSub, size_t cbSub, const char *pszTag)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     /*
      * Check for unsupported stuff.
      */
@@ -785,44 +830,50 @@ DECLHIDDEN(int) rtR0MemObjNativeMapUser(PPRTR0MEMOBJIN
 
     if (rc == KERN_SUCCESS)
     {
-        rc = vm_map_wire(pProcMap, AddrR3, AddrR3 + pMemToMap->cb, VM_MAP_WIRE_USER|VM_MAP_WIRE_NOHOLES);
+        rc = vm_map_wire(pProcMap, AddrR3, AddrR3 + cbSub, VM_MAP_WIRE_USER|VM_MAP_WIRE_NOHOLES);
         AssertMsg(rc == KERN_SUCCESS, ("%#x\n", rc));
 
-        rc = vm_map_inherit(pProcMap, AddrR3, AddrR3 + pMemToMap->cb, VM_INHERIT_SHARE);
+        rc = vm_map_inherit(pProcMap, AddrR3, AddrR3 + cbSub, VM_INHERIT_SHARE);
         AssertMsg(rc == KERN_SUCCESS, ("%#x\n", rc));
 
         /*
          * Create a mapping object for it.
          */
         PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(RTR0MEMOBJFREEBSD), RTR0MEMOBJTYPE_MAPPING,
-                                                                           (void *)AddrR3, pMemToMap->cb, pszTag);
+                                                                           (void *)AddrR3, cbSub, pszTag);
         if (pMemFreeBSD)
         {
             Assert((vm_offset_t)pMemFreeBSD->Core.pv == AddrR3);
             pMemFreeBSD->Core.u.Mapping.R0Process = R0Process;
             *ppMem = &pMemFreeBSD->Core;
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VINF_SUCCESS;
         }
 
-        rc = vm_map_remove(pProcMap, AddrR3, AddrR3 + pMemToMap->cb);
+        rc = vm_map_remove(pProcMap, AddrR3, AddrR3 + cbSub);
         AssertMsg(rc == KERN_SUCCESS, ("Deleting mapping failed\n"));
     }
     else
         vm_object_deallocate(pMemToMapFreeBSD->pObject);
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
 
 DECLHIDDEN(int) rtR0MemObjNativeProtect(PRTR0MEMOBJINTERNAL pMem, size_t offSub, size_t cbSub, uint32_t fProt)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     vm_prot_t          ProtectionFlags = 0;
     vm_offset_t        AddrStart       = (uintptr_t)pMem->pv + offSub;
     vm_offset_t        AddrEnd         = AddrStart + cbSub;
     vm_map_t           pVmMap          = rtR0MemObjFreeBSDGetMap(pMem);
 
     if (!pVmMap)
+    {
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VERR_NOT_SUPPORTED;
+    }
 
     if ((fProt & RTMEM_PROT_NONE) == RTMEM_PROT_NONE)
         ProtectionFlags = VM_PROT_NONE;
@@ -833,7 +884,12 @@ DECLHIDDEN(int) rtR0MemObjNativeProtect(PRTR0MEMOBJINT
     if ((fProt & RTMEM_PROT_EXEC) == RTMEM_PROT_EXEC)
         ProtectionFlags |= VM_PROT_EXECUTE;
 
+#if __FreeBSD_version >= 1300135
+    int krc = vm_map_protect(pVmMap, AddrStart, AddrEnd, ProtectionFlags, 0, VM_MAP_PROTECT_SET_PROT);
+#else
     int krc = vm_map_protect(pVmMap, AddrStart, AddrEnd, ProtectionFlags, FALSE);
+#endif
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     if (krc == KERN_SUCCESS)
         return VINF_SUCCESS;
 
@@ -858,11 +914,19 @@ DECLHIDDEN(RTHCPHYS) rtR0MemObjNativeGetPagePhysAddr(P
 
             vm_offset_t pb = (vm_offset_t)pMemFreeBSD->Core.pv + ptoa(iPage);
 
-            struct proc    *pProc     = (struct proc *)pMemFreeBSD->Core.u.Lock.R0Process;
-            struct vm_map  *pProcMap  = &pProc->p_vmspace->vm_map;
-            pmap_t pPhysicalMap       = vm_map_pmap(pProcMap);
+            if (pMemFreeBSD->Core.u.Mapping.R0Process != NIL_RTR0PROCESS)
+            {
+                RTHCPHYS addr;
+                IPRT_FREEBSD_SAVE_EFL_AC();
+                struct proc    *pProc     = (struct proc *)pMemFreeBSD->Core.u.Lock.R0Process;
+                struct vm_map  *pProcMap  = &pProc->p_vmspace->vm_map;
+                pmap_t pPhysicalMap       = vm_map_pmap(pProcMap);
 
-            return pmap_extract(pPhysicalMap, pb);
+                addr =  pmap_extract(pPhysicalMap, pb);
+                IPRT_FREEBSD_RESTORE_EFL_AC();
+                return addr;
+            }
+            return vtophys(pb);
         }
 
         case RTR0MEMOBJTYPE_MAPPING:
@@ -871,11 +935,15 @@ DECLHIDDEN(RTHCPHYS) rtR0MemObjNativeGetPagePhysAddr(P
 
             if (pMemFreeBSD->Core.u.Mapping.R0Process != NIL_RTR0PROCESS)
             {
+                RTHCPHYS addr;
+                IPRT_FREEBSD_SAVE_EFL_AC();
                 struct proc    *pProc     = (struct proc *)pMemFreeBSD->Core.u.Mapping.R0Process;
                 struct vm_map  *pProcMap  = &pProc->p_vmspace->vm_map;
                 pmap_t pPhysicalMap       = vm_map_pmap(pProcMap);
 
-                return pmap_extract(pPhysicalMap, pb);
+                addr =  pmap_extract(pPhysicalMap, pb);
+                IPRT_FREEBSD_RESTORE_EFL_AC();
+                return addr;
             }
             return vtophys(pb);
         }
@@ -886,9 +954,11 @@ DECLHIDDEN(RTHCPHYS) rtR0MemObjNativeGetPagePhysAddr(P
         {
             RTHCPHYS addr;
 
+            IPRT_FREEBSD_SAVE_EFL_AC();
             VM_OBJECT_WLOCK(pMemFreeBSD->pObject);
             addr = VM_PAGE_TO_PHYS(vm_page_lookup(pMemFreeBSD->pObject, iPage));
             VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return addr;
         }
 
