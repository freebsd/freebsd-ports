--- src/third_party/wiredtiger/src/os_linux/os_futex.c.orig
+++ src/third_party/wiredtiger/src/os_linux/os_futex.c
@@ -9,4 +9,8 @@
 #include "wt_internal.h"
 
+#ifdef __FreeBSD__
+#include <sys/umtx.h>
+#else
 #include <linux/futex.h>
 #include <sys/syscall.h>
+#endif
@@ -18,18 +22,36 @@
 int
 __wt_futex_wait(
   volatile WT_FUTEX_WORD *addr, WT_FUTEX_WORD expected, time_t usec, WT_FUTEX_WORD *wake_valp)
 {
+#ifdef __FreeBSD__
+    struct _umtx_time timeout;
+    int ret;
+#else
     struct timespec timeout;
     long sysret;
+#endif
 
     WT_ASSERT(NULL, usec > 0);
 
+#ifdef __FreeBSD__
+    __wt_usec_to_timespec(usec, &timeout._timeout);
+    timeout._flags = 0;
+    timeout._clockid = CLOCK_MONOTONIC;
+    ret = _umtx_op((void *)(uintptr_t)addr, UMTX_OP_WAIT_UINT_PRIVATE, expected,
+      (void *)(uintptr_t)sizeof(timeout), &timeout);
+    if (ret == 0)
+#else
     __wt_usec_to_timespec(usec, &timeout);
     sysret = syscall(SYS_futex, addr, FUTEX_WAIT_PRIVATE, expected, &timeout, NULL, 0);
     if (sysret == 0)
+#endif
         *wake_valp = __atomic_load_n(addr, __ATOMIC_SEQ_CST);
 
+#ifdef __FreeBSD__
+    return (ret);
+#else
     return ((int)sysret);
+#endif
 }
 
 /*
@@ -39,14 +61,23 @@
 int
 __wt_futex_wake(volatile WT_FUTEX_WORD *addr, WT_FUTEX_WAKE wake, WT_FUTEX_WORD wake_val)
 {
-    long sysret;
     int wake_op;
+#ifdef __FreeBSD__
+    int ret;
+#else
+    long sysret;
+#endif
 
     WT_ASSERT(NULL, wake == WT_FUTEX_WAKE_ONE || wake == WT_FUTEX_WAKE_ALL);
 
     wake_op = (wake == WT_FUTEX_WAKE_ALL) ? INT_MAX : 1;
     __atomic_store_n(addr, wake_val, __ATOMIC_SEQ_CST);
+#ifdef __FreeBSD__
+    ret = _umtx_op((void *)(uintptr_t)addr, UMTX_OP_WAKE_PRIVATE, wake_op, NULL, NULL);
+    return ((ret == 0) ? 0 : ret);
+#else
     sysret = syscall(SYS_futex, addr, FUTEX_WAKE_PRIVATE, wake_op, NULL, 0);
 
     return ((int)((sysret >= 0) ? 0 : sysret));
+#endif
 }
