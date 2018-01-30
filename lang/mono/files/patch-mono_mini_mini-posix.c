--- mono/mini/mini-posix.c.orig	2017-07-20 18:10:59 UTC
+++ mono/mini/mini-posix.c
@@ -588,7 +588,7 @@ clock_init (void)
 		 * makes very little sense as we can only use nanosleep () to sleep on
 		 * real time.
 		 */
-		sampling_posix_clock = CLOCK_PROCESS_CPUTIME_ID;
+		sampling_posix_clock = CLOCK_MONOTONIC;
 		break;
 #endif
 	case MONO_PROFILER_STAT_MODE_REAL: sampling_posix_clock = CLOCK_MONOTONIC; break;
