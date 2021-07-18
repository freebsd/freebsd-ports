--- base/allocator/partition_allocator/spinning_mutex.cc.orig	2021-04-14 01:08:36 UTC
+++ base/allocator/partition_allocator/spinning_mutex.cc
@@ -16,9 +16,16 @@
 #include <unistd.h>
 #endif  // defined(PA_HAS_LINUX_KERNEL)
 
+#if defined(PA_HAS_FREEBSD_KERNEL)
+#include <errno.h>
+#include <sys/types.h>
+#include <sys/thr.h>
+#include <sys/umtx.h>
+#endif // defined(PA_HAS_FREEBSD_KERNEL)
+
 namespace base {
 namespace internal {
-#if defined(PA_HAS_LINUX_KERNEL)
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL)
 
 void SpinningMutex::FutexWait() {
   // Save and restore errno.
@@ -42,8 +49,13 @@ void SpinningMutex::FutexWait() {
   // |kLockedContended| anymore. Note that even without spurious wakeups, the
   // value of |state_| is not guaranteed when this returns, as another thread
   // may get the lock before we get to run.
+#if defined(PA_HAS_LINUX_KERNEL)
   int err = syscall(SYS_futex, &state_, FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
                     kLockedContended, nullptr, nullptr, 0);
+#elif defined(PA_HAS_FREEBSD_KERNEL)
+  int err = _umtx_op(&state_, UMTX_OP_WAIT_UINT_PRIVATE,
+		     kLockedContended, nullptr, nullptr);
+#endif
 
   if (err) {
     // These are programming error, check them.
@@ -55,8 +67,14 @@ void SpinningMutex::FutexWait() {
 
 void SpinningMutex::FutexWake() {
   int saved_errno = errno;
+#if defined(PA_HAS_LINUX_KERNEL)
   long retval = syscall(SYS_futex, &state_, FUTEX_WAKE | FUTEX_PRIVATE_FLAG,
                         1 /* wake up a single waiter */, nullptr, nullptr, 0);
+#elif defined(PA_HAS_FREEBSD_KERNEL)
+  long retval = _umtx_op(&state_, UMTX_OP_WAKE_PRIVATE,
+                         1 /* wake up a single waiter */, nullptr, nullptr);
+#endif
+		      
   PA_CHECK(retval != -1);
   errno = saved_errno;
 }
