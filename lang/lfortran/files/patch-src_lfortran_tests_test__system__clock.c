--- src/lfortran/tests/test_system_clock.c.orig	2026-10-25 06:06:38 UTC
+++ src/lfortran/tests/test_system_clock.c
@@ -1,9 +1,14 @@
+#if defined(__linux__)
+#define _GNU_SOURCE  /* for syscall() */
+#endif
 #include <inttypes.h>
 #include <limits.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
+#include <sys/syscall.h>
+#include <unistd.h>
 
 extern int32_t _lfortran_i32sys_clock_count(void);
 extern int32_t _lfortran_i32sys_clock_count_rate(void);
@@ -14,13 +19,16 @@ static int clock_status;
 
 static struct timespec clock_value;
 static int clock_status;
+static int monotonic_calls;
 
-// Interpose the platform clock while testing the actual static runtime.
+// On FreeBSD (and possibly the other BSDs) clock_gettime() returns every
+// values, among them the ones called in libc, e.g. CLOCK_SECOND for time(3)
+// or CLOCK_MONOTONIC_FAST for jemalloc: we have to filter them.
 int clock_gettime(clockid_t clock_id, struct timespec *value) {
     if (clock_id != CLOCK_MONOTONIC) {
-        fprintf(stderr, "unexpected system_clock source\n");
-        exit(1);
+        return (int)syscall(SYS_clock_gettime, clock_id, value);
     }
+    monotonic_calls++;
     *value = clock_value;
     return clock_status;
 }
@@ -29,8 +37,13 @@ static void check_count(time_t seconds, long nanosecon
         int32_t expected32, uint64_t expected64) {
     clock_value.tv_sec = seconds;
     clock_value.tv_nsec = nanoseconds;
+    int calls = monotonic_calls;
     int32_t count32 = _lfortran_i32sys_clock_count();
     uint64_t count64 = _lfortran_i64sys_clock_count();
+    if (monotonic_calls != calls + 2) {
+        fprintf(stderr, "unexpected system_clock source\n");
+        exit(1);
+    }
     if (count32 != expected32 || count64 != expected64) {
         fprintf(stderr, "system_clock: got %" PRId32 ", %" PRIu64
             "; expected %" PRId32 ", %" PRIu64 "\n",
