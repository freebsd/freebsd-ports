--- hotspot/src/os/bsd/vm/os_bsd.hpp.orig	2015-12-22 22:53:56 UTC
+++ hotspot/src/os/bsd/vm/os_bsd.hpp
@@ -64,6 +64,7 @@ class Bsd {
   static volatile uint64_t         _max_abstime;
 #else
   static int (*_clock_gettime)(clockid_t, struct timespec *);
+  static int (*_getcpuclockid)(pthread_t, clockid_t *);
 #endif
 
   static GrowableArray<int>* _cpu_to_node;
