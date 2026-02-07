--- PDP1/pdp1_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ PDP1/pdp1_cpu.c
@@ -546,7 +546,7 @@ reason = 0;
 while (reason == 0) {                                   /* loop until halted */
 
     if (sim_interval <= 0) {                            /* check clock queue */
-        if (reason = sim_process_event ())
+        if ((reason = sim_process_event ()))
             break;
         sbs_lvl = sbs_eval ();                          /* eval sbs system */
         }
@@ -610,25 +610,25 @@ while (reason == 0) {                   
 /* Logical, load, store instructions */
 
     case 001:                                           /* AND */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         AC = AC & MB;
         break;
 
     case 002:                                           /* IOR */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         AC = AC | MB;
         break;
 
     case 003:                                           /* XOR */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         AC = AC ^ MB;
         break;
@@ -638,9 +638,9 @@ while (reason == 0) {                   
             reason = STOP_XCT;
             break;
             }
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         xct_count = xct_count + 1;                      /* count XCT's */
         IR = MB;                                        /* get instruction */
@@ -648,9 +648,9 @@ while (reason == 0) {                   
 
     case 005:                                           /* LCH */
         if (cpu_unit.flags & UNIT_1D) {                 /* PDP-1D? */
-            if (reason = Ea_ch (IR, &byno))             /* MA <- eff addr */
+            if ((reason = Ea_ch (IR, &byno)))           /* MA <- eff addr */
                 break;
-            if (reason = Read ())                       /* MB <- data */
+            if ((reason = Read ()))                     /* MB <- data */
                 break;
             AC = (MB << byt_shf[byno]) & 0770000;       /* extract byte */
             }
@@ -659,9 +659,9 @@ while (reason == 0) {                   
 
     case 006:                                           /* DCH */
         if (cpu_unit.flags & UNIT_1D) {                 /* PDP-1D? */
-            if (reason = Ea_ch (IR, &byno))             /* MA <- eff addr */
+            if ((reason = Ea_ch (IR, &byno)))           /* MA <- eff addr */
                 break;
-            if (reason = Read ())                       /* MB <- data */
+            if ((reason = Read ()))                     /* MB <- data */
                 break;
             MB = (MB & ~(0770000 >> byt_shf[byno])) |   /* insert byte */
                 ((AC & 0770000) >> byt_shf[byno]);
@@ -683,55 +683,55 @@ while (reason == 0) {                   
         break;
 
     case 010:                                           /* LAC */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         AC = MB;
         break;
 
     case 011:                                           /* LIO */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         IO = MB;
         break;
 
     case 012:                                           /* DAC */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
         MB = AC;
         reason = Write ();
         break;
 
     case 013:                                           /* DAP */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         MB = (AC & DAMASK) | (MB & ~DAMASK);
         reason = Write ();
         break;
 
     case 014:                                           /* DIP */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         MB = (AC & ~DAMASK) | (MB & DAMASK);
         reason = Write ();
         break;
 
     case 015:                                           /* DIO */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
         MB = IO;
         reason = Write ();
         break;
 
     case 016:                                           /* DZM */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
         MB = 0;
         reason = Write ();
@@ -755,9 +755,9 @@ while (reason == 0) {                   
 
     case 017:                                           /* TAD */
         if (cpu_unit.flags & UNIT_1D) {                 /* PDP-1D? */
-            if (reason = Ea (IR))                       /* MA <- eff addr */
+            if ((reason = Ea (IR)))                     /* MA <- eff addr */
                 break;
-            if (reason = Read ())                       /* MB <- data */
+            if ((reason = Read ()))                     /* MB <- data */
                 break;
             AC = AC + MB + ((PF & PF_L)? 1: 0);         /* AC + opnd + L */
             if (AC > DMASK)                             /* carry? set L */
@@ -769,9 +769,9 @@ while (reason == 0) {                   
         break;
 
     case 020:                                           /* ADD */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         t = AC;
         AC = AC + MB;
@@ -784,9 +784,9 @@ while (reason == 0) {                   
         break;
 
     case 021:                                           /* SUB */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         t = AC ^ DMASK;                                 /* complement AC */
         AC = t + MB;                                    /* -AC + MB */
@@ -798,9 +798,9 @@ while (reason == 0) {                   
         break;
 
     case 022:                                           /* IDX */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         AC = MB + 1;
         if (AC >= DMASK)
@@ -810,9 +810,9 @@ while (reason == 0) {                   
         break;
 
     case 023:                                           /* ISP */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         AC = MB + 1;
         if (AC >= DMASK)
@@ -824,18 +824,18 @@ while (reason == 0) {                   
         break;
 
     case 024:                                           /* SAD */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         if (AC != MB)
             PC = INCR_ADDR (PC);
         break;
 
     case 025:                                           /* SAS */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         if (AC == MB)
             PC = INCR_ADDR (PC);
@@ -863,7 +863,7 @@ while (reason == 0) {                   
                 hst[hst_p].ea = PC;
             }
         else {                                          /* normal JMP */
-            if (reason = Ea (IR))                       /* MA <- eff addr */
+            if ((reason = Ea (IR)))                     /* MA <- eff addr */
                 break;
             PCQ_ENTRY;
             PC = MA;
@@ -871,7 +871,7 @@ while (reason == 0) {                   
         break;
 
     case 031:                                           /* JSP */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
         AC = EPC_WORD;
         PCQ_ENTRY;
@@ -889,9 +889,9 @@ while (reason == 0) {                   
 */   
 
     case 026:                                           /* MUL */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         if (cpu_unit.flags & UNIT_MDV) {                /* hardware? */
             sign = AC ^ MB;                             /* result sign */
@@ -919,9 +919,9 @@ while (reason == 0) {                   
         break;
 
     case 027:                                           /* DIV */
-        if (reason = Ea (IR))                           /* MA <- eff addr */
+        if ((reason = Ea (IR)))                         /* MA <- eff addr */
             break;
-        if (reason = Read ())                           /* MB <- data */
+        if ((reason = Read ()))                         /* MB <- data */
             break;
         if (cpu_unit.flags & UNIT_MDV) {                /* hardware */
             sign = AC ^ MB;                             /* result sign */
@@ -1362,13 +1362,13 @@ t_stat r;
 MA = (PC & EPCMASK) | (IR & DAMASK);                    /* direct address */
 if (IR & IA) {                                          /* indirect addr? */
     if (extm) {                                         /* extend? */
-        if (r = Read ())                                /* read; err? */
+        if ((r = Read ()))                              /* read; err? */
             return r;
         MA = MB & AMASK;                                /* one level */
         }
     else {                                              /* multi-level */
         for (i = 0; i < ind_max; i++) {                 /* count indirects */
-            if (r = Read ())                            /* get ind word */
+            if ((r = Read ()))                          /* get ind word */
                 return r;
             MA = (PC & EPCMASK) | (MB & DAMASK);
             if ((MB & IA) == 0)
@@ -1392,12 +1392,12 @@ t_stat r;
 
 MA = (PC & EPCMASK) | (IR & DAMASK);                    /* direct address */
 if (extm) {                                             /* extend? */
-    if (r = Read ())                                    /* read; err? */
+    if ((r = Read ()))                                  /* read; err? */
         return r;
     }
 else {                                                  /* multi-level */
     for (i = 0; i < ind_max; i++) {                     /* count indirects */
-        if (r = Read ())                                /* get ind word */
+        if ((r = Read ()))                              /* get ind word */
             return r;
         if ((MB & IA) == 0)
             break;
