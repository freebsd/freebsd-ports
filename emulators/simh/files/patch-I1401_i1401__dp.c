--- I1401/i1401_dp.c.orig	2016-12-01 22:43:42 UTC
+++ I1401/i1401_dp.c
@@ -269,7 +269,7 @@ switch (fnc) {                          
         for (;;) {                                      /* loop */
             qzr = (--cnt == 0);                         /* set zero latch */
             dp_cvt_bin (dcf + DCF_CNT, DCF_CNT_LEN, cnt, MD_WM); /* redo count */
-            if (r = dp_rdsec (uptr, psec, flg, qwc))    /* read sector */
+            if ((r = dp_rdsec (uptr, psec, flg, qwc)))  /* read sector */
                 break;
             cnt = dp_get_cnt (dcf);                     /* get new count */
             if (cnt < 0)                                /* bad count? */
@@ -278,7 +278,7 @@ switch (fnc) {                          
                 break;
             sec++; psec++;                              /* next sector */
             dp_cvt_bin (dcf + DCF_SEC, DCF_SEC_LEN, sec, flg); /* rewr sec */
-            if (r = dp_nexsec (uptr, psec, dcf))        /* find next */
+            if ((r = dp_nexsec (uptr, psec, dcf)))      /* find next */
                 break;
             }
         break;                                          /* done, clean up */
@@ -289,9 +289,9 @@ switch (fnc) {                          
         for (;;) {                                      /* loop */
             qzr = (--cnt == 0);                         /* set zero latch */
             dp_cvt_bin (dcf + DCF_CNT, DCF_CNT_LEN, cnt, MD_WM); /* redo count */
-            if (r = dp_rdadr (uptr, psec, flg, qwc))    /* read addr */
+            if ((r = dp_rdadr (uptr, psec, flg, qwc)))  /* read addr */
                 break;                                  /* error? */
-            if (r = dp_rdsec (uptr, psec, flg, qwc))    /* read data */
+            if ((r = dp_rdsec (uptr, psec, flg, qwc)))  /* read data */
                 break;                                  /* error? */
             cnt = dp_get_cnt (dcf);                     /* get new count */
             if (cnt < 0)                                /* bad count? */
@@ -312,13 +312,13 @@ switch (fnc) {                          
         for (;;) {                                      /* loop */
             qzr = (--cnt == 0);                         /* set zero latch */
             dp_cvt_bin (dcf + DCF_CNT, DCF_CNT_LEN, cnt, MD_WM); /* rewr cnt */
-            if (r = dp_wrsec (uptr, psec, flg))         /* write data */
+            if ((r = dp_wrsec (uptr, psec, flg)))       /* write data */
                 break;
             if (qzr)                                    /* zero latch? done */
                 break;
             sec++; psec++;                              /* next sector */
             dp_cvt_bin (dcf + DCF_SEC, DCF_SEC_LEN, sec, flg); /* rewr sec */
-            if (r = dp_nexsec (uptr, psec, dcf))        /* find next */
+            if ((r = dp_nexsec (uptr, psec, dcf)))      /* find next */
                 break;
             }
         break;                                          /* done, clean up */
@@ -331,9 +331,9 @@ switch (fnc) {                          
         for (;;) {                                      /* loop */
             qzr = (--cnt == 0);                         /* set zero latch */
             dp_cvt_bin (dcf + DCF_CNT, DCF_CNT_LEN, cnt, MD_WM); /* redo count */
-            if (r = dp_wradr (uptr, psec, flg))         /* write addr */
+            if ((r = dp_wradr (uptr, psec, flg)))       /* write addr */
                 break;
-            if (r = dp_wrsec (uptr, psec, flg))         /* write data */
+            if ((r = dp_wrsec (uptr, psec, flg)))       /* write data */
                 break;
             if (qzr)                                    /* zero latch? done */
                 break;
