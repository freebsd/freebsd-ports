--- Interdata/id_pas.c.orig	2016-12-01 22:43:42 UTC
+++ Interdata/id_pas.c
@@ -334,7 +334,7 @@ if (ln >= 0) {                          
 tmxr_poll_rx (&pas_desc);                               /* poll for input */
 for (ln = 0; ln < PAS_ENAB; ln++) {                     /* loop thru lines */
     if (pas_ldsc[ln].conn) {                            /* connected? */
-        if (c = tmxr_getc_ln (&pas_ldsc[ln])) {         /* any char? */
+        if ((c = tmxr_getc_ln (&pas_ldsc[ln]))) {       /* any char? */
             pas_sta[ln] = pas_sta[ln] & ~(STA_FR | STA_PF);
             if (pas_rchp[ln])
                 pas_sta[ln] = pas_sta[ln] | STA_OVR;
