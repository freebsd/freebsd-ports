--- base/synchronization/lock_impl.h.orig	2022-05-19 05:17:34 UTC
+++ base/synchronization/lock_impl.h
@@ -107,6 +107,10 @@ void LockImpl::Unlock() {
 }
 
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
+#endif
 
 BASE_EXPORT std::string SystemErrorCodeToString(int error_code);
 
@@ -121,6 +125,9 @@ void LockImpl::Unlock() {
   int rv = pthread_mutex_unlock(&native_handle_);
   DCHECK_EQ(rv, 0) << ". " << strerror(rv);
 }
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic pop
+#endif
 #endif
 
 // This is an implementation used for AutoLock templated on the lock type.
