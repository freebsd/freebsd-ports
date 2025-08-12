# Original upstream implementation:
#   https://jira.mongodb.org/browse/SERVER-81797
# Attempt to upstream this patch:
#   https://github.com/mongodb/mongo/pull/1607
#   https://jira.mongodb.org/browse/SERVER-99225
#
--- src/mongo/platform/waitable_atomic.cpp.orig	2024-11-20 23:53:48 UTC
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
@@ -233,6 +236,45 @@ bool waitUntil(const void* uaddr,
     // There isn't a good list of possible errors, so assuming that anything other than a timeout
     // error is a possible spurious wakeup.
     return timeoutOverflow || errno != ETIMEDOUT;
+}
+
+#elif defined(__FreeBSD__)
+
+void notifyOne(const void* uaddr) {
+    _umtx_op(const_cast<void*>(uaddr), UMTX_OP_WAKE_PRIVATE, 1, NULL, NULL);
+}
+
+void notifyMany(const void* uaddr, int nToWake) {
+    _umtx_op(const_cast<void*>(uaddr), UMTX_OP_WAKE_PRIVATE, nToWake, NULL, NULL);
+}
+
+void notifyAll(const void* uaddr) {
+    _umtx_op(const_cast<void*>(uaddr), UMTX_OP_WAKE_PRIVATE, INT_MAX, NULL, NULL);
+}
+
+bool waitUntil(const void* uaddr,
+               uint32_t old,
+               boost::optional<system_clock::time_point> deadline) {
+    struct _umtx_time umtx_deadline;
+    void* uaddr2 = nullptr;
+
+    if (deadline) {
+        umtx_deadline._timeout.tv_sec = durationCount<Seconds>(deadline->time_since_epoch());
+        umtx_deadline._timeout.tv_nsec = durationCount<Nanoseconds>(
+                deadline->time_since_epoch() - stdx::chrono::seconds(umtx_deadline._timeout.tv_sec));
+        umtx_deadline._flags = UMTX_ABSTIME;
+        umtx_deadline._clockid = CLOCK_REALTIME_FAST;
+        uaddr2 = &umtx_deadline;
+    }
+
+    int umtxOpRet;
+    if ((umtxOpRet = _umtx_op(const_cast<void*>(uaddr), UMTX_OP_WAIT_UINT_PRIVATE, old, (void*)sizeof(struct _umtx_time), uaddr2)) != 0) {
+        if (errno == ETIMEDOUT) {
+            return false;
+        }
+        invariant(umtxOpRet == 0, errorMessage(lastSystemError()));
+    }
+    return true;
 }
 
 #else
