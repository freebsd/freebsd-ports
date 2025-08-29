--- src/VBox/Runtime/r0drv/freebsd/semfastmutex-r0drv-freebsd.c.orig	2021-01-07 15:42:08 UTC
+++ src/VBox/Runtime/r0drv/freebsd/semfastmutex-r0drv-freebsd.c
@@ -86,6 +86,7 @@ RTDECL(int)  RTSemFastMutexCreate(PRTSEMFASTMUTEX phFa
 {
     AssertCompile(sizeof(RTSEMFASTMUTEXINTERNAL) > sizeof(void *));
     AssertPtrReturn(phFastMtx, VERR_INVALID_POINTER);
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     PRTSEMFASTMUTEXINTERNAL pThis = (PRTSEMFASTMUTEXINTERNAL)RTMemAllocZ(sizeof(*pThis));
     if (pThis)
@@ -94,8 +95,10 @@ RTDECL(int)  RTSemFastMutexCreate(PRTSEMFASTMUTEX phFa
         sx_init_flags(&pThis->SxLock, "IPRT Fast Mutex Semaphore", SX_DUPOK);
 
         *phFastMtx = pThis;
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VINF_SUCCESS;
     }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
@@ -107,11 +110,13 @@ RTDECL(int)  RTSemFastMutexDestroy(RTSEMFASTMUTEX hFas
         return VINF_SUCCESS;
     AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
     AssertMsgReturn(pThis->u32Magic == RTSEMFASTMUTEX_MAGIC, ("%p: u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_HANDLE);
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     ASMAtomicWriteU32(&pThis->u32Magic, RTSEMFASTMUTEX_MAGIC_DEAD);
     sx_destroy(&pThis->SxLock);
     RTMemFree(pThis);
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -121,8 +126,11 @@ RTDECL(int)  RTSemFastMutexRequest(RTSEMFASTMUTEX hFas
     PRTSEMFASTMUTEXINTERNAL pThis = hFastMtx;
     AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
     AssertMsgReturn(pThis->u32Magic == RTSEMFASTMUTEX_MAGIC, ("%p: u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_HANDLE);
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     sx_xlock(&pThis->SxLock);
+
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -132,8 +140,11 @@ RTDECL(int)  RTSemFastMutexRelease(RTSEMFASTMUTEX hFas
     PRTSEMFASTMUTEXINTERNAL pThis = hFastMtx;
     AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
     AssertMsgReturn(pThis->u32Magic == RTSEMFASTMUTEX_MAGIC, ("%p: u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_HANDLE);
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     sx_xunlock(&pThis->SxLock);
+
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
