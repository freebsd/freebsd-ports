--- src/VBox/Runtime/r0drv/freebsd/alloc-r0drv-freebsd.c.orig	2024-10-10 20:32:14.000000000 +0200
+++ src/VBox/Runtime/r0drv/freebsd/alloc-r0drv-freebsd.c	2024-12-27 13:39:49.059878000 +0100
@@ -88,6 +88,7 @@
 
 DECLHIDDEN(int) rtR0MemAllocEx(size_t cb, uint32_t fFlags, PRTMEMHDR *ppHdr)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     size_t      cbAllocated = cb;
     PRTMEMHDR   pHdr        = (PRTMEMHDR)malloc(cb + sizeof(RTMEMHDR), M_IPRTHEAP,
                                                 fFlags & RTMEMHDR_FLAG_ZEROED ? M_NOWAIT | M_ZERO : M_NOWAIT);
@@ -99,21 +100,28 @@
         pHdr->cbReq      = cb;
 
         *ppHdr = pHdr;
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VINF_SUCCESS;
-    }
+    } 
+	
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
 
 DECLHIDDEN(void) rtR0MemFree(PRTMEMHDR pHdr)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     pHdr->u32Magic += 1;
     free(pHdr, M_IPRTHEAP);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 
 RTR0DECL(void *) RTMemContAlloc(PRTCCPHYS pPhys, size_t cb)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     void *pv;
 
     /*
@@ -138,6 +146,7 @@
         *pPhys = vtophys(pv);
         Assert(!(*pPhys & PAGE_OFFSET_MASK));
     }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return pv;
 }
 
@@ -147,7 +156,9 @@
     if (pv)
     {
         AssertMsg(!((uintptr_t)pv & PAGE_OFFSET_MASK), ("pv=%p\n", pv));
+        IPRT_FREEBSD_SAVE_EFL_AC();
         contigfree(pv, cb, M_IPRTCONT);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
     }
 }
 
