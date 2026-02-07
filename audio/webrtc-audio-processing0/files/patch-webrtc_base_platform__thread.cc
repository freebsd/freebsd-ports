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
@@ -32,6 +38,12 @@ PlatformThreadId CurrentThreadId() {
   ret =  syscall(__NR_gettid);
 #elif defined(WEBRTC_ANDROID)
   ret = gettid();
+#elif defined(__DragonFly__) || defined(__FreeBSD__) // WEBRTC_BSD
+  ret = pthread_getthreadid_np();
+#elif defined(__NetBSD__) // WEBRTC_BSD
+  ret = _lwp_self();
+#elif defined(__OpenBSD__) // WEBRTC_BSD
+  ret = getthrid();
 #else
   // Default implementation for nacl and solaris.
   ret = reinterpret_cast<pid_t>(pthread_self());
@@ -76,6 +88,10 @@ void SetCurrentThreadName(const char* name) {
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__) // WEBRTC_BSD
+  pthread_set_name_np(pthread_self(), name);
+#elif defined(__NetBSD__) // WEBRTC_BSD
+  pthread_setname_np(pthread_self(), "%s", (void*)name);
 #endif
 }
 
