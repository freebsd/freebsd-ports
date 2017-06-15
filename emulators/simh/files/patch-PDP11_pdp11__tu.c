--- PDP11/pdp11_tu.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_tu.c
@@ -647,7 +647,7 @@ switch (fnc) {                          
     case FNC_SPACEF:                                    /* space forward */
         do {
             tufc = (tufc + 1) & 0177777;                /* incr fc */
-            if (st = sim_tape_sprecf (uptr, &tbc)) {    /* space rec fwd, err? */
+            if ((st = sim_tape_sprecf (uptr, &tbc))) {  /* space rec fwd, err? */
                 r = tu_map_err (drv, st, 0);            /* map error */
                 break;
                 }
@@ -660,7 +660,7 @@ switch (fnc) {                          
     case FNC_SPACER:                                    /* space reverse */
         do {
             tufc = (tufc + 1) & 0177777;                /* incr wc */
-            if (st = sim_tape_sprecr (uptr, &tbc)) {    /* space rec rev, err? */
+            if ((st = sim_tape_sprecr (uptr, &tbc))) {  /* space rec rev, err? */
                 r = tu_map_err (drv, st, 0);            /* map error */
                 break;
                 }
@@ -671,7 +671,7 @@ switch (fnc) {                          
         break;
 
     case FNC_WREOF:                                     /* write end of file */
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = tu_map_err (drv, st, 0);                /* map error */
         break;
 
@@ -687,7 +687,7 @@ switch (fnc) {                          
         tufc = 0;                                       /* clear frame count */
         if ((uptr->UDENS == TC_1600) && sim_tape_bot (uptr))
             tufs = tufs | FS_ID;                        /* PE BOT? ID burst */
-        if (st = sim_tape_rdrecf (uptr, xbuf, &tbc, MT_MAXFR)) { /* read fwd */
+        if ((st = sim_tape_rdrecf (uptr, xbuf, &tbc, MT_MAXFR))) { /* read fwd */
             if (st == MTSE_TMK)                         /* tmk also sets FCE */
                 tu_set_er (ER_FCE);
             r = tu_map_err (drv, st, 1);                /* map error */
@@ -739,7 +739,7 @@ switch (fnc) {                          
 				}
             tbc = xbc;
             }
-        if (st = sim_tape_wrrecf (uptr, xbuf, tbc))     /* write rec, err? */
+        if ((st = sim_tape_wrrecf (uptr, xbuf, tbc)))   /* write rec, err? */
             r = tu_map_err (drv, st, 1);                /* map error */
         else {
             tufc = (tufc + tbc) & 0177777;
@@ -751,7 +751,7 @@ switch (fnc) {                          
     case FNC_READR:                                     /* read reverse */
     case FNC_WCHKR:                                     /* wcheck = read */
         tufc = 0;                                       /* clear frame count */
-        if (st = sim_tape_rdrecr (uptr, xbuf + 4, &tbc, MT_MAXFR)) { /* read rev */
+        if ((st = sim_tape_rdrecr (uptr, xbuf + 4, &tbc, MT_MAXFR))) { /* read rev */
             if (st == MTSE_TMK)                         /* tmk also sets FCE */
                 tu_set_er (ER_FCE);
             r = tu_map_err (drv, st, 1);                /* map error */
