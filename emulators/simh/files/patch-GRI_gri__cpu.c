--- GRI/gri_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ GRI/gri_cpu.c
@@ -421,7 +421,7 @@ ao_update ();                           
 while (reason == 0) {                                   /* loop until halted */
 
     if (sim_interval <= 0) {                            /* check clock queue */
-        if (reason = sim_process_event ())
+        if ((reason = sim_process_event ()))
             break;
         }
 
