--- HP2100/hp2100_cpu3.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_cpu3.c
@@ -186,7 +186,7 @@ entry = IR & 037;                       
 
 if (UNIT_CPU_MODEL != UNIT_1000_F) {                    /* 2100/M/E-Series? */
     if (op_ffp_e[entry] != OP_N)
-        if (reason = cpu_ops (op_ffp_e[entry], op, intrq))  /* get instruction operands */
+        if ((reason = cpu_ops (op_ffp_e[entry], op, intrq))) /* get instruction operands */
             return reason;
     }
 
@@ -194,7 +194,7 @@ if (UNIT_CPU_MODEL != UNIT_1000_F) {    
 
 else {                                                  /* F-Series */
     if (op_ffp_f[entry] != OP_N)
-        if (reason = cpu_ops (op_ffp_f[entry], op, intrq))  /* get instruction operands */
+        if ((reason = cpu_ops (op_ffp_f[entry], op, intrq))) /* get instruction operands */
             return reason;
 
     switch (entry) {                                    /* decode IR<4:0> */
@@ -417,7 +417,7 @@ switch (entry) {                        
             sa = op[0].word - 1;
 
         da = ReadW (sa);                                /* get jump target */
-        if (reason = resolve (da, &MA, intrq)) {        /* resolve indirects */
+        if ((reason = resolve (da, &MA, intrq))) {      /* resolve indirects */
             PC = err_PC;                                /* irq restarts instruction */
             break;
             }
@@ -435,7 +435,7 @@ switch (entry) {                        
             op[1].word = op[1].word +                   /* compute element offset */
                          (op[2].word - 1) * op[3].word;
         else {                                          /* 3-dim access */
-            if (reason = cpu_ops (OP_KK, op2, intrq)) { /* get 1st, 2nd ranges */
+            if ((reason = cpu_ops (OP_KK, op2, intrq))) { /* get 1st, 2nd ranges */
                 PC = err_PC;                            /* irq restarts instruction */
                 break;
                 }
@@ -461,7 +461,7 @@ switch (entry) {                        
 
         for (j = 0; j < sc; j++) {
             MA = ReadW (sa++);                          /* get addr of actual */
-            if (reason = resolve (MA, &MA, intrq)) {    /* resolve indirect */
+            if ((reason = resolve (MA, &MA, intrq))) {  /* resolve indirect */
                 PC = err_PC;                            /* irq restarts instruction */
                 break;
                 }
@@ -644,7 +644,7 @@ t_stat reason = SCPE_OK;
 entry = IR & 017;                                       /* mask to entry point */
 
 if (op_dbi[entry] != OP_N)
-    if (reason = cpu_ops (op_dbi[entry], op, intrq))    /* get instruction operands */
+    if ((reason = cpu_ops (op_dbi[entry], op, intrq)))  /* get instruction operands */
         return reason;
 
 switch (entry) {                                        /* decode IR<3:0> */
