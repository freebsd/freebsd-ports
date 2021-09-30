--- third_party/highway/hwy/nanobenchmark.cc.orig	2021-09-30 15:38:30 UTC
+++ third_party/highway/hwy/nanobenchmark.cc
@@ -47,7 +47,12 @@
 
 #include "hwy/base.h"
 #if HWY_ARCH_PPC
+#if linux
 #include <sys/platform/ppc.h>  // NOLINT __ppc_get_timebase_freq
+#elif __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>                 /* must come after sys/types.h */
+#endif
 #elif HWY_ARCH_X86
 
 #if HWY_COMPILER_MSVC
@@ -400,7 +405,14 @@ double NominalClockRate() {
 
 double InvariantTicksPerSecond() {
 #if HWY_ARCH_PPC
+#if linux
   return __ppc_get_timebase_freq();
+#elif __FreeBSD__
+  static double cycles_per_second = 0;
+  size_t length = sizeof(cycles_per_second);
+  sysctlbyname("kern.timecounter.tc.timebase.frequency", &cycles_per_second,
+               &length, NULL, 0);
+#endif
 #elif HWY_ARCH_X86
   // We assume the TSC is invariant; it is on all recent Intel/AMD CPUs.
   return NominalClockRate();
