--- src/timer_clockgettime.c.orig	2018-07-18 15:04:27 UTC
+++ src/timer_clockgettime.c
@@ -72,16 +72,16 @@ static struct fakeclock* clkid_to_fakecl
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
