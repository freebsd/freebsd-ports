--- util/env_posix.cc.orig	2014-06-20 07:40:32.000000000 +0800
+++ util/env_posix.cc	2014-07-22 22:10:43.909825684 +0800
@@ -1315,7 +1315,7 @@
   }
 
   virtual uint64_t NowNanos() {
-#ifdef OS_LINUX
+#ifdef OS_FREEBSD
     struct timespec ts;
     clock_gettime(CLOCK_MONOTONIC, &ts);
     return static_cast<uint64_t>(ts.tv_sec) * 1000000000 + ts.tv_nsec;
