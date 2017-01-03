--- H316/h316_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ H316/h316_cpu.c
@@ -424,7 +424,7 @@ reason = 0;
 while (reason == 0) {                                   /* loop until halted */
 
 if (sim_interval <= 0) {                                /* check clock queue */
-    if (reason = sim_process_event ())
+    if ((reason = sim_process_event ()))
         break;
     }
 
@@ -458,7 +458,7 @@ if (chan_req) {                         
                 t = iotab[dev] (ioOTA, 0, Read (ad), dev);      /* output word */
                 if ((t & IOT_SKIP) == 0)
                     return STOP_DMAER;
-                if (r = (t >> IOT_V_REASON))
+                if ((r = (t >> IOT_V_REASON)))
                     return r;
                 }
             if (Q_DMA (i)) {                            /* DMA? */
@@ -528,7 +528,7 @@ if (hst_lnt) {                          
 switch (I_GETOP (MB)) {                                 /* case on <1:6> */
 
     case 001: case 021: case 041: case 061:             /* JMP */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         PCQ_ENTRY;                                      /* save PC */
         PC = NEWA (PC, Y);                              /* set new PC */
@@ -537,7 +537,7 @@ switch (I_GETOP (MB)) {                 
         break;
 
     case 002: case 022: case 042: case 062:             /* LDA */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         if (dp) {                                       /* double prec? */
             AR = Read (Y & ~1);                         /* get doubleword */
@@ -548,13 +548,13 @@ switch (I_GETOP (MB)) {                 
         break;
 
     case 003: case 023: case 043: case 063:             /* ANA */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         AR = AR & Read (Y);
         break;
 
     case 004: case 024: case 044: case 064:             /* STA */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         Write (Y, AR);                                  /* store A */
         if (dp) {                                       /* double prec? */
@@ -564,13 +564,13 @@ switch (I_GETOP (MB)) {                 
         break;
 
     case 005: case 025: case 045: case 065:             /* ERA */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         AR = AR ^ Read (Y);
         break;
 
     case 006: case 026: case 046: case 066:             /* ADD */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         if (dp) {                                       /* double prec? */
             t1 = GETDBL_S (AR, BR);                     /* get A'B */
@@ -583,7 +583,7 @@ switch (I_GETOP (MB)) {                 
         break;
 
     case 007: case 027: case 047: case 067:             /* SUB */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         if (dp) {                                       /* double prec? */
             t1 = GETDBL_S (AR, BR);                     /* get A'B */
@@ -596,7 +596,7 @@ switch (I_GETOP (MB)) {                 
         break;
 
     case 010: case 030: case 050: case 070:             /* JST */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         MB = NEWA (Read (Y), PC);                       /* merge old PC */
         Write (Y, MB);
@@ -605,7 +605,7 @@ switch (I_GETOP (MB)) {                 
         break;
 
     case 011: case 031: case 051: case 071:             /* CAS */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         MB = Read (Y);
         if (AR == MB)
@@ -615,7 +615,7 @@ switch (I_GETOP (MB)) {                 
         break;
 
     case 012: case 032: case 052: case 072:             /* IRS */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         MB = (Read (Y) + 1) & DMASK;                    /* incr, rewrite */
         Write (Y, MB);
@@ -624,7 +624,7 @@ switch (I_GETOP (MB)) {                 
         break;
 
     case 013: case 033: case 053: case 073:             /* IMA */
-        if (reason = Ea (MB, &Y))                       /* eff addr */
+        if ((reason = Ea (MB, &Y)))                     /* eff addr */
             break;
         MB = Read (Y);
         Write (Y, AR);                                  /* A to mem */
@@ -632,13 +632,13 @@ switch (I_GETOP (MB)) {                 
         break;
 
     case 015: case 055:                                 /* STX */
-        if (reason = Ea (MB & ~IDX, &Y))                /* eff addr */
+        if ((reason = Ea (MB & ~IDX, &Y)))              /* eff addr */
             break;
         Write (Y, XR);                                  /* store XR */
         break;
 
     case 035: case 075:                                 /* LDX */
-        if (reason = Ea (MB & ~IDX, &Y))                /* eff addr */
+        if ((reason = Ea (MB & ~IDX, &Y)))              /* eff addr */
             break;
         XR = Read (Y);                                  /* load XR */
         M[M_XR] = XR;                                   /* update mem too */
@@ -646,7 +646,7 @@ switch (I_GETOP (MB)) {                 
 
     case 016: case 036: case 056: case 076:             /* MPY */
         if (cpu_unit.flags & UNIT_HSA) {                /* installed? */
-            if (reason = Ea (MB, &Y))                   /* eff addr */
+            if ((reason = Ea (MB, &Y)))                 /* eff addr */
                 break;
             t1 = SEXT (AR) * SEXT (Read (Y));
             PUTDBL_Z (t1);
@@ -657,7 +657,7 @@ switch (I_GETOP (MB)) {                 
 
     case 017: case 037: case 057: case 077:             /* DIV */
         if (cpu_unit.flags & UNIT_HSA) {                /* installed? */
-            if (reason = Ea (MB, &Y))                   /* eff addr */
+            if ((reason = Ea (MB, &Y)))                 /* eff addr */
                 break;
             t2 = SEXT (Read (Y));                       /* divr */
             if (t2) {                                   /* divr != 0? */
@@ -826,7 +826,7 @@ switch (I_GETOP (MB)) {                 
             break;
 
         case 003:                                       /* "long right arot" */
-            if (reason = stop_inst)                     /* stop on undef? */
+            if ((reason = stop_inst))                   /* stop on undef? */
                 break;
             for (t2 = 0; t2 < t1; t2++) {               /* bit by bit */
                 C = BR & 1;                             /* C = last out */
@@ -859,7 +859,7 @@ switch (I_GETOP (MB)) {                 
             break;
 
         case 007:                                       /* "short right arot" */
-            if (reason = stop_inst)                     /* stop on undef? */
+            if ((reason = stop_inst))                   /* stop on undef? */
                 break;
             for (t2 = 0; t2 < t1; t2++) {               /* bit by bit */
                 C = AR & 1;                             /* C = last out */
@@ -899,7 +899,7 @@ switch (I_GETOP (MB)) {                 
             break;
 
         case 013:                                       /* "long left arot" */
-            if (reason = stop_inst)                     /* stop on undef? */
+            if ((reason = stop_inst))                   /* stop on undef? */
                 break;
             for (t2 = 0; t2 < t1; t2++) {               /* bit by bit */
                 AR = (AR << 1) | ((BR >> 14) & 1);
@@ -935,7 +935,7 @@ switch (I_GETOP (MB)) {                 
             break;
 
         case 017:                                       /* "short left arot" */
-            if (reason = stop_inst)                     /* stop on undef? */
+            if ((reason = stop_inst))                   /* stop on undef? */
                 break;
             for (t2 = 0; t2 < t1; t2++) {               /* bit by bit */
                 if ((AR & SIGN) != ((AR << 1) & SIGN)) C = 1;
@@ -1003,7 +1003,7 @@ switch (I_GETOP (MB)) {                 
             AR = (AR << 8) & DMASK;
         else if (MB == 0141340)                         /* ICA */
             AR = ((AR << 8) | (AR >> 8)) & DMASK;
-        else if (reason = stop_inst)
+        else if ((reason = stop_inst))
             break;
         else AR = Operate (MB, AR);                     /* undefined */
         break;
@@ -1500,7 +1500,7 @@ for (i = 0; i < DEV_MAX; i++)
     iotab[i] = NULL;
 for (i = 0; i < (DMA_MAX + DMC_MAX); i++)
     chan_map[i] = 0;
-for (i = 0; dptr = sim_devices[i]; i++) {               /* loop thru devices */
+for (i = 0; (dptr = sim_devices[i]); i++) {             /* loop thru devices */
     dibp = (DIB *) dptr->ctxt;                          /* get DIB */
     if ((dibp == NULL) || (dptr->flags & DEV_DIS))      /* exist, enabled? */
         continue;
