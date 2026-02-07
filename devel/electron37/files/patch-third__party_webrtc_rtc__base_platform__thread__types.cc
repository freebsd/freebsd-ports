--- third_party/webrtc/rtc_base/platform_thread_types.cc.orig	2025-06-30 07:04:30 UTC
+++ third_party/webrtc/rtc_base/platform_thread_types.cc
@@ -12,7 +12,9 @@
 
 // IWYU pragma: begin_keep
 #if defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
@@ -46,6 +48,8 @@ PlatformThreadId CurrentThreadId() {
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
+#elif defined(WEBRTC_BSD)
+  return reinterpret_cast<uint64_t>(pthread_self());
 #elif defined(WEBRTC_LINUX)
   return syscall(__NR_gettid);
 #elif defined(__EMSCRIPTEN__)
@@ -76,6 +80,7 @@ void SetCurrentThreadName(const char* name) {
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(WEBRTC_BSD)
 #if defined(WEBRTC_WIN)
   // The SetThreadDescription API works even if no debugger is attached.
   // The names set with this API also show up in ETW traces. Very handy.
@@ -122,6 +127,7 @@ void SetCurrentThreadName(const char* name) {
   zx_status_t status = zx_object_set_property(zx_thread_self(), ZX_PROP_NAME,
                                               name, strlen(name));
   RTC_DCHECK_EQ(status, ZX_OK);
+#endif
 #endif
 }
 
