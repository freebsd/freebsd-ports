--- Interdata/id16_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ Interdata/id16_cpu.c
@@ -604,7 +604,7 @@ while (reason == 0) {                   
     int32 sr, st;
 
     if (sim_interval <= 0) {                            /* check clock queue */
-        if (reason = sim_process_event ())
+        if ((reason = sim_process_event ()))
             break;
         int_eval ();
         }
