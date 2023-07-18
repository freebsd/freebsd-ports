--- groups/bsl/bslmt/bslmt_threadutilimpl_pthread.cpp.orig	2023-08-03 19:22:19 UTC
+++ groups/bsl/bslmt/bslmt_threadutilimpl_pthread.cpp
@@ -41,6 +41,8 @@ BSLS_IDENT_RCSID(bslmt_threadutilimpl_pthread_cpp,"$Id
 # include <mach/mach.h>    // clock_sleep
 # include <mach/clock.h>   // clock_sleep
 # include <sys/sysctl.h>   // sysctl
+#elif defined(BSLS_PLATFORM_OS_FREEBSD)
+#include <sys/sysctl.h>
 #elif defined(BSLS_PLATFORM_OS_SOLARIS)
 # include <sys/utsname.h>
 #elif defined(BSLS_PLATFORM_OS_LINUX)
@@ -557,7 +559,11 @@ bslmt::ThreadUtilImpl<bslmt::Platform::PosixThreads>::
     // set the mib for hw.ncpu.
 
     mib[0] = CTL_HW;
+#if defined(HW_AVAILCPU)
     mib[1] = HW_AVAILCPU;  // alternatively, try HW_NCPU
+#else
+    mib[1] = HW_NCPU;
+#endif
 
     // Get the number of CPUs from the system.
 
