--- PDP11/pdp11_ta.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_ta.c
@@ -397,13 +397,13 @@ switch (uptr->FNC) {                    
 
     case TACS_WRITE|TACS_3RD:                           /* write CRC */
         if (ta_bptr) {                                  /* anything to write? */
-           if (st = sim_tape_wrrecf (uptr, ta_xb, ta_bptr)) /* write, err? */
+           if ((st = sim_tape_wrrecf (uptr, ta_xb, ta_bptr))) /* write, err? */
                r = ta_map_err (uptr, st);               /* map error */
            }
         break;                                          /* op done */
 
     case TACS_WFG:                                      /* write file gap */
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = ta_map_err (uptr, st);                  /* map error */
         break;
 
@@ -413,7 +413,7 @@ switch (uptr->FNC) {                    
         break;
 
     case TACS_SRB:                                      /* space rev blk */
-        if (st = sim_tape_sprecr (uptr, &tbc))          /* space rev, err? */
+        if ((st = sim_tape_sprecr (uptr, &tbc)))        /* space rev, err? */
             r = ta_map_err (uptr, st);                  /* map error */
          break;
 
@@ -425,7 +425,7 @@ switch (uptr->FNC) {                    
         break;
 
     case TACS_SFB:                                      /* space fwd blk */
-        if (st = sim_tape_sprecf (uptr, &tbc))          /* space rev, err? */
+        if ((st = sim_tape_sprecf (uptr, &tbc)))        /* space rev, err? */
             r = ta_map_err (uptr, st);                  /* map error */
         ta_cs |= TACS_CRC;                              /* CRC sets, no err */
         break;
