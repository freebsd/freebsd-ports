--- PDP10/pdp10_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ PDP10/pdp10_cpu.c
@@ -705,7 +705,7 @@ pager_tc = FALSE;                       
 pflgs = 0;                                              /* not in PXCT */
 xct_cnt = 0;                                            /* count XCT's */
 if (sim_interval <= 0) {                                /* check clock queue */
-    if (i = sim_process_event ())                       /* error?  stop sim */
+    if ((i = sim_process_event ()))                     /* error?  stop sim */
         ABORT (i);
     pi_eval ();                                         /* eval pi system */
     }
@@ -719,7 +719,7 @@ if (sim_interval <= 0) {                
 if (qintr) {
     int32 vec, uba;
     pager_pi = TRUE;                                    /* flag in pi seq */
-    if (vec = pi_ub_vec (qintr, &uba)) {                /* Unibus interrupt? */
+    if ((vec = pi_ub_vec (qintr, &uba))) {              /* Unibus interrupt? */
         mb = ReadP (epta + EPT_UBIT + uba);             /* get dispatch table */
         if (mb == 0)                                    /* invalid? stop */
             ABORT (STOP_ZERINT);
@@ -2019,7 +2019,7 @@ int32 test_int (void)
 int32 t;
 
 if (sim_interval <= 0) {                                /* check queue */
-    if (t = sim_process_event ())                       /* IO event? */
+    if ((t = sim_process_event ()))                     /* IO event? */
         return t;
     if (pi_eval ())                                     /* interrupt? */
         return (INTERRUPT);
