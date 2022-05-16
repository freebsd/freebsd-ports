--- third_party/webrtc/rtc_base/platform_thread_types.cc.orig	2022-05-11 07:06:40 UTC
+++ third_party/webrtc/rtc_base/platform_thread_types.cc
@@ -11,7 +11,9 @@
 #include "rtc_base/platform_thread_types.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
@@ -37,8 +39,10 @@ PlatformThreadId CurrentThreadId() {
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
   return syscall(__NR_gettid);
+#elif defined(WEBRTC_BSD)
+  return reinterpret_cast<uint64_t>(pthread_self());
 #elif defined(__EMSCRIPTEN__)
   return static_cast<PlatformThreadId>(pthread_self());
 #else
@@ -67,6 +71,7 @@ bool IsThreadRefEqual(const PlatformThreadRef& a, cons
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(WEBRTC_BSD)
 #if defined(WEBRTC_WIN)
   // The SetThreadDescription API works even if no debugger is attached.
   // The names set with this API also show up in ETW traces. Very handy.
@@ -109,6 +114,7 @@ void SetCurrentThreadName(const char* name) {
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#endif
 #endif
 }
 
