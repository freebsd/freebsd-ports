--- src/hotspot/os/bsd/os_perf_bsd.cpp.orig	2026-04-22 18:05:58 UTC
+++ src/hotspot/os/bsd/os_perf_bsd.cpp
@@ -34,6 +34,10 @@
   #include <mach/task_info.h>
 #else
 # if !defined(__NetBSD__)
+  #if ( defined(__aarch64__) && __FreeBSD_version >= 160000 )
+    // do not redefine "breakpoint"
+    #define _MACHINE_CPUFUNC_H_
+  #endif
   #include <sys/user.h>
 # endif
   #include <sys/sched.h>
