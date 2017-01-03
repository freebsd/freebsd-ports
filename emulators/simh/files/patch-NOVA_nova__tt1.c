--- NOVA/nova_tt1.c.orig	2016-12-01 22:43:42 UTC
+++ NOVA/nova_tt1.c
@@ -184,7 +184,7 @@ int32 temp, newln;
 
 if (tt1_ldsc.conn) {                                    /* connected? */
     tmxr_poll_rx (&tt_desc);                            /* poll for input */
-    if (temp = tmxr_getc_ln (&tt1_ldsc)) {              /* get char */ 
+    if ((temp = tmxr_getc_ln (&tt1_ldsc))) {            /* get char */ 
         uptr->buf = temp & 0177;
         if ((uptr->flags & UNIT_DASHER) &&
             (uptr->buf == '\r'))
