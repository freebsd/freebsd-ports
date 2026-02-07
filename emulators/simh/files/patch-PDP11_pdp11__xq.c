--- PDP11/pdp11_xq.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_xq.c
@@ -1187,7 +1187,7 @@ t_stat xq_process_setup(CTLR* xq)
 
     xq->var->setup.multicast = (0 != (len & XQ_SETUP_MC));
     xq->var->setup.promiscuous = (0 != (len & XQ_SETUP_PM));
-    if (led = (len & XQ_SETUP_LD) >> 2) {
+    if ((led = (len & XQ_SETUP_LD) >> 2)) {
       switch (led) {
         case 1: xq->var->setup.l1 = 0; break;
         case 2: xq->var->setup.l2 = 0; break;
@@ -2073,6 +2073,10 @@ t_stat xq_process_bootrom (CTLR* xq)
       /* set to next bdl (implicit chain) */
       xq->var->rbdl_ba += 12;
       break;
+
+    case XQ_T_DELQA:
+    case XQ_T_DELQA_PLUS:
+      break;
   } /* switch */
 
   /* --------------------------- Done, finish up -----------------------------*/
@@ -2531,7 +2535,7 @@ t_stat xq_tmrsvc(UNIT* uptr)
 
   /* has sanity timer expired? if so, reboot */
   if (xq->var->sanity.enabled)
-    if (--xq->var->sanity.timer <= 0)
+    if (--xq->var->sanity.timer <= 0) {
       if (xq->var->mode != XQ_T_DELQA_PLUS)
         return xq_boot_host(xq);
       else { /* DELQA-T Host Inactivity Timer expiration means switch out of DELQA-T mode */
@@ -2540,6 +2544,7 @@ t_stat xq_tmrsvc(UNIT* uptr)
         xq->var->iba = xq->var->srr = 0;
         xq->var->var = XQ_VEC_MS | XQ_VEC_OS;
       }
+  }
 
   /* has system id timer expired? if so, do system id */
   if (--xq->var->idtmr <= 0) {
