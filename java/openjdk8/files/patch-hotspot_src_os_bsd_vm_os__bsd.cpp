--- hotspot/src/os/bsd/vm/os_bsd.cpp.orig	2015-12-22 22:54:16 UTC
+++ hotspot/src/os/bsd/vm/os_bsd.cpp
@@ -151,6 +151,7 @@ mach_timebase_info_data_t os::Bsd::_time
 volatile uint64_t         os::Bsd::_max_abstime   = 0;
 #else
 int (*os::Bsd::_clock_gettime)(clockid_t, struct timespec *) = NULL;
+int (*os::Bsd::_getcpuclockid)(pthread_t, clockid_t *) = NULL;
 #endif
 pthread_t os::Bsd::_main_thread;
 int os::Bsd::_page_size = -1;
@@ -1058,6 +1059,7 @@ void os::Bsd::clock_init() {
     // yes, monotonic clock is supported
     _clock_gettime = ::clock_gettime;
   }
+  _getcpuclockid = (int (*)(pthread_t, clockid_t *))dlsym(RTLD_DEFAULT, "pthread_getcpuclockid");
 }
 #endif
 
@@ -4248,6 +4250,8 @@ jlong os::current_thread_cpu_time() {
 #ifdef __APPLE__
   return os::thread_cpu_time(Thread::current(), true /* user + sys */);
 #else
+  if (Bsd::_getcpuclockid != NULL)
+    return os::thread_cpu_time(Thread::current(), true /* user + sys */);
   Unimplemented();
   return 0;
 #endif
@@ -4257,6 +4261,8 @@ jlong os::thread_cpu_time(Thread* thread
 #ifdef __APPLE__
   return os::thread_cpu_time(thread, true /* user + sys */);
 #else
+  if (Bsd::_getcpuclockid != NULL)
+    return os::thread_cpu_time(thread, true /* user + sys */);
   Unimplemented();
   return 0;
 #endif
@@ -4266,6 +4272,8 @@ jlong os::current_thread_cpu_time(bool u
 #ifdef __APPLE__
   return os::thread_cpu_time(Thread::current(), user_sys_cpu_time);
 #else
+  if (Bsd::_getcpuclockid != NULL)
+    return os::thread_cpu_time(Thread::current(), user_sys_cpu_time);
   Unimplemented();
   return 0;
 #endif
@@ -4292,6 +4300,24 @@ jlong os::thread_cpu_time(Thread *thread
     return ((jlong)tinfo.user_time.seconds * 1000000000) + ((jlong)tinfo.user_time.microseconds * (jlong)1000);
   }
 #else
+  if (user_sys_cpu_time && Bsd::_getcpuclockid != NULL) {
+    struct timespec tp;
+    clockid_t clockid;
+    int ret;
+
+    /*
+     * XXX This is essentially a copy of the Linux implementation,
+     *     but with fewer indirections.
+     */
+    ret = Bsd::_getcpuclockid(thread->osthread()->pthread_id(), &clockid);
+    if (ret != 0)
+      return -1;
+    /* NB: _clock_gettime only needs to be valid for CLOCK_MONOTONIC. */
+    ret = ::clock_gettime(clockid, &tp);
+    if (ret != 0)
+      return -1;
+    return (tp.tv_sec * NANOSECS_PER_SEC) + tp.tv_nsec;
+  }
   Unimplemented();
   return 0;
 #endif
@@ -4316,7 +4342,7 @@ bool os::is_thread_cpu_time_supported() 
 #ifdef __APPLE__
   return true;
 #else
-  return false;
+  return (Bsd::_getcpuclockid != NULL);
 #endif
 }
 
