Without this patch any waits for periods shorter than a single tick return
immediately leading to a lot of unnecessary spinning. For example, I observe that
my guest's idle loop does a lot of sleeps with periods slightly shorter than 1 ms
(1/hz), e.g. 900us.  All that waiting turns into pure spinning and VirtualBox eats
100% of a core.
The patch improves the situation significantly. Also, it (approximately) follows
what tvtohz does.

Submitted by:	Andriy Gapon <avg@FreeBSD.org>
--- src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h.orig	2021-01-07 15:42:09 UTC
+++ src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h
@@ -84,6 +84,8 @@ DECLINLINE(uint32_t) rtR0SemBsdWaitUpdateTimeout(PRTR0
     uint64_t cTicks = ASMMultU64ByU32DivByU32(uTimeout, hz, UINT32_C(1000000000));
     if (cTicks >= INT_MAX)
         return RTSEMWAIT_FLAGS_INDEFINITE;
+    else if (cTicks == 0 && uTimeout > 0)
+        pWait->iTimeout     = 1;
     else
         pWait->iTimeout     = (int)cTicks;
 #endif
