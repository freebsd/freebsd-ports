--- src/VBox/Runtime/r0drv/freebsd/thread-r0drv-freebsd.c.orig	2021-04-20 04:32:44 UTC
+++ src/VBox/Runtime/r0drv/freebsd/thread-r0drv-freebsd.c
@@ -49,7 +49,6 @@ RTDECL(RTNATIVETHREAD) RTThreadNativeSelf(void)
 static int rtR0ThreadFbsdSleepCommon(RTMSINTERVAL cMillies)
 {
     int rc;
-    int cTicks;
 
     /*
      * 0 ms sleep -> yield.
@@ -60,30 +59,34 @@ static int rtR0ThreadFbsdSleepCommon(RTMSINTERVAL cMil
         return VINF_SUCCESS;
     }
 
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     /*
      * Translate milliseconds into ticks and go to sleep.
      */
     if (cMillies != RT_INDEFINITE_WAIT)
     {
-        if (hz == 1000)
-            cTicks = cMillies;
-        else if (hz == 100)
-            cTicks = cMillies / 10;
-        else
-        {
-            int64_t cTicks64 = ((uint64_t)cMillies * hz) / 1000;
-            cTicks = (int)cTicks64;
-            if (cTicks != cTicks64)
-                cTicks = INT_MAX;
-        }
+        struct timeval tv;
+
+        tv.tv_sec = cMillies / 1000;
+        tv.tv_usec = cMillies * 1000;
+
+        rc = tsleep_sbt((void *)RTThreadSleep,
+                        PZERO | PCATCH,
+                        "iprtsl",       /* max 6 chars */
+                        tvtosbt(tv),
+                        0,
+                        C_ABSOLUTE);
     }
     else
-        cTicks = 0;     /* requires giant lock! */
-
-    rc = tsleep((void *)RTThreadSleep,
-                PZERO | PCATCH,
-                "iprtsl",           /* max 6 chars */
-                cTicks);
+    {
+        /* requires giant lock! */
+        rc = tsleep((void *)RTThreadSleep,
+                    PZERO | PCATCH,
+                    "iprts0",           /* max 6 chars */
+                    0);
+    }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     switch (rc)
     {
         case 0:
@@ -114,11 +117,13 @@ RTDECL(int) RTThreadSleepNoLog(RTMSINTERVAL cMillies)
 
 RTDECL(bool) RTThreadYield(void)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
 #if __FreeBSD_version >= 900032
     kern_yield(curthread->td_user_pri);
 #else
     uio_yield();
 #endif
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return false; /** @todo figure this one ... */
 }
 
@@ -167,12 +172,14 @@ RTDECL(void) RTThreadPreemptDisable(PRTTHREADPREEMPTST
 
 RTDECL(void) RTThreadPreemptRestore(PRTTHREADPREEMPTSTATE pState)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC(); /* paranoia */
     AssertPtr(pState);
     Assert(pState->u32Reserved == 42);
     pState->u32Reserved = 0;
 
     RT_ASSERT_PREEMPT_CPUID_RESTORE(pState);
     critical_exit();
+    IPRT_FREEBSD_RESTORE_EFL_ONLY_AC();  /* paranoia */
 }
 
 
