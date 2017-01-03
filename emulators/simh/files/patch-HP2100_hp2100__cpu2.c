--- HP2100/hp2100_cpu2.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_cpu2.c
@@ -244,7 +244,7 @@ absel = (IR & I_AB)? 1: 0;              
 entry = IR & 037;                                       /* mask to entry point */
 
 if (op_dms[entry] != OP_N)
-    if (reason = cpu_ops (op_dms[entry], op, intrq))    /* get instruction operands */
+    if ((reason = cpu_ops (op_dms[entry], op, intrq)))  /* get instruction operands */
         return reason;
 
 switch (entry) {                                        /* decode IR<3:0> */
@@ -610,7 +610,7 @@ absel = (IR & I_AB)? 1: 0;              
 entry = IR & 037;                                       /* mask to entry point */
 
 if (op_eig[entry] != OP_N)
-    if (reason = cpu_ops (op_eig[entry], op, intrq))    /* get instruction operands */
+    if ((reason = cpu_ops (op_eig[entry], op, intrq)))  /* get instruction operands */
         return reason;
 
 switch (entry) {                                        /* decode IR<4:0> */
@@ -989,7 +989,7 @@ else if (entry <= 057)                  
 entry = entry - 060;                                    /* offset 10x460-477 */
 
 if (op_iop[entry] != OP_N)
-    if (reason = cpu_ops (op_iop[entry], op, intrq))    /* get instruction operands */
+    if ((reason = cpu_ops (op_iop[entry], op, intrq)))  /* get instruction operands */
         return reason;
 
 switch (entry) {                                        /* decode IR<5:0> */
