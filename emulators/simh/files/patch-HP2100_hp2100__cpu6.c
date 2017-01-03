--- HP2100/hp2100_cpu6.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_cpu6.c
@@ -394,7 +394,7 @@ entry = IR & 017;                       
 pattern = op_os[entry];                                 /* get operand pattern */
 
 if (pattern != OP_N)
-    if (reason = cpu_ops (pattern, op, intrq))          /* get instruction operands */
+    if ((reason = cpu_ops (pattern, op, intrq)))        /* get instruction operands */
         return reason;
 
 tbg_tick = tbg_tick || (IR == 0105357) && iotrap;       /* set TBG interrupting flag */
@@ -544,7 +544,7 @@ switch (entry) {                        
         for (i = 0; i < count; i++) {
             ma = ReadW (PC);                            /* get operand address */
 
-            if (reason = resolve (ma, &ma, intrq)) {    /* resolve indirect */
+            if ((reason = resolve (ma, &ma, intrq))) {  /* resolve indirect */
                 PC = err_PC;                            /* IRQ restarts instruction */
                 break;
                 }
@@ -710,7 +710,7 @@ switch (entry) {                        
                 ma = ReadW (sa);                        /* get addr of actual */
                 sa = (sa + 1) & VAMASK;                 /* increment address */
 
-                if (reason = resolve (ma, &ma, intrq)) {    /* resolve indirect */
+                if ((reason = resolve (ma, &ma, intrq))) {  /* resolve indirect */
                     PC = err_PC;                            /* irq restarts instruction */
                     break;
                     }
