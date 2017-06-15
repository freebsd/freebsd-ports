--- I7094/i7094_mt.c.orig	2016-12-01 22:43:42 UTC
+++ I7094/i7094_mt.c
@@ -564,7 +564,7 @@ switch (uptr->UST) {                    
             bc = chrono_rd (xb, MT_MAXFR);              /* read clock */
         else {                                          /* real tape */
             r = sim_tape_rdrecf (uptr, xb, &bc, MT_MAXFR); /* read record */
-            if (r = mt_map_err (uptr, r))               /* map status */
+            if ((r = mt_map_err (uptr, r)))             /* map status */
                 return r;
             if (mt_unit[ch] == 0)                       /* disconnected? */
                 return SCPE_OK;
@@ -736,7 +736,7 @@ if (mt_bptr[ch]) {                      
     if (xb == NULL)
         return SCPE_IERR;
     r = sim_tape_wrrecf (uptr, xb, mt_bptr[ch]);        /* write record */
-    if (r = mt_map_err (uptr, r))                       /* map error */
+    if ((r = mt_map_err (uptr, r)))                     /* map error */
         return r;
     }
 uptr->UST = CHSL_WRS|CHSL_3RD;                          /* next state */
