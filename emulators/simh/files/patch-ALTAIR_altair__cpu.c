--- ALTAIR/altair_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ ALTAIR/altair_cpu.c
@@ -313,7 +313,7 @@ int32 sim_instr (void)
 
     while (reason == 0) {                               /* loop until halted */
         if (sim_interval <= 0) {                        /* check clock queue */
-            if (reason = sim_process_event ()) break;
+            if ((reason = sim_process_event ())) break;
         }
 
         if (int_req > 0) {                              /* interrupt? */
@@ -366,7 +366,7 @@ int32 sim_instr (void)
         if ((OP & 0xCF) == 0x01) {                      /* LXI */
             DAR = M[PC] & 0x00ff;
             PC++;
-            DAR = DAR | (M[PC] <<8) & 0xFF00;;
+            DAR = DAR | ((M[PC] <<8) & 0xFF00);
             putpair((OP >> 4) & 0x03, DAR);
             PC++;
             continue;
