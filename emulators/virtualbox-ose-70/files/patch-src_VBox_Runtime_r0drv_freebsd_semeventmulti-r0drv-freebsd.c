--- src/VBox/Runtime/r0drv/freebsd/semeventmulti-r0drv-freebsd.c.orig	2021-01-07 15:42:08 UTC
+++ src/VBox/Runtime/r0drv/freebsd/semeventmulti-r0drv-freebsd.c
@@ -120,7 +120,9 @@ RTDECL(int)  RTSemEventMultiCreateEx(PRTSEMEVENTMULTI 
     PRTSEMEVENTMULTIINTERNAL pThis;
 
     AssertReturn(!(fFlags & ~RTSEMEVENTMULTI_FLAGS_NO_LOCK_VAL), VERR_INVALID_PARAMETER);
+    IPRT_FREEBSD_SAVE_EFL_AC();
     pThis = (PRTSEMEVENTMULTIINTERNAL)RTMemAlloc(sizeof(*pThis));
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     if (pThis)
     {
         pThis->u32Magic     = RTSEMEVENTMULTI_MAGIC;
@@ -176,10 +178,12 @@ RTDECL(int)  RTSemEventMultiDestroy(RTSEMEVENTMULTI hE
     /*
      * Invalidate it and signal the object just in case.
      */
+    IPRT_FREEBSD_SAVE_EFL_AC();
     ASMAtomicWriteU32(&pThis->u32Magic, ~RTSEMEVENTMULTI_MAGIC);
     ASMAtomicAndU32(&pThis->fStateAndGen, RTSEMEVENTMULTIBSD_GEN_MASK);
     rtR0SemBsdBroadcast(pThis);
     rtR0SemEventMultiBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -188,6 +192,7 @@ RTDECL(int)  RTSemEventMultiSignal(RTSEMEVENTMULTI hEv
 {
     uint32_t fNew;
     uint32_t fOld;
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     /*
      * Validate input.
@@ -214,12 +219,15 @@ RTDECL(int)  RTSemEventMultiSignal(RTSEMEVENTMULTI hEv
 
     rtR0SemBsdBroadcast(pThis);
     rtR0SemEventMultiBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
 
 RTDECL(int)  RTSemEventMultiReset(RTSEMEVENTMULTI hEventMultiSem)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     /*
      * Validate input.
      */
@@ -236,6 +244,7 @@ RTDECL(int)  RTSemEventMultiReset(RTSEMEVENTMULTI hEve
     ASMAtomicAndU32(&pThis->fStateAndGen, ~RTSEMEVENTMULTIBSD_STATE_MASK);
 
     rtR0SemEventMultiBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -252,6 +261,7 @@ RTDECL(int)  RTSemEventMultiReset(RTSEMEVENTMULTI hEve
 static int rtR0SemEventMultiBsdWait(PRTSEMEVENTMULTIINTERNAL pThis, uint32_t fFlags, uint64_t uTimeout,
                                     PCRTLOCKVALSRCPOS pSrcPos)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     uint32_t    fOrgStateAndGen;
     int         rc;
 
@@ -311,6 +321,7 @@ static int rtR0SemEventMultiBsdWait(PRTSEMEVENTMULTIIN
     }
 
     rtR0SemEventMultiBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 }
 
