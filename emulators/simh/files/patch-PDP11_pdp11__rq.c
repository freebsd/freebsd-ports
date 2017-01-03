--- PDP11/pdp11_rq.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_rq.c
@@ -1352,7 +1352,7 @@ UNIT *uptr;
 DEVICE *dptr = rq_devmap[cp->cnum];
 
 tpkt = 0;                                               /* set no mtch */
-if (uptr = rq_getucb (cp, lu)) {                        /* get unit */
+if ((uptr = rq_getucb (cp, lu))) {                        /* get unit */
     if (uptr->cpkt &&                                   /* curr pkt? */
         (GETP32 (uptr->cpkt, CMD_REFL) == ref)) {       /* match ref? */
         tpkt = uptr->cpkt;                              /* save match */
@@ -1365,8 +1365,8 @@ if (uptr = rq_getucb (cp, lu)) {        
         tpkt = uptr->pktq;                              /* save match */
         uptr->pktq = cp->pak[tpkt].link;                /* unlink */
         }
-    else if (prv = uptr->pktq) {                        /* srch pkt q */
-        while (tpkt = cp->pak[prv].link) {              /* walk list */
+    else if ((prv = uptr->pktq)) {                      /* srch pkt q */
+        while ((tpkt = cp->pak[prv].link)) {            /* walk list */
             if (GETP32 (tpkt, RSP_REFL) == ref) {       /* match? unlink */
                 cp->pak[prv].link = cp->pak[tpkt].link;
                 break;
@@ -1393,7 +1393,7 @@ uint32 cmd = GETP (pkt, CMD_OPC, OPC);  
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = rq_getucb (cp, lu)) {                        /* unit exist? */
+if ((uptr = rq_getucb (cp, lu))) {                      /* unit exist? */
     if (q && uptr->cpkt) {                              /* need to queue? */
         rq_enqt (cp, &uptr->pktq, pkt);                 /* do later */
         return OK;
@@ -1447,7 +1447,7 @@ if (cp->pak[pkt].d[CMD_MOD] & MD_NXU) { 
         cp->pak[pkt].d[RSP_UN] = lu;
         }
     }
-if (uptr = rq_getucb (cp, lu)) {                        /* unit exist? */
+if ((uptr = rq_getucb (cp, lu))) {                      /* unit exist? */
     if ((uptr->flags & UNIT_ATT) == 0)                  /* not attached? */
         sts = ST_OFL | SB_OFL_NV;                       /* offl no vol */
     else if (uptr->flags & UNIT_ONL)                    /* online */
@@ -1482,7 +1482,7 @@ uint32 cmd = GETP (pkt, CMD_OPC, OPC);  
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = rq_getucb (cp, lu)) {                        /* unit exist? */
+if ((uptr = rq_getucb (cp, lu))) {                      /* unit exist? */
     if (q && uptr->cpkt) {                              /* need to queue? */
         rq_enqt (cp, &uptr->pktq, pkt);                 /* do later */
         return OK;
@@ -1520,7 +1520,7 @@ else {
     cmd = GETP (pkt, CMD_OPC, OPC);                     /* get opcode */
     cp->cflgs = (cp->cflgs & CF_RPL) |                  /* hack ctrl flgs */
         cp->pak[pkt].d[SCC_CFL];
-    if (cp->htmo = cp->pak[pkt].d[SCC_TMO])             /* set timeout */
+    if ((cp->htmo = cp->pak[pkt].d[SCC_TMO]))           /* set timeout */
         cp->htmo = cp->htmo + 2;                        /* if nz, round up */
     cp->pak[pkt].d[SCC_CFL] = cp->cflgs;                /* return flags */
     cp->pak[pkt].d[SCC_TMO] = RQ_DCTMO;                 /* ctrl timeout */
@@ -1547,7 +1547,7 @@ uint32 cmd = GETP (pkt, CMD_OPC, OPC);  
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = rq_getucb (cp, lu)) {                        /* unit exist? */
+if ((uptr = rq_getucb (cp, lu))) {                      /* unit exist? */
     if (q && uptr->cpkt) {                              /* need to queue? */
         rq_enqt (cp, &uptr->pktq, pkt);                 /* do later */
         return OK;
@@ -1576,7 +1576,7 @@ uint32 cmd = GETP (pkt, CMD_OPC, OPC);  
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = rq_getucb (cp, lu)) {                        /* unit exist? */
+if ((uptr = rq_getucb (cp, lu))) {                      /* unit exist? */
     if (q && uptr->cpkt) {                              /* need to queue? */
         rq_enqt (cp, &uptr->pktq, pkt);                 /* do later */
         return OK;
@@ -1610,7 +1610,7 @@ uint32 cmd = GETP (pkt, CMD_OPC, OPC);  
 uint32 sts;
 UNIT *uptr;
 
-if (uptr = rq_getucb (cp, lu)) {                        /* unit exist? */
+if ((uptr = rq_getucb (cp, lu))) {                      /* unit exist? */
     if (q && uptr->cpkt) {                              /* need to queue? */
         rq_enqt (cp, &uptr->pktq, pkt);                 /* do later */
         return OK;
@@ -1725,7 +1725,7 @@ if (cmd == OP_ERS) {                    
 
 else if (cmd == OP_WR) {                                /* write? */
     t = Map_ReadW (ba, tbc, rqxb);                      /* fetch buffer */
-    if (abc = tbc - t) {                                /* any xfer? */
+    if ((abc = tbc - t)) {                              /* any xfer? */
         wwc = ((abc + (RQ_NUMBY - 1)) & ~(RQ_NUMBY - 1)) >> 1;
         for (i = (abc >> 1); i < wwc; i++)
             rqxb[i] = 0;
@@ -1752,7 +1752,7 @@ else {
         err = ferror (uptr->fileref);
         }
     if ((cmd == OP_RD) && !err) {                       /* read? */
-        if (t = Map_WriteW (ba, tbc, rqxb)) {           /* store, nxm? */
+        if ((t = Map_WriteW (ba, tbc, rqxb))) {         /* store, nxm? */
             PUTP32 (pkt, RW_WBCL, bc - (tbc - t));      /* adj bc */
             PUTP32 (pkt, RW_WBAL, ba + (tbc - t));      /* adj ba */
             if (rq_hbe (cp, uptr))                      /* post err log */
@@ -2586,11 +2586,11 @@ if ((uptr->flags & UNIT_ONL) == 0) {
 if (uptr->cpkt) {
     fprintf (st, "Unit %d current ", u);
     rq_show_pkt (st, cp, uptr->cpkt);
-    if (pkt = uptr->pktq) {
+    if ((pkt = uptr->pktq)) {
         do {
             fprintf (st, "Unit %d queued ", u);
             rq_show_pkt (st, cp, pkt);
-            } while (pkt = cp->pak[pkt].link);
+            } while ((pkt = cp->pak[pkt].link));
         }
     }
 else fprintf (st, "Unit %d queues are empty\n", u);
@@ -2617,7 +2617,7 @@ if (val & RQ_SH_RI) {
     rq_show_ring (st, &cp->rq);
     }
 if (val & RQ_SH_FR) {
-    if (pkt = cp->freq) {
+    if ((pkt = cp->freq)) {
         for (i = 0; pkt != 0; i++, pkt = cp->pak[pkt].link) {
             if (i == 0)
                 fprintf (st, "Free queue = %d", pkt);
@@ -2630,11 +2630,11 @@ if (val & RQ_SH_FR) {
     else fprintf (st, "Free queue is empty\n");
     }
 if (val & RQ_SH_RS) {
-    if (pkt = cp->rspq) {
+    if ((pkt = cp->rspq)) {
         do {
             fprintf (st, "Response ");
             rq_show_pkt (st, cp, pkt);
-            } while (pkt = cp->pak[pkt].link);
+            } while ((pkt = cp->pak[pkt].link));
         }
     else fprintf (st, "Response queue is empty\n");
     }
