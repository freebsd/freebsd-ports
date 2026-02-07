--- HP2100/hp2100_cpu0.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_cpu0.c
@@ -130,7 +130,7 @@ uint32 entry;
 entry = IR & 017;                                       /* mask to entry point */
 
 if (op_ds[entry] != OP_N)
-    if (reason = cpu_ops (op_ds[entry], op, intrq))     /* get instruction operands */
+    if ((reason = cpu_ops (op_ds[entry], op, intrq)))   /* get instruction operands */
         return reason;
 
 switch (entry) {                                        /* decode IR<3:0> */
@@ -244,7 +244,7 @@ uint32 entry;
 entry = IR & 017;                                       /* mask to entry point */
 
 if (op_user_20 [entry] != OP_N)
-    if (reason = cpu_ops (op_user_20 [entry], op, intrq))   /* get instruction operands */
+    if ((reason = cpu_ops (op_user_20 [entry], op, intrq))) /* get instruction operands */
         return reason;
 
 switch (entry) {                                        /* decode IR<4:0> */
