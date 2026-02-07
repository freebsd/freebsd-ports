--- HP2100/hp2100_mt.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_mt.c
@@ -495,7 +495,7 @@ switch (mtc_fnc) {                      
         return sim_tape_detach (uptr);                  /* don't set cch flg */
 
     case FNC_WFM:                                       /* write file mark */
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         mtc_sta = STA_EOF;                              /* set EOF status */
         break;
@@ -504,12 +504,12 @@ switch (mtc_fnc) {                      
         break;
 
     case FNC_FSR:                                       /* space forward */
-        if (st = sim_tape_sprecf (uptr, &tbc))          /* space rec fwd, err? */
+        if ((st = sim_tape_sprecf (uptr, &tbc)))        /* space rec fwd, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         break;
 
     case FNC_BSR:                                       /* space reverse */
-        if (st = sim_tape_sprecr (uptr, &tbc))          /* space rec rev, err? */
+        if ((st = sim_tape_sprecr (uptr, &tbc)))        /* space rec rev, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         break;
 
@@ -558,7 +558,7 @@ switch (mtc_fnc) {                      
             return SCPE_OK;
             }
         if (mt_ptr) {                                   /* write buffer */
-            if (st = sim_tape_wrrecf (uptr, mtxb, mt_ptr)) {    /* write, err? */
+            if ((st = sim_tape_wrrecf (uptr, mtxb, mt_ptr))) {  /* write, err? */
                 r = mt_map_err (uptr, st);              /* map error */
                 break;                                  /* done */
                 }
@@ -627,7 +627,7 @@ t_stat st;
 
 if (sim_is_active (&mtc_unit) &&                        /* write in prog? */
     (mtc_fnc == FNC_WC) && (mt_ptr > 0)) {              /* yes, bad rec */
-    if (st = sim_tape_wrrecf (&mtc_unit, mtxb, mt_ptr | MTR_ERF))
+    if ((st = sim_tape_wrrecf (&mtc_unit, mtxb, mt_ptr | MTR_ERF)))
         mt_map_err (&mtc_unit, st);
     }
 
