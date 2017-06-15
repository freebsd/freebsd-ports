--- SDS/sds_mt.c.orig	2016-12-01 22:43:43 UTC
+++ SDS/sds_mt.c
@@ -235,14 +235,14 @@ switch (fnc) {                          
     case IO_DISC:                                       /* disconnect */
         sim_cancel (uptr);                              /* no more xfr's */
         if (inst & DEV_OUT) {                           /* write? */
-            if (r = mt_wrend (inst))                    /* end record */
+            if ((r = mt_wrend (inst)))                  /* end record */
                 return r;
             }
         break;
 
     case IO_WREOR:                                      /* write eor */
         chan_set_flag (mt_dib.chan, CHF_EOR);           /* set eor flg */
-        if (r = mt_wrend (inst))                        /* end record */
+        if ((r = mt_wrend (inst)))                      /* end record */
             return r;
         mt_gap = 1;                                     /* in gap */
         sim_activate (uptr, mt_gtime);                  /* start timer */        
