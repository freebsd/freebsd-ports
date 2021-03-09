--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2020-10-16 16:38:10 UTC
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
@@ -129,6 +129,7 @@ static vm_map_t rtR0MemObjFreeBSDGetMap(PRTR0MEMOBJINT
 
 DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)pMem;
     int rc;
 
@@ -145,16 +146,15 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
 
         case RTR0MEMOBJTYPE_LOCK:
         {
-            vm_map_t pMap = kernel_map;
+            if (pMemFreeBSD->Core.u.Lock.R0Process != NIL_RTR0PROCESS) {
+                vm_map_t pMap = &((struct proc *)pMemFreeBSD->Core.u.Lock.R0Process)->p_vmspace->vm_map;
 
-            if (pMemFreeBSD->Core.u.Lock.R0Process != NIL_RTR0PROCESS)
-                pMap = &((struct proc *)pMemFreeBSD->Core.u.Lock.R0Process)->p_vmspace->vm_map;
-
-            rc = vm_map_unwire(pMap,
+                rc = vm_map_unwire(pMap,
                                (vm_offset_t)pMemFreeBSD->Core.pv,
                                (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb,
                                VM_MAP_WIRE_SYSTEM | VM_MAP_WIRE_NOHOLES);
-            AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
+                AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
+            }
             break;
         }
 
@@ -210,6 +210,7 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
             return VERR_INTERNAL_ERROR;
     }
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -320,7 +321,8 @@ static int rtR0MemObjFreeBSDAllocHelper(PRTR0MEMOBJFRE
     size_t      cPages = atop(pMemFreeBSD->Core.cb);
     int         rc;
 
-    pMemFreeBSD->pObject = vm_object_allocate(OBJT_PHYS, cPages);
+    pMemFreeBSD->pObject = vm_pager_allocate(OBJT_PHYS, NULL,
+            pMemFreeBSD->Core.cb, VM_PROT_ALL, 0, curthread->td_ucred);
 
     /* No additional object reference for auto-deallocation upon unmapping. */
 #if __FreeBSD_version >= 1000055
@@ -361,58 +363,77 @@ static int rtR0MemObjFreeBSDAllocHelper(PRTR0MEMOBJFRE
 }
 DECLHIDDEN(int) rtR0MemObjNativeAllocPage(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD),
                                                                        RTR0MEMOBJTYPE_PAGE, NULL, cb);
     if (!pMemFreeBSD)
+    {
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VERR_NO_MEMORY;
+    }
 
     int rc = rtR0MemObjFreeBSDAllocHelper(pMemFreeBSD, fExecutable, ~(vm_paddr_t)0, false, VERR_NO_MEMORY);
     if (RT_FAILURE(rc))
     {
         rtR0MemObjDelete(&pMemFreeBSD->Core);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return rc;
     }
 
     *ppMem = &pMemFreeBSD->Core;
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 }
 
 
 DECLHIDDEN(int) rtR0MemObjNativeAllocLow(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD),
                                                                        RTR0MEMOBJTYPE_LOW, NULL, cb);
     if (!pMemFreeBSD)
+    {
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VERR_NO_MEMORY;
+    }
 
     int rc = rtR0MemObjFreeBSDAllocHelper(pMemFreeBSD, fExecutable, _4G - 1, false, VERR_NO_LOW_MEMORY);
     if (RT_FAILURE(rc))
     {
         rtR0MemObjDelete(&pMemFreeBSD->Core);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return rc;
     }
 
     *ppMem = &pMemFreeBSD->Core;
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 }
 
 
 DECLHIDDEN(int) rtR0MemObjNativeAllocCont(PPRTR0MEMOBJINTERNAL ppMem, size_t cb, bool fExecutable)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD),
                                                                        RTR0MEMOBJTYPE_CONT, NULL, cb);
     if (!pMemFreeBSD)
+    {
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VERR_NO_MEMORY;
+    }
 
     int rc = rtR0MemObjFreeBSDAllocHelper(pMemFreeBSD, fExecutable, _4G - 1, true, VERR_NO_CONT_MEMORY);
     if (RT_FAILURE(rc))
     {
         rtR0MemObjDelete(&pMemFreeBSD->Core);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return rc;
     }
 
     pMemFreeBSD->Core.u.Cont.Phys = vtophys(pMemFreeBSD->Core.pv);
     *ppMem = &pMemFreeBSD->Core;
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 }
 
@@ -422,6 +443,7 @@ static int rtR0MemObjFreeBSDAllocPhysPages(PPRTR0MEMOB
                                            RTHCPHYS PhysHighest, size_t uAlignment,
                                            bool fContiguous, int rcNoMem)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     uint32_t   cPages = atop(cb);
     vm_paddr_t VmPhysAddrHigh;
 
@@ -429,9 +451,13 @@ static int rtR0MemObjFreeBSDAllocPhysPages(PPRTR0MEMOB
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD),
                                                                        enmType, NULL, cb);
     if (!pMemFreeBSD)
+    {
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VERR_NO_MEMORY;
+    }
 
-    pMemFreeBSD->pObject = vm_object_allocate(OBJT_PHYS, atop(cb));
+    pMemFreeBSD->pObject = vm_pager_allocate(OBJT_PHYS, NULL,
+            pMemFreeBSD->Core.cb, VM_PROT_ALL, 0, curthread->td_ucred);
 
     if (PhysHighest != NIL_RTHCPHYS)
         VmPhysAddrHigh = PhysHighest;
@@ -459,6 +485,7 @@ static int rtR0MemObjFreeBSDAllocPhysPages(PPRTR0MEMOB
         rtR0MemObjDelete(&pMemFreeBSD->Core);
     }
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 }
 
@@ -478,17 +505,22 @@ DECLHIDDEN(int) rtR0MemObjNativeAllocPhysNC(PPRTR0MEMO
 DECLHIDDEN(int) rtR0MemObjNativeEnterPhys(PPRTR0MEMOBJINTERNAL ppMem, RTHCPHYS Phys, size_t cb, uint32_t uCachePolicy)
 {
     AssertReturn(uCachePolicy == RTMEM_CACHE_POLICY_DONT_CARE, VERR_NOT_SUPPORTED);
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     /* create the object. */
     PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(*pMemFreeBSD), RTR0MEMOBJTYPE_PHYS, NULL, cb);
     if (!pMemFreeBSD)
+    {
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VERR_NO_MEMORY;
+    }
 
     /* there is no allocation here, it needs to be mapped somewhere first. */
     pMemFreeBSD->Core.u.Phys.fAllocated = false;
     pMemFreeBSD->Core.u.Phys.PhysBase = Phys;
     pMemFreeBSD->Core.u.Phys.uCachePolicy = uCachePolicy;
     *ppMem = &pMemFreeBSD->Core;
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -500,6 +532,7 @@ static int rtR0MemObjNativeLockInMap(PPRTR0MEMOBJINTER
                                      vm_offset_t AddrStart, size_t cb, uint32_t fAccess,
                                      RTR0PROCESS R0Process, int fFlags)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc;
     NOREF(fAccess);
 
@@ -508,21 +541,28 @@ static int rtR0MemObjNativeLockInMap(PPRTR0MEMOBJINTER
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
 
@@ -558,6 +598,7 @@ DECLHIDDEN(int) rtR0MemObjNativeLockKernel(PPRTR0MEMOB
  */
 static int rtR0MemObjNativeReserveInMap(PPRTR0MEMOBJINTERNAL ppMem, void *pvFixed, size_t cb, size_t uAlignment, RTR0PROCESS R0Process, vm_map_t pMap)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc;
 
     /*
@@ -615,11 +656,13 @@ static int rtR0MemObjNativeReserveInMap(PPRTR0MEMOBJIN
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
@@ -641,6 +684,8 @@ DECLHIDDEN(int) rtR0MemObjNativeReserveUser(PPRTR0MEMO
 DECLHIDDEN(int) rtR0MemObjNativeMapKernel(PPRTR0MEMOBJINTERNAL ppMem, RTR0MEMOBJ pMemToMap, void *pvFixed, size_t uAlignment,
                                           unsigned fProt, size_t offSub, size_t cbSub)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
 //  AssertMsgReturn(!offSub && !cbSub, ("%#x %#x\n", offSub, cbSub), VERR_NOT_SUPPORTED);
     AssertMsgReturn(pvFixed == (void *)-1, ("%p\n", pvFixed), VERR_NOT_SUPPORTED);
 
@@ -697,6 +742,7 @@ DECLHIDDEN(int) rtR0MemObjNativeMapKernel(PPRTR0MEMOBJ
             Assert((vm_offset_t)pMemFreeBSD->Core.pv == Addr);
             pMemFreeBSD->Core.u.Mapping.R0Process = NIL_RTR0PROCESS;
             *ppMem = &pMemFreeBSD->Core;
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VINF_SUCCESS;
         }
         rc = vm_map_remove(kernel_map, Addr, Addr + cbSub);
@@ -705,6 +751,7 @@ DECLHIDDEN(int) rtR0MemObjNativeMapKernel(PPRTR0MEMOBJ
     else
         vm_object_deallocate(pMemToMapFreeBSD->pObject);
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
@@ -712,6 +759,8 @@ DECLHIDDEN(int) rtR0MemObjNativeMapKernel(PPRTR0MEMOBJ
 DECLHIDDEN(int) rtR0MemObjNativeMapUser(PPRTR0MEMOBJINTERNAL ppMem, RTR0MEMOBJ pMemToMap, RTR3PTR R3PtrFixed, size_t uAlignment,
                                         unsigned fProt, RTR0PROCESS R0Process, size_t offSub, size_t cbSub)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     /*
      * Check for unsupported stuff.
      */
@@ -768,47 +817,53 @@ DECLHIDDEN(int) rtR0MemObjNativeMapUser(PPRTR0MEMOBJIN
                      0);                    /* copy-on-write and similar flags */
 
     if (rc == KERN_SUCCESS)
+        rc = vm_map_wire(pProcMap, AddrR3, AddrR3 + cbSub, VM_MAP_WIRE_USER|VM_MAP_WIRE_NOHOLES);
+    if (rc == KERN_SUCCESS)
     {
-        rc = vm_map_wire(pProcMap, AddrR3, AddrR3 + pMemToMap->cb, VM_MAP_WIRE_USER|VM_MAP_WIRE_NOHOLES);
+        rc = vm_map_inherit(pProcMap, AddrR3, AddrR3 + cbSub, VM_INHERIT_SHARE);
         AssertMsg(rc == KERN_SUCCESS, ("%#x\n", rc));
 
-        rc = vm_map_inherit(pProcMap, AddrR3, AddrR3 + pMemToMap->cb, VM_INHERIT_SHARE);
-        AssertMsg(rc == KERN_SUCCESS, ("%#x\n", rc));
-
         /*
          * Create a mapping object for it.
          */
         PRTR0MEMOBJFREEBSD pMemFreeBSD = (PRTR0MEMOBJFREEBSD)rtR0MemObjNew(sizeof(RTR0MEMOBJFREEBSD),
                                                                            RTR0MEMOBJTYPE_MAPPING,
                                                                            (void *)AddrR3,
-                                                                           pMemToMap->cb);
+                                                                           cbSub);
         if (pMemFreeBSD)
         {
             Assert((vm_offset_t)pMemFreeBSD->Core.pv == AddrR3);
             pMemFreeBSD->Core.u.Mapping.R0Process = R0Process;
             *ppMem = &pMemFreeBSD->Core;
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VINF_SUCCESS;
         }
 
-        rc = vm_map_remove(pProcMap, AddrR3, AddrR3 + pMemToMap->cb);
+        rc = vm_map_remove(pProcMap, AddrR3, AddrR3 + cbSub /* XXX pMemToMap->cb*/ );
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
+
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
@@ -819,7 +874,12 @@ DECLHIDDEN(int) rtR0MemObjNativeProtect(PRTR0MEMOBJINT
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
 
@@ -844,11 +904,19 @@ DECLHIDDEN(RTHCPHYS) rtR0MemObjNativeGetPagePhysAddr(P
 
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
@@ -857,11 +925,15 @@ DECLHIDDEN(RTHCPHYS) rtR0MemObjNativeGetPagePhysAddr(P
 
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
@@ -872,9 +944,11 @@ DECLHIDDEN(RTHCPHYS) rtR0MemObjNativeGetPagePhysAddr(P
         {
             RTHCPHYS addr;
 
+            IPRT_FREEBSD_SAVE_EFL_AC();
             VM_OBJECT_WLOCK(pMemFreeBSD->pObject);
             addr = VM_PAGE_TO_PHYS(vm_page_lookup(pMemFreeBSD->pObject, iPage));
             VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return addr;
         }
 
