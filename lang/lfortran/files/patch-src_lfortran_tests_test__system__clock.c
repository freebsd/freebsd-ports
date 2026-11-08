--- src/lfortran/tests/test_system_clock.c.orig	2026-10-25 06:06:38 UTC
+++ src/lfortran/tests/test_system_clock.c
@@ -14,12 +14,14 @@ static int clock_status;
 
 static struct timespec clock_value;
 static int clock_status;
+static int monotonic_calls;
 
 // Interpose the platform clock while testing the actual static runtime.
+// Other clocks may be queried by libc internals (e.g. on FreeBSD), so only
+// CLOCK_MONOTONIC calls are counted; check_count() verifies the runtime used it.
 int clock_gettime(clockid_t clock_id, struct timespec *value) {
-    if (clock_id != CLOCK_MONOTONIC) {
-        fprintf(stderr, "unexpected system_clock source\n");
-        exit(1);
+    if (clock_id == CLOCK_MONOTONIC) {
+        monotonic_calls++;
     }
     *value = clock_value;
     return clock_status;
@@ -29,8 +31,13 @@ static void check_count(time_t seconds, long nanosecon
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
