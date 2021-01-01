--- src/timer_clockgettime.c.orig	2019-05-07 16:36:51 UTC
+++ src/timer_clockgettime.c
@@ -75,16 +75,16 @@ static struct fakeclock* clkid_to_fakeclock(clockid_t 
 	switch(clk_id) {
 	case CLOCK_REALTIME:
 		return &realtime;
-	case CLOCK_REALTIME_COARSE:
-		return &realtime_coarse;
+//	case CLOCK_REALTIME_COARSE:
+//		return &realtime_coarse;
 	case CLOCK_MONOTONIC:
 		return &mono;
-	case CLOCK_MONOTONIC_COARSE:
-		return &mono_coarse;
-	case CLOCK_MONOTONIC_RAW:
-		return &mono_raw;
-	case CLOCK_BOOTTIME:
-		return &boottime;
+//	case CLOCK_MONOTONIC_COARSE:
+//		return &mono_coarse;
+//	case CLOCK_MONOTONIC_RAW:
+//		return &mono_raw;
+//	case CLOCK_BOOTTIME:
+//		return &boottime;
 	case CLOCK_PROCESS_CPUTIME_ID:
 		return &proc_cputime_id;
 	case CLOCK_THREAD_CPUTIME_ID:
