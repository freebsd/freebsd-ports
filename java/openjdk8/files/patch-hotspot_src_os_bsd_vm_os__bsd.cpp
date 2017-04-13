--- hotspot/src/os/bsd/vm/os_bsd.cpp.orig	2017-04-12 17:03:59 UTC
+++ hotspot/src/os/bsd/vm/os_bsd.cpp
@@ -155,6 +155,7 @@ int (*os::Bsd::_getcpuclockid)(pthread_t
 #endif
 pthread_t os::Bsd::_main_thread;
 int os::Bsd::_page_size = -1;
+pthread_condattr_t os::Bsd::_condattr[1];
 
 static jlong initial_time_count=0;
 
@@ -1076,12 +1077,15 @@ void os::Bsd::clock_init() {
 void os::Bsd::clock_init() {
   struct timespec res;
   struct timespec tp;
+  _getcpuclockid = (int (*)(pthread_t, clockid_t *))dlsym(RTLD_DEFAULT, "pthread_getcpuclockid");
   if (::clock_getres(CLOCK_MONOTONIC, &res) == 0 &&
       ::clock_gettime(CLOCK_MONOTONIC, &tp)  == 0) {
     // yes, monotonic clock is supported
     _clock_gettime = ::clock_gettime;
+    return;
   }
-  _getcpuclockid = (int (*)(pthread_t, clockid_t *))dlsym(RTLD_DEFAULT, "pthread_getcpuclockid");
+  warning("No monotonic clock was available - timed services may " \
+          "be adversely affected if the time-of-day clock changes");
 }
 #endif
 
@@ -1117,7 +1121,7 @@ jlong os::javaTimeNanos() {
 jlong os::javaTimeNanos() {
   if (Bsd::supports_monotonic_clock()) {
     struct timespec tp;
-    int status = Bsd::_clock_gettime(CLOCK_MONOTONIC, &tp);
+    int status = ::clock_gettime(CLOCK_MONOTONIC, &tp);
     assert(status == 0, "gettime error");
     jlong result = jlong(tp.tv_sec) * (1000 * 1000 * 1000) + jlong(tp.tv_nsec);
     return result;
@@ -3721,6 +3725,25 @@ void os::init(void) {
   Bsd::clock_init();
   initial_time_count = javaTimeNanos();
 
+  // pthread_condattr initialization for monotonic clock
+  int status;
+  pthread_condattr_t* _condattr = os::Bsd::condAttr();
+  if ((status = pthread_condattr_init(_condattr)) != 0) {
+    fatal(err_msg("pthread_condattr_init: %s", strerror(status)));
+  }
+  // Only set the clock if CLOCK_MONOTONIC is available
+  if (Bsd::supports_monotonic_clock()) {
+    if ((status = pthread_condattr_setclock(_condattr, CLOCK_MONOTONIC)) != 0) {
+      if (status == EINVAL) {
+        warning("Unable to use monotonic clock with relative timed-waits" \
+                " - changes to the time-of-day clock may have adverse affects");
+      } else {
+        fatal(err_msg("pthread_condattr_setclock: %s", strerror(status)));
+      }
+    }
+  }
+  // else it defaults to CLOCK_REALTIME
+
 #ifdef __APPLE__
   // XXXDARWIN
   // Work around the unaligned VM callbacks in hotspot's
@@ -4483,21 +4506,36 @@ void os::pause() {
 
 static struct timespec* compute_abstime(struct timespec* abstime, jlong millis) {
   if (millis < 0)  millis = 0;
-  struct timeval now;
-  int status = gettimeofday(&now, NULL);
-  assert(status == 0, "gettimeofday");
+
   jlong seconds = millis / 1000;
   millis %= 1000;
   if (seconds > 50000000) { // see man cond_timedwait(3T)
     seconds = 50000000;
   }
-  abstime->tv_sec = now.tv_sec  + seconds;
-  long       usec = now.tv_usec + millis * 1000;
-  if (usec >= 1000000) {
-    abstime->tv_sec += 1;
-    usec -= 1000000;
+
+  if (os::Bsd::supports_monotonic_clock()) {
+    struct timespec now;
+    int status = ::clock_gettime(CLOCK_MONOTONIC, &now);
+    assert_status(status == 0, status, "clock_gettime");
+    abstime->tv_sec = now.tv_sec  + seconds;
+    long nanos = now.tv_nsec + millis * NANOSECS_PER_MILLISEC;
+    if (nanos >= NANOSECS_PER_SEC) {
+      abstime->tv_sec += 1;
+      nanos -= NANOSECS_PER_SEC;
+    }
+    abstime->tv_nsec = nanos;
+  } else {
+    struct timeval now;
+    int status = gettimeofday(&now, NULL);
+    assert(status == 0, "gettimeofday");
+    abstime->tv_sec = now.tv_sec  + seconds;
+    long usec = now.tv_usec + millis * 1000;
+    if (usec >= 1000000) {
+      abstime->tv_sec += 1;
+      usec -= 1000000;
+    }
+    abstime->tv_nsec = usec * 1000;
   }
-  abstime->tv_nsec = usec * 1000;
   return abstime;
 }
 
@@ -4589,7 +4627,7 @@ int os::PlatformEvent::park(jlong millis
     status = os::Bsd::safe_cond_timedwait(_cond, _mutex, &abst);
     if (status != 0 && WorkAroundNPTLTimedWaitHang) {
       pthread_cond_destroy (_cond);
-      pthread_cond_init (_cond, NULL) ;
+      pthread_cond_init (_cond, os::Bsd::condAttr()) ;
     }
     assert_status(status == 0 || status == EINTR ||
                   status == ETIMEDOUT,
@@ -4690,32 +4728,50 @@ void os::PlatformEvent::unpark() {
 
 static void unpackTime(struct timespec* absTime, bool isAbsolute, jlong time) {
   assert (time > 0, "convertTime");
+  time_t max_secs = 0;
 
-  struct timeval now;
-  int status = gettimeofday(&now, NULL);
-  assert(status == 0, "gettimeofday");
+  if (!os::Bsd::supports_monotonic_clock() || isAbsolute) {
+    struct timeval now;
+    int status = gettimeofday(&now, NULL);
+    assert(status == 0, "gettimeofday");
 
-  time_t max_secs = now.tv_sec + MAX_SECS;
+    max_secs = now.tv_sec + MAX_SECS;
 
-  if (isAbsolute) {
-    jlong secs = time / 1000;
-    if (secs > max_secs) {
-      absTime->tv_sec = max_secs;
-    }
-    else {
-      absTime->tv_sec = secs;
+    if (isAbsolute) {
+      jlong secs = time / 1000;
+      if (secs > max_secs) {
+        absTime->tv_sec = max_secs;
+      } else {
+        absTime->tv_sec = secs;
+      }
+      absTime->tv_nsec = (time % 1000) * NANOSECS_PER_MILLISEC;
+    } else {
+      jlong secs = time / NANOSECS_PER_SEC;
+      if (secs >= MAX_SECS) {
+        absTime->tv_sec = max_secs;
+        absTime->tv_nsec = 0;
+      } else {
+        absTime->tv_sec = now.tv_sec + secs;
+        absTime->tv_nsec = (time % NANOSECS_PER_SEC) + now.tv_usec*1000;
+        if (absTime->tv_nsec >= NANOSECS_PER_SEC) {
+          absTime->tv_nsec -= NANOSECS_PER_SEC;
+          ++absTime->tv_sec; // note: this must be <= max_secs
+        }
+      }
     }
-    absTime->tv_nsec = (time % 1000) * NANOSECS_PER_MILLISEC;
-  }
-  else {
+  } else {
+    // must be relative using monotonic clock
+    struct timespec now;
+    int status = ::clock_gettime(CLOCK_MONOTONIC, &now);
+    assert_status(status == 0, status, "clock_gettime");
+    max_secs = now.tv_sec + MAX_SECS;
     jlong secs = time / NANOSECS_PER_SEC;
     if (secs >= MAX_SECS) {
       absTime->tv_sec = max_secs;
       absTime->tv_nsec = 0;
-    }
-    else {
+    } else {
       absTime->tv_sec = now.tv_sec + secs;
-      absTime->tv_nsec = (time % NANOSECS_PER_SEC) + now.tv_usec*1000;
+      absTime->tv_nsec = (time % NANOSECS_PER_SEC) + now.tv_nsec;
       if (absTime->tv_nsec >= NANOSECS_PER_SEC) {
         absTime->tv_nsec -= NANOSECS_PER_SEC;
         ++absTime->tv_sec; // note: this must be <= max_secs
@@ -4795,15 +4851,19 @@ void Parker::park(bool isAbsolute, jlong
   jt->set_suspend_equivalent();
   // cleared by handle_special_suspend_equivalent_condition() or java_suspend_self()
 
+  assert(_cur_index == -1, "invariant");
   if (time == 0) {
-    status = pthread_cond_wait (_cond, _mutex) ;
+    _cur_index = REL_INDEX; // arbitrary choice when not timed
+    status = pthread_cond_wait (&_cond[_cur_index], _mutex) ;
   } else {
-    status = os::Bsd::safe_cond_timedwait (_cond, _mutex, &absTime) ;
+    _cur_index = isAbsolute ? ABS_INDEX : REL_INDEX;
+    status = os::Bsd::safe_cond_timedwait (&_cond[_cur_index], _mutex, &absTime) ;
     if (status != 0 && WorkAroundNPTLTimedWaitHang) {
-      pthread_cond_destroy (_cond) ;
-      pthread_cond_init    (_cond, NULL);
+      pthread_cond_destroy (&_cond[_cur_index]) ;
+      pthread_cond_init    (&_cond[_cur_index], isAbsolute ? NULL : os::Bsd::condAttr());
     }
   }
+  _cur_index = -1;
   assert_status(status == 0 || status == EINTR ||
                 status == ETIMEDOUT,
                 status, "cond_timedwait");
@@ -4832,17 +4892,26 @@ void Parker::unpark() {
   s = _counter;
   _counter = 1;
   if (s < 1) {
-     if (WorkAroundNPTLTimedWaitHang) {
-        status = pthread_cond_signal (_cond) ;
-        assert (status == 0, "invariant") ;
+    // thread might be parked
+    if (_cur_index != -1) {
+      // thread is definitely parked
+      if (WorkAroundNPTLTimedWaitHang) {
+        status = pthread_cond_signal (&_cond[_cur_index]);
+        assert (status == 0, "invariant");
         status = pthread_mutex_unlock(_mutex);
-        assert (status == 0, "invariant") ;
-     } else {
+        assert (status == 0, "invariant");
+      } else {
+        // must capture correct index before unlocking
+        int index = _cur_index;
         status = pthread_mutex_unlock(_mutex);
-        assert (status == 0, "invariant") ;
-        status = pthread_cond_signal (_cond) ;
-        assert (status == 0, "invariant") ;
-     }
+        assert (status == 0, "invariant");
+        status = pthread_cond_signal (&_cond[index]);
+        assert (status == 0, "invariant");
+      }
+    } else {
+      pthread_mutex_unlock(_mutex);
+      assert (status == 0, "invariant") ;
+    }
   } else {
     pthread_mutex_unlock(_mutex);
     assert (status == 0, "invariant") ;
