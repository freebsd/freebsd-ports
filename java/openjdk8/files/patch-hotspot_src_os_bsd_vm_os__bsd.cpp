--- hotspot/src/os/bsd/vm/os_bsd.cpp.orig	2016-01-05 21:15:40 UTC
+++ hotspot/src/os/bsd/vm/os_bsd.cpp
@@ -151,6 +151,7 @@ mach_timebase_info_data_t os::Bsd::_time
 volatile uint64_t         os::Bsd::_max_abstime   = 0;
 #else
 int (*os::Bsd::_clock_gettime)(clockid_t, struct timespec *) = NULL;
+int (*os::Bsd::_getcpuclockid)(pthread_t, clockid_t *) = NULL;
 #endif
 pthread_t os::Bsd::_main_thread;
 int os::Bsd::_page_size = -1;
@@ -1028,6 +1029,13 @@ bool os::enable_vtime()   { return false
 bool os::vtime_enabled()  { return false; }
 
 double os::elapsedVTime() {
+#ifdef RUSAGE_THREAD
+  struct rusage usage;
+  int retval = getrusage(RUSAGE_THREAD, &usage);
+  if (retval == 0) {
+    return (double) (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) + (double) (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / (1000 * 1000);
+  }
+#endif
   // better than nothing, but not much
   return elapsedTime();
 }
@@ -1058,6 +1066,7 @@ void os::Bsd::clock_init() {
     // yes, monotonic clock is supported
     _clock_gettime = ::clock_gettime;
   }
+  _getcpuclockid = (int (*)(pthread_t, clockid_t *))dlsym(RTLD_DEFAULT, "pthread_getcpuclockid");
 }
 #endif
 
@@ -4248,8 +4257,9 @@ jlong os::current_thread_cpu_time() {
 #ifdef __APPLE__
   return os::thread_cpu_time(Thread::current(), true /* user + sys */);
 #else
-  Unimplemented();
-  return 0;
+  if (Bsd::_getcpuclockid != NULL)
+    return os::thread_cpu_time(Thread::current(), true /* user + sys */);
+  return -1;
 #endif
 }
 
@@ -4257,8 +4267,9 @@ jlong os::thread_cpu_time(Thread* thread
 #ifdef __APPLE__
   return os::thread_cpu_time(thread, true /* user + sys */);
 #else
-  Unimplemented();
-  return 0;
+  if (Bsd::_getcpuclockid != NULL)
+    return os::thread_cpu_time(thread, true /* user + sys */);
+  return -1;
 #endif
 }
 
@@ -4266,8 +4277,9 @@ jlong os::current_thread_cpu_time(bool u
 #ifdef __APPLE__
   return os::thread_cpu_time(Thread::current(), user_sys_cpu_time);
 #else
-  Unimplemented();
-  return 0;
+  if (Bsd::_getcpuclockid != NULL)
+    return os::thread_cpu_time(Thread::current(), user_sys_cpu_time);
+  return -1;
 #endif
 }
 
@@ -4292,8 +4304,41 @@ jlong os::thread_cpu_time(Thread *thread
     return ((jlong)tinfo.user_time.seconds * 1000000000) + ((jlong)tinfo.user_time.microseconds * (jlong)1000);
   }
 #else
-  Unimplemented();
-  return 0;
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
+#ifdef RUSAGE_THREAD
+  if (thread == Thread::current()) {
+    struct rusage usage;
+    jlong nanos;
+
+    if (getrusage(RUSAGE_THREAD, &usage) != 0)
+      return -1;
+    nanos = (jlong)usage.ru_utime.tv_sec * NANOSECS_PER_SEC;
+    nanos += (jlong)usage.ru_utime.tv_usec * 1000;
+    if (user_sys_cpu_time) {
+      nanos += (jlong)usage.ru_stime.tv_sec * NANOSECS_PER_SEC;
+      nanos += (jlong)usage.ru_stime.tv_usec * 1000;
+    }
+    return nanos;
+  }
+#endif
+  return -1;
 #endif
 }
 
@@ -4316,7 +4361,7 @@ bool os::is_thread_cpu_time_supported() 
 #ifdef __APPLE__
   return true;
 #else
-  return false;
+  return (Bsd::_getcpuclockid != NULL);
 #endif
 }
 
