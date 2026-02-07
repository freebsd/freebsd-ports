--- HP2100/hp2100_cpu1.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_cpu1.c
@@ -193,11 +193,12 @@ OPS op;
 uint32 rs, qs, sc, v1, v2, t;
 int32 sop1, sop2;
 
-if ((cpu_unit.flags & UNIT_EAU) == 0)                   /* option installed? */
+if ((cpu_unit.flags & UNIT_EAU) == 0) {                 /* option installed? */
     if ((UNIT_CPU_MODEL == UNIT_2114) && (IR == 0101100))   /* 2114 and RRR 16? */
         return SCPE_OK;                                 /* allowed as NOP */
     else
         return stop_inst;                               /* fail */
+}
 
 switch ((IR >> 8) & 0377) {                             /* decode IR<15:8> */
 
@@ -245,7 +246,7 @@ switch ((IR >> 8) & 0377) {             
 
         case 010:                                       /* MPY 100200 (OP_K) */
         MPY:
-            if (reason = cpu_ops (OP_K, op, intrq))     /* get operand */
+            if ((reason = cpu_ops (OP_K, op, intrq)))   /* get operand */
                 break;
             sop1 = SEXT (AR);                           /* sext AR */
             sop2 = SEXT (op[0].word);                   /* sext mem */
@@ -262,9 +263,9 @@ switch ((IR >> 8) & 0377) {             
         break;
 
     case 0201:                                          /* DIV 100400 (OP_K) */
-        if (reason = cpu_ops (OP_K, op, intrq))         /* get operand */
+        if ((reason = cpu_ops (OP_K, op, intrq)))       /* get operand */
             break;
-        if (rs = qs = BR & SIGN) {                      /* save divd sign, neg? */
+        if ((rs = qs = BR & SIGN)) {                    /* save divd sign, neg? */
             AR = (~AR + 1) & DMASK;                     /* make B'A pos */
             BR = (~BR + (AR == 0)) & DMASK;             /* make divd pos */
             }
@@ -317,14 +318,14 @@ switch ((IR >> 8) & 0377) {             
         break;
 
     case 0210:                                          /* DLD 104200 (OP_D) */
-        if (reason = cpu_ops (OP_D, op, intrq))         /* get operand */
+        if ((reason = cpu_ops (OP_D, op, intrq)))       /* get operand */
             break;
         AR = (op[0].dword >> 16) & DMASK;               /* load AR */
         BR = op[0].dword & DMASK;                       /* load BR */
         break;
 
     case 0211:                                          /* DST 104400 (OP_A) */
-        if (reason = cpu_ops (OP_A, op, intrq))         /* get operand */
+        if ((reason = cpu_ops (OP_A, op, intrq)))       /* get operand */
             break;
         WriteW (op[0].word, AR);                        /* store AR */
         WriteW ((op[0].word + 1) & VAMASK, BR);         /* store BR */
@@ -734,7 +735,7 @@ for (i = 0; i < OP_N_F; i++) {
     flags = pattern & OP_M_FLAGS;                       /* get operand pattern */
 
     if (flags >= OP_ADR)                                /* address operand? */
-        if (reason = resolve (ReadW (PC), &MA, irq))    /* resolve indirects */
+        if ((reason = resolve (ReadW (PC), &MA, irq)))  /* resolve indirects */
             return reason;
 
     switch (flags) {
