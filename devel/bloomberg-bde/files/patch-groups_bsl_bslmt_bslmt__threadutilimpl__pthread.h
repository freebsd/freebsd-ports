--- groups/bsl/bslmt/bslmt_threadutilimpl_pthread.h.orig	2023-07-31 19:01:20 UTC
+++ groups/bsl/bslmt/bslmt_threadutilimpl_pthread.h
@@ -443,6 +443,8 @@ bslmt::ThreadUtilImpl<bslmt::Platform::PosixThreads>::
 {
 #ifdef BSLS_PLATFORM_OS_DARWIN
     return reinterpret_cast<bsls::Types::Uint64>(threadId);
+#elif defined(BSLS_PLATFORM_OS_FREEBSD)
+    return static_cast<bsls::Types::Uint64>(reinterpret_cast<std::uintptr_t>(threadId));
 #else
     return static_cast<bsls::Types::Uint64>(threadId);
 #endif
