--- PDP8/pdp8_ct.c.orig	2016-12-01 22:43:43 UTC
+++ PDP8/pdp8_ct.c
@@ -270,7 +270,7 @@ switch (IR & 07) {                      
 
     case 6:                                             /* KGOA */
         ct_df = 0;                                      /* clear data flag */
-        if (uptr = ct_busy ())                          /* op in progress? */
+        if ((uptr = ct_busy ()))                        /* op in progress? */
             AC = ct_go_cont (uptr, AC);                 /* yes */
         else AC = ct_go_start (AC);                     /* no, start */
         ct_updsta (NULL);
@@ -433,7 +433,7 @@ switch (uptr->FNC) {                    
 
     case SRA_CRC:                                       /* CRC */
         if (ct_write) {                                 /* write? */
-           if (st = sim_tape_wrrecf (uptr, ct_xb, ct_bptr)) /* write, err? */
+           if ((st = sim_tape_wrrecf (uptr, ct_xb, ct_bptr))) /* write, err? */
                r = ct_map_err (uptr, st);               /* map error */
            break;                                       /* write done */
            }
@@ -452,7 +452,7 @@ switch (uptr->FNC) {                    
          break;                                         /* read done */
 
     case SRA_WFG:                                       /* write file gap */
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = ct_map_err (uptr, st);                  /* map error */
         break;
 
@@ -462,7 +462,7 @@ switch (uptr->FNC) {                    
         break;
 
     case SRA_SRB:                                       /* space rev blk */
-        if (st = sim_tape_sprecr (uptr, &tbc))          /* space rev, err? */
+        if ((st = sim_tape_sprecr (uptr, &tbc)))        /* space rev, err? */
             r = ct_map_err (uptr, st);                  /* map error */
          break;
 
