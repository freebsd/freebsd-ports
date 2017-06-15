--- H316/h316_mt.c.orig	2016-12-01 22:43:42 UTC
+++ H316/h316_mt.c
@@ -371,17 +371,17 @@ switch (uptr->FNC) {                    
         return SCPE_OK;
 
     case FNC_WEOF:                                      /* write file mark */
-        if (st = sim_tape_wrtmk (uptr))                 /* write tmk, err? */
+        if ((st = sim_tape_wrtmk (uptr)))               /* write tmk, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         break;                                          /* sched end motion */
 
     case FNC_FSR:                                       /* space fwd rec */
-        if (st = sim_tape_sprecf (uptr, &tbc))          /* space fwd, err? */
+        if ((st = sim_tape_sprecf (uptr, &tbc)))        /* space fwd, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         break;                                          /* sched end motion */
 
     case FNC_BSR:                                       /* space rev rec */
-        if (st = sim_tape_sprecr (uptr, &tbc))          /* space rev, err? */
+        if ((st = sim_tape_sprecr (uptr, &tbc)))        /* space rev, err? */
             r = mt_map_err (uptr, st);                  /* map error */
         break;                                          /* sched end motion */
 
@@ -455,7 +455,7 @@ switch (uptr->FNC) {                    
                 mt_wrwd (uptr, mt_buf);
             else mt_rdy = 0;                            /* rdy must be clr */
             if (mt_ptr) {                               /* any data? */
-                if (st = sim_tape_wrrecf (uptr, mtxb, mt_ptr))  /* write, err? */
+                if ((st = sim_tape_wrrecf (uptr, mtxb, mt_ptr)))  /* write, err? */
                     r = mt_map_err (uptr, st);          /* map error */
                 }
             break;                                      /* sched end motion */
