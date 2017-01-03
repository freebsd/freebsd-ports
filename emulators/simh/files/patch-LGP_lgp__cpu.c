--- LGP/lgp_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ LGP/lgp_cpu.c
@@ -288,7 +288,7 @@ if (lgp21_sov) {                        
 
 do {
     if (sim_interval <= 0) {                            /* check clock queue */
-        if (r = sim_process_event ())
+        if ((r = sim_process_event ()))
             break;
         }
 
@@ -308,7 +308,7 @@ do {
     PC = (PC + 1) & AMASK;                              /* increment PC */
     sim_interval = sim_interval - 1;
 
-    if (r = cpu_one_inst (oPC, IR)) {                   /* one instr; error? */
+    if ((r = cpu_one_inst (oPC, IR))) {                 /* one instr; error? */
         if (r == STOP_STALL) {                          /* stall? */
             PC = oPC;                                   /* back up PC */
             delay = r = 0;                              /* no delay */
@@ -744,7 +744,7 @@ if (cptr) {
 else inst = IR;
 while ((r = cpu_one_inst (PC, inst)) == STOP_STALL) {
     sim_interval = 0;
-    if (r = sim_process_event ())
+    if ((r = sim_process_event ()))
         return r;
     }
 return r;
