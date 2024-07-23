--- src/mongo/platform/waitable_atomic.cpp.orig	2024-07-23 11:53:14 UTC
+++ src/mongo/platform/waitable_atomic.cpp
@@ -34,6 +34,9 @@
 #ifdef __linux__
 #include <linux/futex.h>
 #include <sys/syscall.h>
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/umtx.h>
 #elif defined(_WIN32)
 #include <synchapi.h>
 #endif
@@ -228,6 +231,52 @@ bool waitUntil(const void* uaddr,
     }
 
     if (__ulock_wait(UL_COMPARE_AND_WAIT, const_cast<void*>(uaddr), old, timeoutMicros) != -1)
+        return true;
+
+    // There isn't a good list of possible errors, so assuming that anything other than a timeout
+    // error is a possible spurious wakeup.
+    return timeoutOverflow || errno != ETIMEDOUT;
+}
+
+#elif defined(__FreeBSD__)
+
+void notifyOne(const void* uaddr) {
+    _umtx_op(const_cast<void*>(uaddr), UMTX_OP_WAKE, 1, NULL, NULL);
+}
+
+void notifyMany(const void* uaddr, int nToWake) {
+    _umtx_op(const_cast<void*>(uaddr), UMTX_OP_WAKE, nToWake, NULL, NULL);
+}
+
+void notifyAll(const void* uaddr) {
+    _umtx_op(const_cast<void*>(uaddr), UMTX_OP_WAKE, INT_MAX, NULL, NULL);
+}
+
+bool waitUntil(const void* uaddr,
+               uint32_t old,
+               boost::optional<system_clock::time_point> deadline) {
+    struct timespec timeout;
+    bool timeoutOverflow = false;
+    if (deadline) {
+        int64_t micros = durationCount<Microseconds>(*deadline - system_clock::now());
+        if (micros <= 0) {
+            return false;  // Synthesize a timeout.
+        }
+
+        if (micros > int64_t(std::numeric_limits<uint32_t>::max())) {
+            // 2**32 micros is a little over an hour. If this happens, we wait as long as we can,
+            // then return as-if a spurious wakeup happened, rather than a timeout. This will cause
+            // the caller to loop and we will compute a smaller time each pass, eventually reaching
+            // a representable timeout.
+            micros = std::numeric_limits<uint32_t>::max();
+            timeoutOverflow = true;
+        }
+
+	timeout.tv_sec = micros / 1000;
+	timeout.tv_nsec = (micros % 1000) * 1000;
+    }
+
+    if (_umtx_op(const_cast<void*>(uaddr), UMTX_OP_WAIT, old, (void*)sizeof(struct timespec), &timeout) != -1)
         return true;
 
     // There isn't a good list of possible errors, so assuming that anything other than a timeout
