--- PDP8/pdp8_cpu.c.orig	2016-12-01 22:43:43 UTC
+++ PDP8/pdp8_cpu.c
@@ -344,7 +344,7 @@ reason = 0;
 while (reason == 0) {                                   /* loop until halted */
 
     if (sim_interval <= 0) {                            /* check clock queue */
-        if (reason = sim_process_event ())
+        if ((reason = sim_process_event ()))
             break;
         }
 
