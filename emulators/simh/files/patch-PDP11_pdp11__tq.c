--- PDP11/pdp11_tq.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_tq.c
@@ -780,7 +780,7 @@ else if (mdf & ~tq_cmf[cmd]) {          
     sts = ST_CMD | I_MODF;                              /* ill mods */
     }
 else {                                                  /* valid cmd */
-    if (uptr = tq_getucb (lu)) {                        /* valid unit? */
+    if ((uptr = tq_getucb (lu))) {                      /* valid unit? */
         if (q && (tq_cmf[cmd] & CMF_SEQ) &&             /* queueing, seq, */
             (uptr->cpkt || uptr->pktq)) {               /* and active? */
             tq_enqt (&uptr->pktq, pkt);                 /* do later */
@@ -858,7 +858,7 @@ int32 tpkt, prv;
 UNIT *uptr;
 
 tpkt = 0;                                               /* set no mtch */
-if (uptr = tq_getucb (lu)) {                            /* get unit */
+if ((uptr = tq_getucb (lu))) {                          /* get unit */
     if (uptr->cpkt &&                                   /* curr pkt? */
         (GETP32 (uptr->cpkt, CMD_REFL) == ref)) {       /* match ref? */
         tpkt = uptr->cpkt;                              /* save match */
@@ -871,8 +871,8 @@ if (uptr = tq_getucb (lu)) {            
         tpkt = uptr->pktq;                              /* save match */
         uptr->pktq = tq_pkt[tpkt].link;                 /* unlink */
         }
-    else if (prv = uptr->pktq) {                        /* srch pkt q */
-        while (tpkt = tq_pkt[prv].link) {               /* walk list */
+    else if ((prv = uptr->pktq)) {                      /* srch pkt q */
+        while ((tpkt = tq_pkt[prv].link)) {             /* walk list */
             if (GETP32 (tpkt, RSP_REFL) == ref) {       /* match ref? */
                 tq_pkt[prv].link = tq_pkt[tpkt].link;   /* unlink */
                     break;
@@ -900,7 +900,7 @@ uint32 mdf = tq_pkt[pkt].d[CMD_MOD];    
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = tq_getucb (lu)) {                            /* unit exist? */
+if ((uptr = tq_getucb (lu))) {                          /* unit exist? */
     if (uptr->flags & UNIT_SXC)                         /* ser exc pending? */
         sts = ST_SXC;
     else {
@@ -955,7 +955,7 @@ if (tq_pkt[pkt].d[CMD_MOD] & MD_NXU) {  
         tq_pkt[pkt].d[RSP_UN] = lu;
         }
     }
-if (uptr = tq_getucb (lu)) {                            /* unit exist? */
+if ((uptr = tq_getucb (lu))) {                          /* unit exist? */
     if ((uptr->flags & UNIT_ATT) == 0)                  /* not attached? */
             sts = ST_OFL | SB_OFL_NV;                   /* offl no vol */
     else if (uptr->flags & UNIT_ONL)                    /* online */
@@ -980,7 +980,7 @@ uint32 lu = tq_pkt[pkt].d[CMD_UN];      
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = tq_getucb (lu)) {                            /* unit exist? */
+if ((uptr = tq_getucb (lu))) {                          /* unit exist? */
     if ((uptr->flags & UNIT_ATT) == 0)                  /* not attached? */
         sts = ST_OFL | SB_OFL_NV;                       /* offl no vol */
     else if (uptr->flags & UNIT_ONL)                    /* already online? */
@@ -1009,7 +1009,7 @@ if (tq_pkt[pkt].d[SCC_MSV])             
 else {
     tq_cflgs = (tq_cflgs & CF_RPL) |                    /* hack ctrl flgs */
         tq_pkt[pkt].d[SCC_CFL];
-    if (tq_htmo = tq_pkt[pkt].d[SCC_TMO])               /* set timeout */
+    if ((tq_htmo = tq_pkt[pkt].d[SCC_TMO]))             /* set timeout */
         tq_htmo = tq_htmo + 2;                          /* if nz, round up */
     tq_pkt[pkt].d[SCC_CFL] = tq_cflgs;                  /* return flags */
     tq_pkt[pkt].d[SCC_TMO] = TQ_DCTMO;                  /* ctrl timeout */
@@ -1033,7 +1033,7 @@ uint32 lu = tq_pkt[pkt].d[CMD_UN];      
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = tq_getucb (lu)) {                            /* unit exist? */
+if ((uptr = tq_getucb (lu))) {                          /* unit exist? */
     if ((uptr->flags & UNIT_ATT) == 0)                  /* not attached? */
         sts = ST_OFL | SB_OFL_NV;                       /* offl no vol */
     else {
@@ -1055,7 +1055,7 @@ uint32 lu = tq_pkt[pkt].d[CMD_UN];      
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = tq_getucb (lu))                              /* unit exist? */
+if ((uptr = tq_getucb (lu)))                            /* unit exist? */
     sts = tq_mot_valid (uptr, OP_FLU);                  /* validate req */
 else sts = ST_OFL;                                      /* offline */
 tq_putr (pkt, OP_FLU | OP_END, tq_efl (uptr), sts, FLU_LNT, UQ_TYP_SEQ);
@@ -1071,7 +1071,7 @@ uint32 cmd = GETP (pkt, CMD_OPC, OPC);  
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = tq_getucb (lu)) {                            /* unit exist? */
+if ((uptr = tq_getucb (lu))) {                          /* unit exist? */
     sts = tq_mot_valid (uptr, cmd);                     /* validity checks */
     if (sts == ST_SUC) {                                /* ok? */
         uptr->cpkt = pkt;                               /* op in progress */
@@ -1092,7 +1092,7 @@ uint32 lu = tq_pkt[pkt].d[CMD_UN];      
 uint32 sts, objp = 0;
 UNIT *uptr;
 
-if (uptr = tq_getucb (lu)) {                            /* unit exist? */
+if ((uptr = tq_getucb (lu))) {                          /* unit exist? */
     objp = uptr->objp;                                  /* position op */
     sts = tq_mot_valid (uptr, OP_WTM);                  /* validity checks */
     if (sts == ST_SUC) {                                /* ok? */
@@ -1115,7 +1115,7 @@ uint32 lu = tq_pkt[pkt].d[CMD_UN];      
 uint32 sts, objp = 0;
 UNIT *uptr;
 
-if (uptr = tq_getucb (lu)) {                            /* unit exist? */
+if ((uptr = tq_getucb (lu))) {                          /* unit exist? */
     objp = uptr->objp;                                  /* position op */
     sts = tq_mot_valid (uptr, OP_POS);                  /* validity checks */
     if (sts == ST_SUC) {                                /* ok? */
@@ -1147,7 +1147,7 @@ uint32 bc = GETP32 (pkt, RW_BCL);       
 uint32 sts, objp = 0;
 UNIT *uptr;
 
-if (uptr = tq_getucb (lu)) {                            /* unit exist? */
+if ((uptr = tq_getucb (lu))) {                          /* unit exist? */
     objp = uptr->objp;                                  /* position op */
     sts = tq_mot_valid (uptr, cmd);                     /* validity checks */
     if (sts == ST_SUC) {                                /* ok? */
@@ -1251,7 +1251,7 @@ switch (cmd) {                          
             }
         else wbc = tbc;
         if (cmd == OP_RD) {                             /* read? */
-            if (t = Map_WriteB (ba, wbc, tqxb)) {       /* store, nxm? */
+            if ((t = Map_WriteB (ba, wbc, tqxb))) {     /* store, nxm? */
                 PUTP32 (pkt, RW_BCL, wbc - t);          /* adj bc */
                 if (tq_hbe (uptr, ba + wbc - t))        /* post err log */
                     tq_mot_end (uptr, EF_LOG, ST_HST | SB_HST_NXM, tbc);        
@@ -1288,7 +1288,7 @@ switch (cmd) {                          
         break;
 
     case OP_WR:                                         /* write */
-        if (t = Map_ReadB (ba, bc, tqxb)) {             /* fetch buf, nxm? */
+        if ((t = Map_ReadB (ba, bc, tqxb))) {           /* fetch buf, nxm? */
             PUTP32 (pkt, RW_BCL, 0);                    /* no bytes xfer'd */
             if (tq_hbe (uptr, ba + bc - t))             /* post err log */
                 tq_mot_end (uptr, EF_LOG, ST_HST | SB_HST_NXM, bc);     
@@ -2233,11 +2233,11 @@ if ((uptr->flags & UNIT_ONL) == 0) {
 if (uptr->cpkt) {
     fprintf (st, "Unit %d current ", u);
     tq_show_pkt (st, uptr->cpkt);
-    if (pkt = uptr->pktq) {
+    if ((pkt = uptr->pktq)) {
         do {
             fprintf (st, "Unit %d queued ", u);
             tq_show_pkt (st, pkt);
-            } while (pkt = tq_pkt[pkt].link);
+            } while ((pkt = tq_pkt[pkt].link));
         }
     }
 else fprintf (st, "Unit %d queues are empty\n", u);
@@ -2262,7 +2262,7 @@ if (val & TQ_SH_RI) {
     tq_show_ring (st, &tq_rq);
     }
 if (val & TQ_SH_FR) {
-    if (pkt = tq_freq) {
+    if ((pkt = tq_freq)) {
         for (i = 0; pkt != 0; i++, pkt = tq_pkt[pkt].link) {
             if (i == 0)
                 fprintf (st, "Free queue = %d", pkt);
@@ -2275,11 +2275,11 @@ if (val & TQ_SH_FR) {
     else fprintf (st, "Free queue is empty\n");
     }
 if (val & TQ_SH_RS) {
-    if (pkt = tq_rspq) {
+    if ((pkt = tq_rspq)) {
         do {
             fprintf (st, "Response ");
             tq_show_pkt (st, pkt);
-            } while (pkt = tq_pkt[pkt].link);
+            } while ((pkt = tq_pkt[pkt].link));
         }
     else fprintf (st, "Response queue is empty\n");
     }
