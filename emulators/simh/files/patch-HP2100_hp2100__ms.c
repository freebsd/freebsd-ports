--- HP2100/hp2100_ms.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_ms.c
@@ -737,7 +737,7 @@ switch (uptr->FNC) {                    
                 fprintf (sim_deb,
                     ">>MSC svc: Unit %d wrote initial gap\n",
                     unum);
-            if (st = ms_write_gap (uptr)) {             /* write initial gap; error? */
+            if ((st = ms_write_gap (uptr))) {           /* write initial gap; error? */
                 r = ms_map_err (uptr, st);              /* map error */
                 break;                                  /* terminate operation */
                 }
@@ -747,13 +747,13 @@ switch (uptr->FNC) {                    
             fprintf (sim_deb,
                 ">>MSC svc: Unit %d wrote file mark\n",
                 unum);
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = ms_map_err (uptr, st);                  /* map error */
         msc_sta = STA_EOF;                              /* set EOF status */
         break;
 
     case FNC_FSR:                                       /* space forward */
-        if (st = sim_tape_sprecf (uptr, &tbc))          /* space rec fwd, err? */
+        if ((st = sim_tape_sprecf (uptr, &tbc)))        /* space rec fwd, err? */
             r = ms_map_err (uptr, st);                  /* map error */
         if (tbc & 1)
             msc_sta = msc_sta | STA_ODD;
@@ -761,7 +761,7 @@ switch (uptr->FNC) {                    
         break;
 
     case FNC_BSR:                                       /* space reverse */
-        if (st = sim_tape_sprecr (uptr, &tbc))          /* space rec rev, err? */
+        if ((st = sim_tape_sprecr (uptr, &tbc)))        /* space rec rev, err? */
             r = ms_map_err (uptr, st);                  /* map error */
         if (tbc & 1)
             msc_sta = msc_sta | STA_ODD;
@@ -831,7 +831,7 @@ switch (uptr->FNC) {                    
                     fprintf (sim_deb,
                         ">>MSC svc: Unit %d wrote initial gap\n",
                         unum);
-                if (st = ms_write_gap (uptr)) {         /* write initial gap; error? */
+                if ((st = ms_write_gap (uptr))) {       /* write initial gap; error? */
                     r = ms_map_err (uptr, st);          /* map error */
                     break;                              /* terminate operation */
                     }
@@ -855,7 +855,7 @@ switch (uptr->FNC) {                    
                 fprintf (sim_deb,
                     ">>MSC svc: Unit %d wrote %d word record\n",
                     unum, ms_ptr / 2);
-            if (st = sim_tape_wrrecf (uptr, msxb, ms_ptr)) {    /* write, err? */
+            if ((st = sim_tape_wrrecf (uptr, msxb, ms_ptr))) {  /* write, err? */
                 r = ms_map_err (uptr, st);              /* map error */
                 break;
                 }
@@ -894,7 +894,7 @@ t_stat st;
 uint32 gap_len = ms_ctype ? GAP_13183 : GAP_13181;      /* establish gap length */
 uint32 tape_bpi = ms_ctype ? BPI_13183 : BPI_13181;     /* establish nominal bpi */
 
-if (st = sim_tape_wrgap (uptr, gap_len, tape_bpi))      /* write gap */
+if ((st = sim_tape_wrgap (uptr, gap_len, tape_bpi)))    /* write gap */
     return ms_map_err (uptr, st);                       /* map error if failure */
 else
     return SCPE_OK;
@@ -974,7 +974,7 @@ for (i = 0; i < MS_NUMDR; i++) {        
             fprintf (sim_deb,
                 ">>MSC rws: Unit %d wrote %d word partial record\n", i, ms_ptr / 2);
 
-        if (st = sim_tape_wrrecf (uptr, msxb, ms_ptr | MTR_ERF))
+        if ((st = sim_tape_wrrecf (uptr, msxb, ms_ptr | MTR_ERF)))
             ms_map_err (uptr, st);                      /* discard any error */
 
         ms_ptr = 0;                                     /* clear partial */
