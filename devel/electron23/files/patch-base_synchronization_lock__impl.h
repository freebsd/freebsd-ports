--- base/synchronization/lock_impl.h.orig	2022-06-17 14:20:10 UTC
+++ base/synchronization/lock_impl.h
@@ -107,6 +107,10 @@ void LockImpl::Unlock() {
 }
 
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
+#endif
 
 #if DCHECK_IS_ON()
 BASE_EXPORT void dcheck_trylock_result(int rv);
@@ -127,6 +131,9 @@ void LockImpl::Unlock() {
   dcheck_unlock_result(rv);
 #endif
 }
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic pop
+#endif
 #endif
 
 // This is an implementation used for AutoLock templated on the lock type.
