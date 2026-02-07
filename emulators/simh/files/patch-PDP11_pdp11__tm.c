--- PDP11/pdp11_tm.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_tm.c
@@ -439,7 +439,7 @@ switch (f) {                            
             tm_sta = tm_sta | STA_RLE;
         if (tbc < cbc)                                  /* use smaller */
             cbc = tbc;
-        if (t = Map_WriteB (xma, cbc, tmxb)) {          /* copy buf to mem */
+        if ((t = Map_WriteB (xma, cbc, tmxb))) {        /* copy buf to mem */
             tm_sta = tm_sta | STA_NXM;                  /* NXM, set err */
             cbc = cbc - t;                              /* adj byte cnt */
             }
@@ -449,13 +449,13 @@ switch (f) {                            
 
     case MTC_WRITE:                                     /* write */
     case MTC_WREXT:                                     /* write ext gap */
-        if (t = Map_ReadB (xma, cbc, tmxb)) {           /* copy mem to buf */
+        if ((t = Map_ReadB (xma, cbc, tmxb))) {         /* copy mem to buf */
             tm_sta = tm_sta | STA_NXM;                  /* NXM, set err */
             cbc = cbc - t;                              /* adj byte cnt */
             if (cbc == 0)                               /* no xfr? done */
                 break;
             }
-        if (st = sim_tape_wrrecf (uptr, tmxb, cbc))     /* write rec, err? */
+        if ((st = sim_tape_wrrecf (uptr, tmxb, cbc)))   /* write rec, err? */
             r = tm_map_err (uptr, st);                  /* map error */
         else {
             xma = (xma + cbc) & 0777777;                /* inc bus addr */
@@ -464,14 +464,14 @@ switch (f) {                            
         break;
 
     case MTC_WREOF:                                     /* write eof */
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = tm_map_err (uptr, st);                  /* map error */
         break;
 
     case MTC_SPACEF:                                    /* space forward */
         do {
             tm_bc = (tm_bc + 1) & 0177777;              /* incr wc */
-            if (st = sim_tape_sprecf (uptr, &tbc)) {    /* spc rec fwd, err? */
+            if ((st = sim_tape_sprecf (uptr, &tbc))) {  /* spc rec fwd, err? */
                 r = tm_map_err (uptr, st);              /* map error */
                 break;
                 }
@@ -481,7 +481,7 @@ switch (f) {                            
     case MTC_SPACER:                                    /* space reverse */
         do {
             tm_bc = (tm_bc + 1) & 0177777;              /* incr wc */
-            if (st = sim_tape_sprecr (uptr, &tbc)) {    /* spc rec rev, err? */
+            if ((st = sim_tape_sprecr (uptr, &tbc))) {  /* spc rec rev, err? */
                 r = tm_map_err (uptr, st);              /* map error */
                 break;
                 }
