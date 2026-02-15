--- pxr/base/arch/timing.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/timing.cpp
@@ -24,6 +24,10 @@
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
+#elif defined(ARCH_OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <stdio.h>
 #elif defined(ARCH_OS_WINDOWS)
 #include <Windows.h>
 #include <chrono>
@@ -133,6 +137,26 @@ Arch_ComputeNanosecondsPerTick()
     // as the overhead to call now() one time.
     return clockNanoSecs /
         double(ticks - ArchGetIntervalTimerTickOverhead() - nowDuration);
+}
+#elif defined(ARCH_OS_FREEBSD)
+
+static
+double
+Arch_ComputeNanosecondsPerTick()
+{
+#if defined(ARCH_CPU_ARM)
+    uint64_t counter_hz;
+    __asm __volatile("mrs	%0, CNTFRQ_EL0" : "=&r" (counter_hz));
+    Arch_NanosecondsPerTick = double(1e9) / double(counter_hz);
+#else
+   size_t counter_mhz = 0;
+   const char mib[] = "dev.cpu.0.freq";
+   if (sysctlbyname(mib, NULL, &counter_mhz, NULL, 0) == -1) {
+      perror("sysctlbyname");
+      abort();
+   }
+   Arch_NanosecondsPerTick = double(1e9) / double(counter_mhz*1000000);
+#endif
 }
 #elif defined(ARCH_OS_WINDOWS)
 
