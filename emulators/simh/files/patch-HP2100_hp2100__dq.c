--- HP2100/hp2100_dq.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_dq.c
@@ -530,7 +530,7 @@ void dq_goc (int32 fnc, int32 drv, int32
 {
 int32 t;
 
-if (t = sim_is_active (&dqc_unit[drv])) {               /* still seeking? */
+if ((t = sim_is_active (&dqc_unit[drv]))) {             /* still seeking? */
     sim_cancel (&dqc_unit[drv]);                        /* cancel */
     time = time + t;                                    /* include seek time */
     }
@@ -740,10 +740,10 @@ switch (uptr->FNC) {                    
             dqc_rars = (dqc_rars + 1) % DQ_NUMSC;       /* incr sector */
             if (dqc_rars == 0)                          /* wrap? incr head */
                 dqc_uhed[drv] = dqc_rarh = dqc_rarh + 1;
-            if (err = fseek (uptr->fileref, da * sizeof (int16),
-                SEEK_SET)) break;
+            if ((err = fseek (uptr->fileref, da * sizeof (int16),
+                SEEK_SET))) break;
             fxread (dqxb, sizeof (int16), DQ_NUMWD, uptr->fileref);
-            if (err = ferror (uptr->fileref)) break;
+            if ((err = ferror (uptr->fileref))) break;
             }
         dqd_ibuf = dqxb[dq_ptr++];                      /* get word */
         if (dq_ptr >= DQ_NUMWD) {                       /* end of sector? */
@@ -786,10 +786,10 @@ switch (uptr->FNC) {                    
             dqc_rars = (dqc_rars + 1) % DQ_NUMSC;       /* incr sector */
             if (dqc_rars == 0)                          /* wrap? incr head */
                 dqc_uhed[drv] = dqc_rarh = dqc_rarh + 1;
-            if (err = fseek (uptr->fileref, da * sizeof (int16),
-                SEEK_SET)) return TRUE;
+            if ((err = fseek (uptr->fileref, da * sizeof (int16),
+                SEEK_SET))) return TRUE;
             fxwrite (dqxb, sizeof (int16), DQ_NUMWD, uptr->fileref);
-            if (err = ferror (uptr->fileref)) break;
+            if ((err = ferror (uptr->fileref))) break;
             dq_ptr = 0;
             }
         if (dqd.command && dqd_xfer) {                  /* dch on, xfer? */
