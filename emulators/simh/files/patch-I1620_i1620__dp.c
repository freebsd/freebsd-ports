--- I1620/i1620_dp.c.orig	2016-12-01 22:43:42 UTC
+++ I1620/i1620_dp.c
@@ -206,7 +206,7 @@ switch (f1 & ~(FNC_WCH | FNC_NRL)) {    
         if (psec < 0)                                   /* error? */
             CRETIOE (dp_stop, STOP_DACERR);
         do {                                            /* loop on count */
-            if (r = dp_rdsec (uptr, psec, qnr, qwc))    /* read sector */
+            if ((r = dp_rdsec (uptr, psec, qnr, qwc)))  /* read sector */
                 break;
             sec++; psec++;                              /* next sector */
             } while ((--cnt > 0) &&
@@ -216,9 +216,9 @@ switch (f1 & ~(FNC_WCH | FNC_NRL)) {    
     case FNC_TRK:                                       /* read track */
         psec = dp_trkop (drv, sec);                     /* start of track */
         for (cnt = 0; cnt < DP_NUMSC; cnt++) {          /* full track */
-            if (r = dp_rdadr (uptr, psec, qnr, qwc))    /* read addr */
+            if ((r = dp_rdadr (uptr, psec, qnr, qwc)))  /* read addr */
                 break;                                  /* error? */
-            if (r = dp_rdsec (uptr, psec, qnr, qwc))    /* read data */
+            if ((r = dp_rdsec (uptr, psec, qnr, qwc)))  /* read data */
                 break;                                  /* error? */
             psec = dp_trkop (drv, sec) + ((psec + 1) % DP_NUMSC);
             }
@@ -231,9 +231,9 @@ switch (f1 & ~(FNC_WCH | FNC_NRL)) {    
         if (psec < 0)                                   /* error? */
             CRETIOE (dp_stop, STOP_DACERR);
         do {                                            /* loop on count */
-            if (r = dp_tstgm (M[dp_ba], qnr))           /* start with gm? */
+            if ((r = dp_tstgm (M[dp_ba], qnr)))         /* start with gm? */
                 break;
-            if (r = dp_wrsec (uptr, psec, qnr))         /* write data */
+            if ((r = dp_wrsec (uptr, psec, qnr)))       /* write data */
                 break;
             sec++; psec++;                              /* next sector */
             } while ((--cnt > 0) &&
@@ -245,11 +245,11 @@ switch (f1 & ~(FNC_WCH | FNC_NRL)) {    
                 return STOP_WRADIS;
         psec = dp_trkop (drv, sec);                     /* start of track */
         for (cnt = 0; cnt < DP_NUMSC; cnt++) {          /* full track */
-            if (r = dp_tstgm (M[dp_ba], qnr))           /* start with gm? */
+            if ((r = dp_tstgm (M[dp_ba], qnr)))         /* start with gm? */
                 break;
-            if (r = dp_wradr (uptr, psec, qnr))         /* write addr */
+            if ((r = dp_wradr (uptr, psec, qnr)))       /* write addr */
                 break;
-            if (r = dp_wrsec (uptr, psec, qnr))         /* write data */
+            if ((r = dp_wrsec (uptr, psec, qnr)))       /* write data */
                 break;
             psec = dp_trkop (drv, sec) + ((psec + 1) % DP_NUMSC);
             }
