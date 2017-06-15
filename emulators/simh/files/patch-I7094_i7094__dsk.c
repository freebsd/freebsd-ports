--- I7094/i7094_dsk.c.orig	2016-12-01 22:43:42 UTC
+++ I7094/i7094_dsk.c
@@ -693,14 +693,14 @@ trk = uaptr->TRK;                       
 switch (dsk_sta) {                                      /* case on state */
 
     case CHSL_RDS:                                      /* read start */
-        if (r = dsk_init_trk (udptr, trk)) {            /* read track, err? */
+        if ((r = dsk_init_trk (udptr, trk))) {          /* read track, err? */
             return ((r == ERR_NRCF)? SCPE_OK: r);       /* rec not fnd ok */
             }
         dsk_sta = CHSL_RDS|CHSL_2ND;                    /* next state */
         break;
 
     case CHSL_RDS|CHSL_2ND:                             /* read data transmit */
-        if (r = dsk_xfer_done (uaptr, dtyp)) {          /* transfer done? */
+        if ((r = dsk_xfer_done (uaptr, dtyp))) {        /* transfer done? */
             if (r != ERR_ENDRC)                         /* error? */
                 return r;
             dsk_sta = CHSL_RDS|CHSL_3RD;                /* next state */
@@ -721,7 +721,7 @@ switch (dsk_sta) {                      
         break;
 
     case CHSL_WRS:                                      /* write start */
-        if (r = dsk_init_trk (udptr, trk)) {            /* read track, err? */
+        if ((r = dsk_init_trk (udptr, trk))) {          /* read track, err? */
             return ((r == ERR_NRCF)? SCPE_OK: r);       /* rec not fnd ok */
             }
         ch_req |= REQ_CH (dsk_ch);                      /* first request */
@@ -742,7 +742,7 @@ switch (dsk_sta) {                      
         else dsk_buf[dsk_rptr++] = dsk_chob;            /* write, store word */
         if (dsk_rptr == T1STREC)                        /* if THA, skip after HA */
             dsk_rptr++;
-        if (r = dsk_xfer_done (uaptr, dtyp)) {          /* transfer done? */
+        if ((r = dsk_xfer_done (uaptr, dtyp))) {        /* transfer done? */
             if (r != ERR_ENDRC)                         /* error? */
                 return r;
             dsk_sta = CHSL_WRS|CHSL_3RD;                /* next state */
@@ -755,7 +755,7 @@ switch (dsk_sta) {                      
 
     case CHSL_WRS|CHSL_3RD:                             /* write done */
         if (!dsk_wchk) {                                /* if write */
-            if (r = dsk_wr_trk (udptr, trk))            /* write track; err? */
+            if ((r = dsk_wr_trk (udptr, trk)))          /* write track; err? */
                 return r;
             }
         if (dsk_qdone (dsk_ch))                         /* done? exit */
@@ -846,7 +846,7 @@ switch (dsk_sta) {                      
             if (!dsk_wchk) {                            /* actual write? */
                 trk = trk - (trk % dsk_tab[dtyp].trkpc);        /* cyl start */
                 for (i = 0; i < dsk_tab[dtyp].trkpc; i++) {     /* do all tracks */
-                    if (r = dsk_wr_trk (udptr,  trk + i))       /* wr track; err? */
+                    if ((r = dsk_wr_trk (udptr,  trk + i)))     /* wr track; err? */
                         return r;
                     }
                 }
