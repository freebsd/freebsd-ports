Without the first part of this patch, any waits for periods shorter than a
single tick return immediately leading to a lot of unnecessary spinning. For
example, I observe that my guest's idle loop does a lot of sleeps with periods
slightly shorter than 1 ms (1/hz), e.g. 900us.  All that waiting turns into pure
spinning and VirtualBox eats 100% of a core.

The clamping improves the situation significantly. Also, it (approximately)
follows what tvtohz does. The rest of the patch just chases an upstream
KPI change.

Submitted by:	Andriy Gapon <avg@FreeBSD.org>
--- src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h.orig	2025-08-13 19:51:51 UTC
+++ src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h
@@ -94,6 +94,8 @@ DECLINLINE(uint32_t) rtR0SemBsdWaitUpdateTimeout(PRTR0
     uint64_t cTicks = ASMMultU64ByU32DivByU32(uTimeout, hz, UINT32_C(1000000000));
     if (cTicks >= INT_MAX)
         return RTSEMWAIT_FLAGS_INDEFINITE;
+    else if (cTicks == 0 && uTimeout > 0)
+        pWait->iTimeout     = 1;
     else
         pWait->iTimeout     = (int)cTicks;
 #endif
@@ -310,10 +312,16 @@ DECLINLINE(void) rtR0SemBsdSignal(void *pvWaitChan)
 DECLINLINE(void) rtR0SemBsdSignal(void *pvWaitChan)
 {
     sleepq_lock(pvWaitChan);
+#if __FreeBSD_version < 1500022
     int fWakeupSwapProc = sleepq_signal(pvWaitChan, SLEEPQ_CONDVAR, 0, 0);
+#else
+    sleepq_signal(pvWaitChan, SLEEPQ_CONDVAR, 0, 0);
+#endif
     sleepq_release(pvWaitChan);
+#if __FreeBSD_version < 1500022
     if (fWakeupSwapProc)
         kick_proc0();
+#endif
 }
 
 /**
