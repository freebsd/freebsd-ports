--- src/avrcore.c.orig	Fri Jan  2 04:01:01 2004
+++ src/avrcore.c	Wed Jan 12 22:31:53 2005
@@ -1067,6 +1067,9 @@
 
     signal_watch_stop (SIGINT);
 
+    /* avoid division by zero below */
+    if (run_time == 0) run_time = 1;
+
     avr_message ("Run time was %lld.%03lld seconds.\n", run_time / 1000,
                  run_time % 1000);
     avr_message ("Executed %lld instructions.\n", cnt);
