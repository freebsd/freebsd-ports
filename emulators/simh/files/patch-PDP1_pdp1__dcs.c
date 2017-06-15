--- PDP1/pdp1_dcs.c.orig	2016-12-01 22:43:42 UTC
+++ PDP1/pdp1_dcs.c
@@ -251,7 +251,7 @@ if (ln >= 0) {                          
 tmxr_poll_rx (&dcs_desc);                               /* poll for input */
 for (ln = 0; ln < DCS_NUMLIN; ln++) {                   /* loop thru lines */
     if (dcs_ldsc[ln].conn) {                            /* connected? */
-        if (c = tmxr_getc_ln (&dcs_ldsc[ln])) {         /* get char */
+        if ((c = tmxr_getc_ln (&dcs_ldsc[ln]))) {       /* get char */
             if (c & SCPE_BREAK)                         /* break? */
                 c = 0;
             else c = sim_tt_inpcvt (c, TT_GET_MODE (dcsl_unit[ln].flags)|TTUF_KSR);
