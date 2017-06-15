--- SDS/sds_mux.c.orig	2016-12-01 22:43:43 UTC
+++ SDS/sds_mux.c
@@ -363,7 +363,7 @@ if (ln >= 0) {                          
 tmxr_poll_rx (&mux_desc);                               /* poll for input */
 for (ln = 0; ln < MUX_NUMLIN; ln++) {                   /* loop thru lines */
     if (mux_ldsc[ln].conn) {                            /* connected? */
-        if (c = tmxr_getc_ln (&mux_ldsc[ln])) {         /* get char */
+        if ((c = tmxr_getc_ln (&mux_ldsc[ln]))) {       /* get char */
             if (mux_sta[ln] & MUX_SCHP)                 /* already got one? */
                 mux_sta[ln] = mux_sta[ln] | MUX_SOVR;   /* overrun */
             else mux_sta[ln] = mux_sta[ln] | MUX_SCHP;  /* char pending */
