--- PDP18B/pdp18b_tt1.c.orig	2016-12-01 22:43:42 UTC
+++ PDP18B/pdp18b_tt1.c
@@ -222,7 +222,7 @@ if (ln >= 0)                            
 tmxr_poll_rx (&ttx_desc);                               /* poll for input */
 for (ln = 0; ln < TTX_MAXL; ln++) {                     /* loop thru lines */
     if (ttx_ldsc[ln].conn) {                            /* connected? */
-        if (temp = tmxr_getc_ln (&ttx_ldsc[ln])) {      /* get char */
+        if ((temp = tmxr_getc_ln (&ttx_ldsc[ln]))) {    /* get char */
             if (temp & SCPE_BREAK)                      /* break? */
                 c = 0;
             else c = sim_tt_inpcvt (temp, TT_GET_MODE (ttox_unit[ln].flags) | TTUF_KSR);
