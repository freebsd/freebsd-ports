--- base/synchronization/lock_impl.h.orig	2021-01-07 00:36:18 UTC
+++ base/synchronization/lock_impl.h
@@ -105,6 +105,8 @@ void LockImpl::Unlock() {
 }
 
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
 
 bool LockImpl::Try() {
   int rv = pthread_mutex_trylock(&native_handle_);
@@ -116,6 +118,7 @@ void LockImpl::Unlock() {
   int rv = pthread_mutex_unlock(&native_handle_);
   DCHECK_EQ(rv, 0) << ". " << strerror(rv);
 }
+#pragma GCC diagnostic pop
 #endif
 
 // This is an implementation used for AutoLock templated on the lock type.
