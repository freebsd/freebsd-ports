--- PDP10/pdp10_lp20.c.orig	2016-12-01 22:43:42 UTC
+++ PDP10/pdp10_lp20.c
@@ -563,7 +563,7 @@ lp20_unit.pos = ftell (lp20_unit.fileref
 if (dvuadv)                                             /* update DAVFU ptr */
     dvptr = (dvptr + cnt) % dvlnt;
 if (davfu[dvptr] & (1 << DV_TOF)) {                     /* at top of form? */
-    if (lppagc = (lppagc - 1) & PAGC_MASK) {            /* decr page cntr */
+    if ((lppagc = (lppagc - 1) & PAGC_MASK)) {          /* decr page cntr */
         lpcsa = lpcsa & ~CSA_PZRO;                      /* update status */
         return TRUE;
         }
@@ -592,7 +592,7 @@ for (i = 0; i < dvlnt; i++) {           
             lp20_adv (1, FALSE);
         fputc ('\f', lp20_unit.fileref);                /* print form feed */
         lp20_unit.pos = ftell (lp20_unit.fileref); 
-        if (lppagc = (lppagc - 1) & PAGC_MASK) {        /* decr page cntr */
+        if ((lppagc = (lppagc - 1) & PAGC_MASK)) {      /* decr page cntr */
             lpcsa = lpcsa & ~CSA_PZRO;                  /* update status */
             return TRUE;
             }
