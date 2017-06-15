--- PDP8/pdp8_mt.c.orig	2016-12-01 22:43:43 UTC
+++ PDP8/pdp8_mt.c
@@ -453,7 +453,7 @@ switch (f) {                            
                 mtxb[p++] = M[xma] & 077;
                 }
             }
-        if (st = sim_tape_wrrecf (uptr, mtxb, tbc)) {   /* write rec, err? */
+        if ((st = sim_tape_wrrecf (uptr, mtxb, tbc))) { /* write rec, err? */
             r = mt_map_err (uptr, st);                  /* map error */
             xma = GET_EMA (mt_cu) + mt_ca;              /* restore xma */
             }
@@ -461,14 +461,14 @@ switch (f) {                            
         break;
 
     case FN_WREOF:
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         break;
 
     case FN_SPACEF:                                     /* space forward */
         do {
             mt_wc = (mt_wc + 1) & 07777;                /* incr wc */
-            if (st = sim_tape_sprecf (uptr, &tbc)) {    /* space rec fwd, err? */
+            if ((st = sim_tape_sprecf (uptr, &tbc))) {  /* space rec fwd, err? */
                 r = mt_map_err (uptr, st);              /* map error */
                 break;                                  /* stop */
                 }
@@ -478,7 +478,7 @@ switch (f) {                            
     case FN_SPACER:                                     /* space reverse */
         do {
             mt_wc = (mt_wc + 1) & 07777;                /* incr wc */
-            if (st = sim_tape_sprecr (uptr, &tbc)) {    /* space rec rev, err? */
+            if ((st = sim_tape_sprecr (uptr, &tbc))) {  /* space rec rev, err? */
                 r = mt_map_err (uptr, st);              /* map error */
                 break;                                  /* stop */
                 }
