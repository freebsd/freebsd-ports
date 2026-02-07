--- Ibm1130/ibm1130_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ Ibm1130/ibm1130_cpu.c
@@ -768,7 +768,7 @@ t_stat sim_instr (void)
 								CCC--;
 							}
 							C = (CCC != 0);
-							WriteIndex(TAG, ReadIndex(TAG) & 0xFF00 | CCC);		/* put 6 bits back into low byte of index register */
+							WriteIndex(TAG, (ReadIndex(TAG) & 0xFF00) | CCC);	/* put 6 bits back into low byte of index register */
 							break;
 						}
 						/* if TAG == 0, fall through and treat like normal shift SLT */
@@ -814,8 +814,8 @@ t_stat sim_instr (void)
 						while (CCC > 0) {
 							xbit = (ACC & 0x0001) << 15;
 							abit = (ACC & 0x8000);
-							ACC  = (ACC >> 1) & 0x7FFF | abit;
-							EXT  = (EXT >> 1) & 0x7FFF | xbit;
+							ACC  = ((ACC >> 1) & 0x7FFF) | abit;
+							EXT  = ((EXT >> 1) & 0x7FFF) | xbit;
 							CCC--;
 						}
 						break;
@@ -824,8 +824,8 @@ t_stat sim_instr (void)
 						while (CCC > 0) {
 							abit = (EXT & 0x0001) << 15;
 							xbit = (ACC & 0x0001) << 15;
-							ACC  = (ACC >> 1) & 0x7FFF | abit;
-							EXT  = (EXT >> 1) & 0x7FFF | xbit;
+							ACC  = ((ACC >> 1) & 0x7FFF) | abit;
+							EXT  = ((EXT >> 1) & 0x7FFF) | xbit;
 							CCC--;
 						}
 						break;
