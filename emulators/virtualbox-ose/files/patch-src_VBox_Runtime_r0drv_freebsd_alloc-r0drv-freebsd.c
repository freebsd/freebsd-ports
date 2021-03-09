--- src/VBox/Runtime/r0drv/freebsd/alloc-r0drv-freebsd.c.orig	2021-01-07 15:42:08 UTC
+++ src/VBox/Runtime/r0drv/freebsd/alloc-r0drv-freebsd.c
@@ -78,6 +78,7 @@ MALLOC_DEFINE(M_IPRTCONT, "iprtcont", "IPRT - contiguo
 
 DECLHIDDEN(int) rtR0MemAllocEx(size_t cb, uint32_t fFlags, PRTMEMHDR *ppHdr)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     size_t      cbAllocated = cb;
     PRTMEMHDR   pHdr        = NULL;
 
@@ -100,8 +101,10 @@ DECLHIDDEN(int) rtR0MemAllocEx(size_t cb, uint32_t fFl
         cbAllocated = RT_ALIGN_Z(cb + sizeof(*pHdr), PAGE_SIZE);
 
         pVmObject = vm_object_allocate(OBJT_DEFAULT, cbAllocated >> PAGE_SHIFT);
-        if (!pVmObject)
+        if (!pVmObject) {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VERR_NO_EXEC_MEMORY;
+        }
 
         /* Addr contains a start address vm_map_find will start searching for suitable space at. */
 #if __FreeBSD_version >= 1000055
@@ -138,6 +141,8 @@ DECLHIDDEN(int) rtR0MemAllocEx(size_t cb, uint32_t fFl
                                  fFlags & RTMEMHDR_FLAG_ZEROED ? M_NOWAIT | M_ZERO : M_NOWAIT);
     }
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
+
     if (RT_UNLIKELY(!pHdr))
         return VERR_NO_MEMORY;
 
@@ -153,6 +158,8 @@ DECLHIDDEN(int) rtR0MemAllocEx(size_t cb, uint32_t fFl
 
 DECLHIDDEN(void) rtR0MemFree(PRTMEMHDR pHdr)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     pHdr->u32Magic += 1;
 
 #ifdef RT_ARCH_AMD64
@@ -165,11 +172,14 @@ DECLHIDDEN(void) rtR0MemFree(PRTMEMHDR pHdr)
     else
 #endif
         free(pHdr, M_IPRTHEAP);
+
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 
 RTR0DECL(void *) RTMemContAlloc(PRTCCPHYS pPhys, size_t cb)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     void *pv;
 
     /*
@@ -194,6 +204,7 @@ RTR0DECL(void *) RTMemContAlloc(PRTCCPHYS pPhys, size_
         *pPhys = vtophys(pv);
         Assert(!(*pPhys & PAGE_OFFSET_MASK));
     }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return pv;
 }
 
@@ -203,7 +214,9 @@ RTR0DECL(void) RTMemContFree(void *pv, size_t cb)
     if (pv)
     {
         AssertMsg(!((uintptr_t)pv & PAGE_OFFSET_MASK), ("pv=%p\n", pv));
+        IPRT_FREEBSD_SAVE_EFL_AC();
         contigfree(pv, cb, M_IPRTCONT);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
     }
 }
 
