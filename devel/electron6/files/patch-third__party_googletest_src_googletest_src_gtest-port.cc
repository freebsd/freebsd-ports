--- third_party/googletest/src/googletest/src/gtest-port.cc.orig	2019-09-10 11:15:40 UTC
+++ third_party/googletest/src/googletest/src/gtest-port.cc
@@ -63,6 +63,11 @@
 # endif
 #endif
 
+#if GTEST_OS_FREEBSD
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 #if GTEST_OS_QNX
 # include <devctl.h>
 # include <fcntl.h>
@@ -137,6 +142,28 @@ size_t GetThreadCount() {
   } else {
     return 0;
   }
+}
+
+#elif GTEST_OS_FREEBSD
+
+#define KP_NLWP(kp) (kp.ki_numthreads)
+
+// Return the number of threads running in the process, or 0 to indicate that
+// we cannot detect it.
+size_t GetThreadCount() {
+  int mib[] = {
+    CTL_KERN,
+    KERN_PROC,
+    KERN_PROC_PID,
+    getpid(),
+  };
+  u_int miblen = sizeof(mib) / sizeof(mib[0]);
+  struct kinfo_proc(info);
+  size_t size = sizeof(info);
+  if (sysctl(mib, miblen, &info, &size, NULL, 0)) {
+    return 0;
+  }
+  return KP_NLWP(info);
 }
 
 #elif GTEST_OS_DRAGONFLY || GTEST_OS_FREEBSD || GTEST_OS_GNU_KFREEBSD || \
