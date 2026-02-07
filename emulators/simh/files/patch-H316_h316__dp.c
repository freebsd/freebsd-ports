--- H316/h316_dp.c.orig	2016-12-01 22:43:42 UTC
+++ H316/h316_dp.c
@@ -617,7 +617,7 @@ switch (uptr->FNC) {                    
     case FNC_RCA:                                       /* read current addr */
         if (h >= dp_tab[dp_ctype].surf)                 /* invalid head? */
             return dp_done (1, STA_ADRER);              /* error */
-        if (r = dp_rdtrk (uptr, dpxb, uptr->CYL, h))    /* get track; error? */
+        if ((r = dp_rdtrk (uptr, dpxb, uptr->CYL, h)))  /* get track; error? */
             return r;
         dp_rptr = 0;                                    /* init rec ptr */
         if (dpxb[dp_rptr + REC_LNT] == 0)               /* unformated? */
@@ -722,7 +722,7 @@ switch (uptr->FNC) {                    
     case FNC_RW:                                        /* read/write */
         if (h >= dp_tab[dp_ctype].surf)                 /* invalid head? */
             return dp_done (1, STA_ADRER);              /* error */
-        if (r = dp_rdtrk (uptr, dpxb, uptr->CYL, h))    /* get track; error? */
+        if ((r = dp_rdtrk (uptr, dpxb, uptr->CYL, h)))  /* get track; error? */
             return r;
         if (!dp_findrec (dp_cw2))                       /* find rec; error? */
             return dp_done (1, STA_ADRER);              /* address error */
@@ -750,7 +750,7 @@ switch (uptr->FNC) {                    
         if (dp_cw1 & CW1_RW) {                          /* write? */
             if (dp_sta & STA_RDY)                       /* timing failure? */
                 return dp_wrdone (uptr, STA_DTRER);     /* yes, error */
-            if (r = dp_wrwd (uptr, dp_buf))             /* wr word, error? */
+            if ((r = dp_wrwd (uptr, dp_buf)))           /* wr word, error? */
                 return r;
             if (dp_eor) {                               /* transfer done? */
                 dpxb[dp_rptr + REC_DATA + dp_wptr] = dp_csum;
@@ -855,7 +855,7 @@ if (dp_wptr < (lnt + REC_MAXEXT)) {
     }
 dpxb[dp_rptr + REC_DATA + dp_wptr] = dp_csum;           /* write csum */
 dpxb[dp_rptr + lnt + REC_OVHD] = 0;                     /* zap rest of track */
-if (r = dp_wrdone (uptr, STA_UNSER))                    /* dump track */
+if ((r = dp_wrdone (uptr, STA_UNSER)))                  /* dump track */
     return r;
 return STOP_DPOVR;
 }       
@@ -1017,7 +1017,7 @@ for (c = cntr = 0; c < dp_tab[dp_ctype].
             else tbuf[rptr + REC_ADDR] = (c << 8) + (h << 3) + i;
             rptr = rptr + nw + REC_OVHD;
             }
-        if (r = dp_wrtrk (uptr, tbuf, c, h))
+        if ((r = dp_wrtrk (uptr, tbuf, c, h)))
             return r;
         }
     }
@@ -1043,7 +1043,7 @@ if ((uptr->flags & UNIT_ATT) == 0)
     return SCPE_UNATT;
 for (c = 0; c < dp_tab[dp_ctype].cyl; c++) {
     for (h = 0; h < dp_tab[dp_ctype].surf; h++) {
-        if (r = dp_rdtrk (uptr, tbuf, c, h))
+        if ((r = dp_rdtrk (uptr, tbuf, c, h)))
             return r;
         rptr = 0;
         rlnt = tbuf[rptr + REC_LNT];
