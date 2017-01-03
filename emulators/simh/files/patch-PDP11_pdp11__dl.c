--- PDP11/pdp11_dl.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_dl.c
@@ -346,7 +346,7 @@ if (ln >= 0) {                          
 tmxr_poll_rx (&dlx_desc);                               /* poll for input */
 for (ln = 0; ln < DLX_LINES; ln++) {                    /* loop thru lines */
     if (dlx_ldsc[ln].conn) {                            /* connected? */
-        if (temp = tmxr_getc_ln (&dlx_ldsc[ln])) {      /* get char */
+        if ((temp = tmxr_getc_ln (&dlx_ldsc[ln]))) {    /* get char */
             if (temp & SCPE_BREAK)                      /* break? */
                 c = DLIBUF_ERR|DLIBUF_RBRK;
             else c = sim_tt_inpcvt (temp, TT_GET_MODE (dlo_unit[ln].flags));
