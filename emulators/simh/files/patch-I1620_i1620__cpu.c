--- I1620/i1620_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ I1620/i1620_cpu.c
@@ -476,7 +476,7 @@ while (reason == 0) {                   
 
     saved_PC = PC;                                      /* commit prev instr */
     if (sim_interval <= 0) {                            /* check clock queue */
-        if (reason = sim_process_event ())
+        if ((reason = sim_process_event ()))
             break;
         }
 
