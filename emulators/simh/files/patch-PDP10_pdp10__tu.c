--- PDP10/pdp10_tu.c.orig	2016-12-01 22:43:42 UTC
+++ PDP10/pdp10_tu.c
@@ -833,7 +833,7 @@ switch (fnc) {                          
     case FNC_SPACEF:                                    /* space forward */
         do {
             tufc = (tufc + 1) & 0177777;                /* incr fc */
-            if (st = sim_tape_sprecf (uptr, &tbc)) {    /* space rec fwd, err? */
+            if ((st = sim_tape_sprecf (uptr, &tbc))) {  /* space rec fwd, err? */
                 r = tu_map_err (uptr, st, 0);           /* map error */
                 break;
                 }
@@ -847,7 +847,7 @@ switch (fnc) {                          
     case FNC_SPACER:                                    /* space reverse */
         do {
             tufc = (tufc + 1) & 0177777;                /* incr wc */
-            if (st = sim_tape_sprecr (uptr, &tbc)) {    /* space rec rev, err? */
+            if ((st = sim_tape_sprecr (uptr, &tbc))) {  /* space rec rev, err? */
                 r = tu_map_err (uptr, st, 0);           /* map error */
                 break;
                 }
@@ -859,7 +859,7 @@ switch (fnc) {                          
         break;
 
     case FNC_WREOF:                                     /* write end of file */
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))                 /* write tmk, err? */
             r = tu_map_err (uptr, st, 0);               /* map error */
         tufs = tufs | FS_ATA;
         break;
@@ -889,7 +889,7 @@ switch (fnc) {                          
         if ((uptr->UDENS == TC_1600) && sim_tape_bot (uptr))
             tufs = tufs | FS_ID;                        /* PE BOT? ID burst */
         TXFR (ba, wc, 0);                               /* validate transfer */
-        if (st = sim_tape_rdrecf (uptr, xbuf, &tbc, MT_MAXFR)) { /* read fwd */
+        if ((st = sim_tape_rdrecf (uptr, xbuf, &tbc, MT_MAXFR))) { /* read fwd */
             if (st == MTSE_TMK)                         /* TMK also sets FCE */
                 set_tuer (ER_FCE);
             r = tu_map_err (uptr, st, 1);               /* map error */
@@ -936,7 +936,7 @@ switch (fnc) {                          
             }                                           /* end for */
         if (j < fc)                                     /* short record? */
             fc = j;
-        if (st = sim_tape_wrrecf (uptr, xbuf, fc))      /* write rec, err? */
+        if ((st = sim_tape_wrrecf (uptr, xbuf, fc)))    /* write rec, err? */
             r = tu_map_err (uptr, st, 1);               /* map error */
         else {
             tufc = (tufc + fc) & 0177777;
@@ -951,7 +951,7 @@ switch (fnc) {                          
     case FNC_WCHKR:                                     /* wcheck = read */
         tufc = 0;                                       /* clear frame count */
         TXFR (ba, wc, 1);                               /* validate xfer rev */
-        if (st = sim_tape_rdrecr (uptr, xbuf + 4, &tbc, MT_MAXFR)) { /* read rev */
+        if ((st = sim_tape_rdrecr (uptr, xbuf + 4, &tbc, MT_MAXFR))) { /* read rev */
             if (st == MTSE_TMK)                         /* TMK also sets FCE */
                 set_tuer (ER_FCE);
             r = tu_map_err (uptr, st, 1);               /* map error */
