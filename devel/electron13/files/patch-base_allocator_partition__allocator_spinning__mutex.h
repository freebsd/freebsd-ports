--- base/allocator/partition_allocator/spinning_mutex.h.orig	2021-07-15 19:13:29 UTC
+++ base/allocator/partition_allocator/spinning_mutex.h
@@ -59,7 +59,7 @@ class LOCKABLE BASE_EXPORT SpinningMutex {
   // as the slow path has better characteristics than SpinLocks's.
   static constexpr int kSpinCount = 1000;
 
-#if defined(PA_HAS_LINUX_KERNEL)
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL)
   void FutexWait();
   void FutexWake();
 
@@ -104,7 +104,7 @@ ALWAYS_INLINE void SpinningMutex::Acquire() {
 
 inline constexpr SpinningMutex::SpinningMutex() = default;
 
-#if defined(PA_HAS_LINUX_KERNEL)
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL)
 
 ALWAYS_INLINE bool SpinningMutex::Try() {
   // Using the weak variant of compare_exchange(), which may fail spuriously. On
