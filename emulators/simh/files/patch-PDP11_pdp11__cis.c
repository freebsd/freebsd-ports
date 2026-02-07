--- PDP11/pdp11_cis.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_cis.c
@@ -1134,7 +1134,7 @@ switch (op) {                           
         result = (A2ADR << 16) | A2LNT;                 /* op in VAX format */
     CVTLx:
         dst = Dstr0;                                    /* clear result */
-        if (dst.sign = GET_SIGN_L (result))
+        if ((dst.sign = GET_SIGN_L (result)))
             result = (~result + 1) & 0xFFFFFFFF;
         for (i = 1; (i < (DSTRLNT * 8)) && result; i++) {
             digit = result % 10;
@@ -1267,7 +1267,7 @@ for (i = 0; i < DSTRLNT; i++) {         
         mask = 0xFFFFFFFF;
     if (dst->val[i] & mask)                             /* test for ovflo */
         V = 1;
-    if (dst->val[i] = dst->val[i] & ~mask)              /* test nz */
+    if ((dst->val[i] = dst->val[i] & ~mask))            /* test nz */
         Z = 0;
     }
 dst->sign = dst->sign & ~unsignedtab[type] & ~(Z & ~V);
@@ -1523,7 +1523,7 @@ uint32 NibbleRshift (DSTR *dsrc, int32 s
 {
 int32 i, s, nc;
 
-if (s = sc * 4) {
+if ((s = sc * 4)) {
     for (i = DSTRMAX; i >= 0; i--) {
         nc = (dsrc->val[i] << (32 - s)) & 0xFFFFFFFF;
         dsrc->val[i] = ((dsrc->val[i] >> s) |
@@ -1548,7 +1548,7 @@ int32 i, s;
 uint32 nc, cin;
 
 cin = 0;
-if (s = sc * 4) {
+if ((s = sc * 4)) {
     for (i = 0; i < DSTRLNT; i++) {
         nc = dsrc->val[i] >> (32 - s);
         dsrc->val[i] = ((dsrc->val[i] << s) | cin) & 0xFFFFFFFF;
