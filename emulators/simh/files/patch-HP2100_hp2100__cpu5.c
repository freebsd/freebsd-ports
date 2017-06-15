--- HP2100/hp2100_cpu5.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_cpu5.c
@@ -650,7 +650,7 @@ entry = IR & 017;                       
 pattern = op_vma[entry];                            /* get operand pattern */
 
 if (pattern != OP_N)
-    if (reason = cpu_ops (pattern, op, intrq))      /* get instruction operands */
+    if ((reason = cpu_ops (pattern, op, intrq)))    /* get instruction operands */
         return reason;
 
 if (debug) {                                            /* debugging? */
@@ -1361,7 +1361,7 @@ entry = IR & 017;                       
 pattern = op_ema[entry];                                /* get operand pattern */
 
 if (pattern != OP_N)
-    if (reason = cpu_ops (pattern, op, intrq))          /* get instruction operands */
+    if ((reason = cpu_ops (pattern, op, intrq)))        /* get instruction operands */
         return reason;
 
 if (debug) {                                            /* debugging? */
