--- src/nettest_unix.c.orig	2012-06-19 22:35:37.000000000 +0200
+++ src/nettest_unix.c	2015-10-19 16:15:15.347526000 +0200
@@ -2714,7 +2714,6 @@
        that sort of rot... */
 
 #ifdef WANT_INTERVALS
-    kept_times[MAX_KEPT_TIMES] = 0;
     time_index = 0;
     while (time_index < MAX_KEPT_TIMES) {
       if (kept_times[time_index] > 0) {
