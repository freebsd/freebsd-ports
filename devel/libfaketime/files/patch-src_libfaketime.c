--- src/libfaketime.c.orig	2025-06-09 12:31:15 UTC
+++ src/libfaketime.c
@@ -41,9 +41,15 @@
 #endif
 #endif
 #include <time.h>
-#ifdef MACOS_DYLD_INTERPOSE
+#if defined (MACOS_DYLD_INTERPOSE) || defined (__FreeBSD__)
 #include <pthread.h>
+#ifdef __FreeBSD__
+#define gettimeofday bsd_gettimeofday
+#endif
 #include <sys/time.h>
+#ifdef __FreeBSD__
+#undef gettimeofday
+#endif
 #include <utime.h>
 #endif
 #include <math.h>
@@ -151,6 +157,14 @@ void do_macos_dyld_interpose(void);
 #define CLOCK_MONOTONIC_RAW (CLOCK_MONOTONIC + 1)
 #endif
 
+/* On some platforms (e.g. FreeBSD 15) CLOCK_BOOTTIME is an alias of another clock.
+ * Only treat BOOTTIME as distinct if its value differs from MONOTONIC and MONOTONIC_RAW. */
+#if defined(CLOCK_BOOTTIME) && \
+    (CLOCK_BOOTTIME != CLOCK_MONOTONIC) && \
+    (CLOCK_BOOTTIME != CLOCK_MONOTONIC_RAW)
+#define HAVE_DISTINCT_CLOCK_BOOTTIME 1
+#endif
+
 #if defined FAKE_UTIME && !defined FAKE_FILE_TIMESTAMPS
 #define FAKE_FILE_TIMESTAMPS
 #endif
@@ -718,7 +732,7 @@ static void system_time_from_system (struct system_tim
    ;
   DONT_FAKE_TIME((*real_clock_gettime)(CLOCK_MONOTONIC_RAW, &systime->mon_raw))
    ;
-#ifdef CLOCK_BOOTTIME
+#ifdef HAVE_DISTINCT_CLOCK_BOOTTIME
   DONT_FAKE_TIME((*real_clock_gettime)(CLOCK_BOOTTIME, &systime->boot))
    ;
 #endif
@@ -2384,7 +2398,7 @@ int clock_gettime(clockid_t clk_id, struct timespec *t
 #ifdef CLOCK_MONOTONIC_COARSE
       && clk_id != CLOCK_MONOTONIC_COARSE
 #endif
-#ifdef CLOCK_BOOTTIME
+#ifdef HAVE_DISTINCT_CLOCK_BOOTTIME
       && clk_id != CLOCK_BOOTTIME
 #endif
       ))
@@ -2619,7 +2633,7 @@ parse_modifiers:
             ftpl_starttime.mon.tv_nsec       = ftpl_timecache.mon.tv_nsec;
             ftpl_starttime.mon_raw.tv_sec    = ftpl_timecache.mon_raw.tv_sec;
             ftpl_starttime.mon_raw.tv_nsec   = ftpl_timecache.mon_raw.tv_nsec;
-#ifdef CLOCK_BOOTTIME
+#ifdef HAVE_DISTINCT_CLOCK_BOOTTIME
             ftpl_starttime.boot.tv_sec       = ftpl_timecache.boot.tv_sec;
             ftpl_starttime.boot.tv_nsec      = ftpl_timecache.boot.tv_nsec;
 #endif
@@ -3302,7 +3316,7 @@ int fake_clock_gettime(clockid_t clk_id, struct timesp
       case CLOCK_MONOTONIC_RAW:
         timespecsub(tp, &ftpl_starttime.mon_raw, &tmp_ts);
         break;
-#ifdef CLOCK_BOOTTIME
+#ifdef HAVE_DISTINCT_CLOCK_BOOTTIME
       case CLOCK_BOOTTIME:
         timespecsub(tp, &ftpl_starttime.boot, &tmp_ts);
         break;
@@ -3447,7 +3461,7 @@ int fake_clock_gettime(clockid_t clk_id, struct timesp
           case CLOCK_MONOTONIC_RAW:
             timespecsub(tp, &ftpl_starttime.mon_raw, &tdiff);
             break;
-#ifdef CLOCK_BOOTTIME
+#ifdef HAVE_DISTINCT_CLOCK_BOOTTIME
           case CLOCK_BOOTTIME:
             timespecsub(tp, &ftpl_starttime.boot, &tdiff);
             break;
@@ -3503,7 +3517,7 @@ abort:
     ftpl_faketimecache.mon_raw.tv_sec  = tp->tv_sec;
     ftpl_faketimecache.mon_raw.tv_nsec = tp->tv_nsec;
   }
-#ifdef CLOCK_BOOTTIME
+#ifdef HAVE_DISTINCT_CLOCK_BOOTTIME
   else if (clk_id == CLOCK_BOOTTIME)
   {
     ftpl_timecache.boot.tv_sec         = tp_save.tv_sec;
@@ -3632,7 +3646,7 @@ int __clock_gettime(clockid_t clk_id, struct timespec 
 #ifdef CLOCK_MONOTONIC_COARSE
       && clk_id != CLOCK_MONOTONIC_COARSE
 #endif
-#ifdef CLOCK_BOOTTIME
+#ifdef HAVE_DISTINCT_CLOCK_BOOTTIME
       && clk_id != CLOCK_BOOTTIME
 #endif
       ))
