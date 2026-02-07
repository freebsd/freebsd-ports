--- S3/s3_cpu.c.orig	2016-12-01 22:43:43 UTC
+++ S3/s3_cpu.c
@@ -527,7 +527,7 @@ reason = 0;
 
 while (reason == 0) {                                   /* loop until halted */
 if (sim_interval <= 0) {                                /* check clock queue */
-    if (reason = sim_process_event ()) break;
+    if ((reason = sim_process_event ())) break;
 }
 
 if (int_req) {                                          /* interrupt? */
