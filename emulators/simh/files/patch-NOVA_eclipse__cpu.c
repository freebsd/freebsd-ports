--- NOVA/eclipse_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ NOVA/eclipse_cpu.c
@@ -744,7 +744,7 @@ if (MapInit == 0) {
 
 while (reason == 0) {                                   /* loop until halted */
 if (sim_interval <= 0) {                                /* check clock queue */
-    if (reason = sim_process_event ()) 
+    if ((reason = sim_process_event ())) 
         break;
 }
 
