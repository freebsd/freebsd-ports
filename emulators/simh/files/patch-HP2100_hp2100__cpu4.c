--- HP2100/hp2100_cpu4.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_cpu4.c
@@ -261,7 +261,7 @@ else
 entry = opcode & 0177;                                  /* map to <6:0> */
 
 if (op_fpp[entry] != OP_N)
-    if (reason = cpu_ops (op_fpp[entry], op, intrq))    /* get instruction operands */
+    if ((reason = cpu_ops (op_fpp[entry], op, intrq)))  /* get instruction operands */
         return reason;
 
 switch (entry) {                                        /* decode IR<6:0> */
@@ -600,7 +600,7 @@ static const OP t_one  = { { 0040000, 00
 entry = IR & 017;                                       /* mask to entry point */
 
 if (op_sis[entry] != OP_N)
-    if (reason = cpu_ops (op_sis[entry], op, intrq))    /* get instruction operands */
+    if ((reason = cpu_ops (op_sis[entry], op, intrq)))  /* get instruction operands */
         return reason;
 
 switch (entry) {                                        /* decode IR<3:0> */
