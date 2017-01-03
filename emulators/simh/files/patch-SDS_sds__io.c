--- SDS/sds_io.c.orig	2016-12-01 22:43:43 UTC
+++ SDS/sds_io.c
@@ -336,7 +336,7 @@ switch (mod) {
             chan_mode[ch] = chan_uar[ch] = 0;
             if (ch >= CHAN_E)
                 chan_mode[ch] = CHM_CE;
-            if (r = dev_dsp[dev][ch] (IO_CONN, inst, NULL)) /* connect */
+            if ((r = dev_dsp[dev][ch] (IO_CONN, inst, NULL))) /* connect */
                 return r;
             if ((inst & I_IND) || (ch >= CHAN_C)) {     /* C-H? alert ilc */
                 alert = POT_ILCY + ch;
@@ -958,7 +958,7 @@ for (i = 0; i < NUM_CHAN; i++) {
 
 /* Test each device for conflict; add to map; init tables */
 
-for (i = 0; dptr = sim_devices[i]; i++) {               /* loop thru devices */
+for (i = 0; (dptr = sim_devices[i]); i++) {             /* loop thru devices */
     dibp = (DIB *) dptr->ctxt;                          /* get DIB */
     if ((dibp == NULL) || (dptr->flags & DEV_DIS))      /* exist, enabled? */
         continue;
