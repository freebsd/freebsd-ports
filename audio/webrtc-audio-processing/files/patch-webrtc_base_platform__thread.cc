- Implement CurrentThreadId() using global thread ID
- Implement SetCurrentThreadName()

--- webrtc/base/platform_thread.cc.orig	2018-07-23 14:02:57 UTC
+++ webrtc/base/platform_thread.cc
@@ -19,6 +19,12 @@
 #include <sys/syscall.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__) // WEBRTC_BSD
+#include <pthread_np.h>
+#elif defined(__NetBSD__) // WEBRTC_BSD
+#include <lwp.h>
+#endif
+
 namespace rtc {
 
 PlatformThreadId CurrentThreadId() {
@@ -32,9 +38,17 @@ PlatformThreadId CurrentThreadId() {
   ret =  syscall(__NR_gettid);
 #elif defined(WEBRTC_ANDROID)
   ret = gettid();
+#elif defined(__DragonFly__) // WEBRTC_BSD
+  ret = lwp_gettid();
+#elif defined(__FreeBSD__) // WEBRTC_BSD
+  ret = pthread_getthreadid_np();
+#elif defined(__NetBSD__) // WEBRTC_BSD
+  ret = _lwp_self();
 #else
   // Default implementation for nacl and solaris.
-  ret = reinterpret_cast<pid_t>(pthread_self());
+  // WEBRTC_BSD: pthread_t is a pointer, so cannot be casted to pid_t
+  //             (aka int32_t) on 64-bit archs. Required on OpenBSD.
+  ret = reinterpret_cast<uintptr_t>(pthread_self());
 #endif
 #endif  // defined(WEBRTC_POSIX)
   RTC_DCHECK(ret);
@@ -76,6 +90,10 @@ void SetCurrentThreadName(const char* name) {
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__) // WEBRTC_BSD
+  pthread_set_name_np(pthread_self(), name);
+#elif defined(__NetBSD__) // WEBRTC_BSD
+  pthread_setname_np(pthread_self(), "%s", (void*)name);
 #endif
 }
 
