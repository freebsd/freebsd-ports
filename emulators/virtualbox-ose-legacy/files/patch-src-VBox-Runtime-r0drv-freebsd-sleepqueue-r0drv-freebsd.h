Without this patch any waits for periods shorter than a single tick return
immediately leading to a lot of unnecessary spinning. For example, I observe that
my guest's idle loop does a lot of sleeps with periods slightly shorter than 1 ms
(1/hz), e.g. 900us.  All that waiting turns into pure spinning and VirtualBox eats
100% of a core.
The patch improves the situation significantly. Also, it (approximately) follows
what tvtohz does.

Submitted by:	Andriy Gapon <avg@FreeBSD.org>
--- src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h.orig	2012-12-19 19:27:29.000000000 +0100
+++ src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h	2012-12-20 12:07:48.941861966 +0100
@@ -82,6 +82,8 @@
     uint64_t cTicks = ASMMultU64ByU32DivByU32(uTimeout, hz, UINT32_C(1000000000));
     if (cTicks >= INT_MAX)
         return RTSEMWAIT_FLAGS_INDEFINITE;
+    else if (cTicks == 0 && uTimeout > 0)
+        pWait->iTimeout     = 1;
     else
         pWait->iTimeout     = (int)cTicks;
 #endif
