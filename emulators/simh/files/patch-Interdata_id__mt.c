--- Interdata/id_mt.c.orig	2016-12-01 22:43:42 UTC
+++ Interdata/id_mt.c
@@ -368,13 +368,13 @@ switch (uptr->UCMD) {                   
             }
 
         if (mt_bptr) {                                  /* any chars? */
-            if (st = sim_tape_wrrecf (uptr, mtxb, mt_bptr)) /* write, err? */
+            if ((st = sim_tape_wrrecf (uptr, mtxb, mt_bptr))) /* write, err? */
                 r = mt_map_err (uptr, st);              /* map error */
             }
         break;                                          /* record done */
 
     case MTC_WEOF:                                      /* write eof */
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         mt_sta = mt_sta | STA_EOF;                      /* set eof */
         if (mt_arm[u])                                  /* set intr */
@@ -402,7 +402,7 @@ switch (uptr->UCMD) {                   
         break;
 
     case MTC_SPCR:                                      /* backspace */
-        if (st = sim_tape_sprecr (uptr, &tbc))          /* skip rec rev, err? */
+        if ((st = sim_tape_sprecr (uptr, &tbc)))        /* skip rec rev, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         break;
         }                                               /* end case */
