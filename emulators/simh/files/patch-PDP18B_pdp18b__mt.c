--- PDP18B/pdp18b_mt.c.orig	2016-12-01 22:43:42 UTC
+++ PDP18B/pdp18b_mt.c
@@ -353,7 +353,7 @@ switch (f) {                            
                 mtxb[p++] = M[xma] & 0377;
                 }
             }                                           /* end for */
-        if (st = sim_tape_wrrecf (uptr, mtxb, tbc))     /* write rec, err? */
+        if ((st = sim_tape_wrrecf (uptr, mtxb, tbc)))   /* write rec, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         else {
             M[MT_CA] = (M[MT_CA] + wc) & DMASK;         /* advance mem addr */
@@ -363,7 +363,7 @@ switch (f) {                            
         break;
 
     case FN_WREOF:
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         else uptr->USTAT = STA_EOF;
         mt_cu = mt_cu & ~CU_ERASE;                      /* clear erase flag */
@@ -372,7 +372,7 @@ switch (f) {                            
     case FN_SPACEF:                                     /* space forward */
         do {
             M[MT_WC] = (M[MT_WC] + 1) & DMASK;          /* inc WC */
-            if (st = sim_tape_sprecf (uptr, &tbc)) {    /* space rec fwd, err? */
+            if ((st = sim_tape_sprecf (uptr, &tbc))) {  /* space rec fwd, err? */
                 r = mt_map_err (uptr, st);              /* map error */
                 break;
                 }
@@ -382,7 +382,7 @@ switch (f) {                            
     case FN_SPACER:                                     /* space reverse */
         do {
             M[MT_WC] = (M[MT_WC] + 1) & DMASK;          /* inc WC */
-            if (st = sim_tape_sprecr (uptr, &tbc)) {    /* space rec rev, err? */
+            if ((st = sim_tape_sprecr (uptr, &tbc))) {  /* space rec rev, err? */
                 r = mt_map_err (uptr, st);              /* map error */
                 break;
                 }
