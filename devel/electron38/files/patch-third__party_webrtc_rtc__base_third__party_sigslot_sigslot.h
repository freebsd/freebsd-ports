--- third_party/webrtc/rtc_base/third_party/sigslot/sigslot.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/webrtc/rtc_base/third_party/sigslot/sigslot.h
@@ -178,6 +178,10 @@ class multi_threaded_local {
 #endif  // _SIGSLOT_HAS_WIN32_THREADS
 
 #ifdef _SIGSLOT_HAS_POSIX_THREADS
+#if defined(OS_FREEBSD)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
+#endif
 // The multi threading policies only get compiled in if they are enabled.
 class multi_threaded_global {
  public:
@@ -201,6 +205,9 @@ class multi_threaded_local {
  private:
   pthread_mutex_t m_mutex;
 };
+#if defined(OS_FREEBSD)
+#pragma GCC diagnostic pop
+#endif
 #endif  // _SIGSLOT_HAS_POSIX_THREADS
 
 template <class mt_policy>
