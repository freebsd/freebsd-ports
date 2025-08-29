--- src/VBox/Runtime/r0drv/freebsd/timer-r0drv-freebsd.c.orig	2025-08-13 19:51:51 UTC
+++ src/VBox/Runtime/r0drv/freebsd/timer-r0drv-freebsd.c
@@ -126,6 +126,7 @@ RTDECL(int) RTTimerCreateEx(PRTTIMER *ppTimer, uint64_
 RTDECL(int) RTTimerCreateEx(PRTTIMER *ppTimer, uint64_t u64NanoInterval, uint32_t fFlags, PFNRTTIMER pfnTimer, void *pvUser)
 {
     *ppTimer = NULL;
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     /*
      * Validate flags.
@@ -155,6 +156,7 @@ RTDECL(int) RTTimerCreateEx(PRTTIMER *ppTimer, uint64_
     callout_init(&pTimer->Callout, CALLOUT_MPSAFE);
 
     *ppTimer = pTimer;
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -175,6 +177,8 @@ RTDECL(int) RTTimerDestroy(PRTTIMER pTimer)
 
 RTDECL(int) RTTimerDestroy(PRTTIMER pTimer)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     /* It's ok to pass NULL pointer. */
     if (pTimer == /*NIL_RTTIMER*/ NULL)
         return VINF_SUCCESS;
@@ -187,6 +191,8 @@ RTDECL(int) RTTimerDestroy(PRTTIMER pTimer)
     pTimer->u32Magic++;
     callout_stop(&pTimer->Callout);
     RTMemFree(pTimer);
+
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -194,6 +200,7 @@ RTDECL(int) RTTimerStart(PRTTIMER pTimer, uint64_t u64
 RTDECL(int) RTTimerStart(PRTTIMER pTimer, uint64_t u64First)
 {
     struct timeval tv;
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     if (!rtTimerIsValid(pTimer))
         return VERR_INVALID_HANDLE;
@@ -217,12 +224,15 @@ RTDECL(int) RTTimerStart(PRTTIMER pTimer, uint64_t u64
     tv.tv_usec = (u64First % 1000000000) / 1000;
     callout_reset(&pTimer->Callout, tvtohz(&tv), rtTimerFreeBSDCallback, pTimer);
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
 
 RTDECL(int) RTTimerStop(PRTTIMER pTimer)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     if (!rtTimerIsValid(pTimer))
         return VERR_INVALID_HANDLE;
     if (pTimer->fSuspended)
@@ -234,6 +244,7 @@ RTDECL(int) RTTimerStop(PRTTIMER pTimer)
     pTimer->fSuspended = true;
     callout_stop(&pTimer->Callout);
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
