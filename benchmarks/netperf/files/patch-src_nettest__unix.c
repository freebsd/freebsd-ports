--- src/nettest_unix.c.orig	2012-06-19 20:35:37 UTC
+++ src/nettest_unix.c
@@ -2714,7 +2714,6 @@ bytes  bytes  bytes   bytes  secs.   per
        that sort of rot... */
 
 #ifdef WANT_INTERVALS
-    kept_times[MAX_KEPT_TIMES] = 0;
     time_index = 0;
     while (time_index < MAX_KEPT_TIMES) {
       if (kept_times[time_index] > 0) {
