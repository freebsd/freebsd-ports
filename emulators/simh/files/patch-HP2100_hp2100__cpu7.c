--- HP2100/hp2100_cpu7.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_cpu7.c
@@ -391,7 +391,7 @@ if (pattern != OP_N)
         rtn = rtn1 = ret.word;                           /* but save it just in case */
         PC = (PC + 1) & VAMASK;                          /* move to next argument */
     }
-    if (reason = cpu_ops (pattern, op, intrq))           /* get instruction operands */
+    if ((reason = cpu_ops (pattern, op, intrq)))           /* get instruction operands */
         return reason;
 
 if (debug) {                                             /* debugging? */
@@ -653,7 +653,7 @@ t_bool debug = DEBUG_PRI (cpu_dev, DEB_S
 entry = IR & 017;                                  /* mask to entry point */
 
 if (op_signal[entry] != OP_N)
-    if (reason = cpu_ops (op_signal[entry], op, intrq)) /* get instruction operands */
+    if ((reason = cpu_ops (op_signal[entry], op, intrq))) /* get instruction operands */
         return reason;
 
 if (debug) {                                             /* debugging? */
