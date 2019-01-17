- Implement setting thread name
- Use monotonic clock for timeouts

--- src/util/u_thread.h.orig	2018-11-09 11:03:00 UTC
+++ src/util/u_thread.h
@@ -34,7 +34,14 @@
 
 #ifdef HAVE_PTHREAD
 #include <signal.h>
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#include <pthread_np.h>
+# if !defined(__DragonFly__)
+#  define cpu_set_t cpuset_t
+# endif
+#undef ALIGN /* Avoid conflict on FreeBSD in main/macros.h */
 #endif
+#endif
 
 static inline thrd_t u_thread_create(int (*routine)(void *), void *param)
 {
@@ -64,6 +69,12 @@ static inline void u_thread_setname( const char *name 
       (__GLIBC__ >= 3 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 12)) && \
       defined(__linux__)
    pthread_setname_np(pthread_self(), name);
+#  elif defined(__sun)
+   pthread_setname_np(pthread_self(), name);
+#  elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+   pthread_set_name_np(pthread_self(), name);
+#  elif defined(__NetBSD__)
+   pthread_setname_np(pthread_self(), "%s", (void*)name);
 #  endif
 #endif
    (void)name;
@@ -134,7 +145,7 @@ util_get_L3_for_pinned_thread(thrd_t thread, unsigned 
 static inline int64_t
 u_thread_get_time_nano(thrd_t thread)
 {
-#if defined(__linux__) && defined(HAVE_PTHREAD)
+#if defined(HAVE_PTHREAD)
    struct timespec ts;
    clockid_t cid;
 
