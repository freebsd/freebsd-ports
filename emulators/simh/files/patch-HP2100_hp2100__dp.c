--- HP2100/hp2100_dp.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_dp.c
@@ -694,7 +694,7 @@ void dp_goc (int32 fnc, int32 drv, int32
 {
 int32 t;
 
-if (t = sim_is_active (&dpc_unit[drv])) {               /* still seeking? */
+if ((t = sim_is_active (&dpc_unit[drv]))) {             /* still seeking? */
     sim_cancel (&dpc_unit[drv]);                        /* stop seek */
     dpc_sta[drv] = dpc_sta[drv] & ~STA_BSY;             /* clear busy */
     time = time + t;                                    /* include seek time */
@@ -906,10 +906,10 @@ switch (uptr->FNC) {                    
                 dpc_rarh = dpc_rarh ^ 1;                /* incr head */
                 dpc_eoc = ((dpc_rarh & 1) == 0);        /* calc eoc */
                 }
-            if (err = fseek (uptr->fileref, da * sizeof (int16),
-                SEEK_SET)) break;
+            if ((err = fseek (uptr->fileref, da * sizeof (int16),
+                SEEK_SET))) break;
             fxread (dpxb, sizeof (int16), DP_NUMWD, uptr->fileref);
-            if (err = ferror (uptr->fileref)) break;
+            if ((err = ferror (uptr->fileref))) break;
             }
         dpd_ibuf = dpxb[dp_ptr++];                      /* get word */
         if (dp_ptr >= DP_NUMWD) {                       /* end of sector? */
@@ -953,10 +953,10 @@ switch (uptr->FNC) {                    
                 dpc_rarh = dpc_rarh ^ 1;                /* incr head */
                 dpc_eoc = ((dpc_rarh & 1) == 0);        /* calc eoc */
                 }
-            if (err = fseek (uptr->fileref, da * sizeof (int16),
-                SEEK_SET)) break;
+            if ((err = fseek (uptr->fileref, da * sizeof (int16),
+                SEEK_SET))) break;
             fxwrite (dpxb, sizeof (int16), DP_NUMWD, uptr->fileref);
-            if (err = ferror (uptr->fileref)) break;    /* error? */
+            if ((err = ferror (uptr->fileref))) break;  /* error? */
             dp_ptr = 0;                                 /* next sector */
             }
         if (dpd.command && dpd_xfer)                    /* dch on, xfer? */
