--- PDP8/pdp8_ttx.c.orig	2016-12-01 22:43:43 UTC
+++ PDP8/pdp8_ttx.c
@@ -233,7 +233,7 @@ if (ln >= 0)                            
 tmxr_poll_rx (&ttx_desc);                               /* poll for input */
 for (ln = 0; ln < TTX_LINES; ln++) {                    /* loop thru lines */
     if (ttx_ldsc[ln].conn) {                            /* connected? */
-        if (temp = tmxr_getc_ln (&ttx_ldsc[ln])) {      /* get char */
+        if ((temp = tmxr_getc_ln (&ttx_ldsc[ln]))) {    /* get char */
             if (temp & SCPE_BREAK)                      /* break? */
                 c = 0;
             else c = sim_tt_inpcvt (temp, TT_GET_MODE (ttox_unit[ln].flags));
