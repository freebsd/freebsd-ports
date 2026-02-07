--- NOVA/nova_mta.c.orig	2016-12-01 22:43:42 UTC
+++ NOVA/nova_mta.c
@@ -412,7 +412,7 @@ else switch (c) {                       
             mtxb[p++] = M[pa] & 0377;
             mta_ma = (mta_ma + 1) & AMASK;
             }
-        if (st = sim_tape_wrrecf (uptr, mtxb, tbc)) {   /* write rec, err? */
+        if ((st = sim_tape_wrrecf (uptr, mtxb, tbc))) { /* write rec, err? */
             r = mta_map_err (uptr, st);                 /* map error */
             mta_ma = (mta_ma - wc) & AMASK;             /* restore wc */
             }
@@ -421,7 +421,7 @@ else switch (c) {                       
         break;
 
     case CU_WREOF:                                      /* write eof */
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = mta_map_err (uptr, st);                 /* map error */
         else mta_upddsta (uptr, uptr->USTAT | STA_EOF | STA_RDY);
         break;
@@ -435,7 +435,7 @@ else switch (c) {                       
     case CU_SPACEF:                                     /* space forward */
         do {
             mta_wc = (mta_wc + 1) & DMASK;              /* incr wc */
-            if (st = sim_tape_sprecf (uptr, &tbc)) {    /* space rec fwd, err? */
+            if ((st = sim_tape_sprecf (uptr, &tbc))) {  /* space rec fwd, err? */
                 r = mta_map_err (uptr, st);             /* map error */
                 break;
                 }
@@ -447,7 +447,7 @@ else switch (c) {                       
     case CU_SPACER:                                     /* space reverse */
         do {
             mta_wc = (mta_wc + 1) & DMASK;              /* incr wc */
-            if (st = sim_tape_sprecr (uptr, &tbc)) {    /* space rec rev, err? */
+            if ((st = sim_tape_sprecr (uptr, &tbc))) {  /* space rec rev, err? */
                 r = mta_map_err (uptr, st);             /* map error */
                 break;
                 }
