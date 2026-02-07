--- PDP11/pdp11_ts.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_ts.c
@@ -490,7 +490,7 @@ do {
     fc = (fc - 1) & DMASK;                              /* decr wc */
     if (upd)
         msgrfc = fc;
-    if (st = sim_tape_sprecf (uptr, &tbc))              /* space rec fwd, err? */
+    if ((st = sim_tape_sprecf (uptr, &tbc)))            /* space rec fwd, err? */
         return ts_map_status (st);                      /* map status */
     msgxs0 = msgxs0 | XS0_MOT;                          /* tape has moved */
     } while (fc != 0);
@@ -533,7 +533,7 @@ do {
     fc = (fc - 1) & DMASK;                              /* decr wc */
     if (upd)
         msgrfc = fc;
-    if (st = sim_tape_sprecr (uptr, &tbc))              /* space rec rev, err? */
+    if ((st = sim_tape_sprecr (uptr, &tbc)))            /* space rec rev, err? */
         return ts_map_status (st);                      /* map status */
     msgxs0 = msgxs0 | XS0_MOT;                          /* tape has moved */
     } while (fc != 0);
@@ -666,7 +666,7 @@ else {
         return TC5;
         }
     }
-if (st = sim_tape_wrrecf (uptr, tsxb, fc))              /* write rec, err? */
+if ((st = sim_tape_wrrecf (uptr, tsxb, fc)))            /* write rec, err? */
     return ts_map_status (st);                          /* return status */
 msgxs0 = msgxs0 | XS0_MOT;                              /* tape has moved */
 msgrfc = 0;
@@ -679,7 +679,7 @@ int32 ts_wtmk (UNIT *uptr)
 {
 t_stat st;
 
-if (st = sim_tape_wrtmk (uptr))                         /* write tmk, err? */
+if ((st = sim_tape_wrtmk (uptr)))                       /* write tmk, err? */
     return ts_map_status (st);                          /* return status */
 msgxs0 = msgxs0 | XS0_MOT;                              /* tape has moved */
 if (sim_tape_eot (&ts_unit))                            /* EOT on write? */
