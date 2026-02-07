--- src/VBox/Runtime/r0drv/freebsd/semevent-r0drv-freebsd.c.orig	2018-10-15 14:31:31 UTC
+++ src/VBox/Runtime/r0drv/freebsd/semevent-r0drv-freebsd.c
@@ -77,7 +77,9 @@ RTDECL(int)  RTSemEventCreateEx(PRTSEMEVENT phEventSem
     Assert(!(fFlags & RTSEMEVENT_FLAGS_BOOTSTRAP_HACK) || (fFlags & RTSEMEVENT_FLAGS_NO_LOCK_VAL));
     AssertPtrReturn(phEventSem, VERR_INVALID_POINTER);
 
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTSEMEVENTINTERNAL pThis = (PRTSEMEVENTINTERNAL)RTMemAllocZ(sizeof(*pThis));
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     if (!pThis)
         return VERR_NO_MEMORY;
 
@@ -128,10 +130,12 @@ RTDECL(int)  RTSemEventDestroy(RTSEMEVENT hEventSem)
     /*
      * Invalidate it and signal the object just in case.
      */
+    IPRT_FREEBSD_SAVE_EFL_AC();
     ASMAtomicWriteU32(&pThis->u32Magic, ~RTSEMEVENT_MAGIC);
     ASMAtomicWriteU32(&pThis->fState, 0);
     rtR0SemBsdBroadcast(pThis);
     rtR0SemEventBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -149,9 +153,11 @@ RTDECL(int)  RTSemEventSignal(RTSEMEVENT hEventSem)
     /*
      * Signal the event object.
      */
+    IPRT_FREEBSD_SAVE_EFL_AC();
     ASMAtomicWriteU32(&pThis->fState, 1);
     rtR0SemBsdSignal(pThis);
     rtR0SemEventBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -175,6 +181,7 @@ static int rtR0SemEventWait(PRTSEMEVENTINTERNAL pThis,
     AssertPtrReturn(pThis, VERR_INVALID_PARAMETER);
     AssertMsgReturn(pThis->u32Magic == RTSEMEVENT_MAGIC, ("%p u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_PARAMETER);
     AssertReturn(RTSEMWAIT_FLAGS_ARE_VALID(fFlags), VERR_INVALID_PARAMETER);
+    IPRT_FREEBSD_SAVE_EFL_AC();
     rtR0SemEventBsdRetain(pThis);
 
     /*
@@ -224,6 +231,7 @@ static int rtR0SemEventWait(PRTSEMEVENTINTERNAL pThis,
     }
 
     rtR0SemEventBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 }
 
