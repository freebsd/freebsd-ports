--- PDP10/pdp10_rp.c.orig	2016-12-01 22:43:42 UTC
+++ PDP10/pdp10_rp.c
@@ -951,7 +951,7 @@ switch (uptr->FUNC) {                   
                 if ((rpcs2 & CS2_UAI) == 0)
                     ba = ba + 4;
                 }
-            if (fc10 = twc10 & (RP_NUMWD - 1)) {        /* fill? */
+            if ((fc10 = twc10 & (RP_NUMWD - 1))) {      /* fill? */
                 fc10 = RP_NUMWD - fc10;
                 for (i = 0; i < fc10; i++)
                     dbuf[twc10 + i] = 0;
