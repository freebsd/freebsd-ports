--- I1401/i1401_mt.c.orig	2016-12-01 22:43:42 UTC
+++ I1401/i1401_mt.c
@@ -451,7 +451,7 @@ int32 i;
 UNIT *uptr;
 
 for (i = 0; i < MT_NUMDR; i++) {                        /* per drive resets */
-    if (uptr = mt_sel_unit (i)) {
+    if ((uptr = mt_sel_unit (i))) {
         MT_CLR_PNU (uptr);                              /* clear pos flag */
         }
     }
