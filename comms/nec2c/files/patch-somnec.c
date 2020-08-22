--- somnec.c.orig	2004-01-24 14:17:48 UTC
+++ somnec.c
@@ -21,11 +21,13 @@
 
 /* common /evlcom/ */
 int jh;
-double ck2, ck2sq, tkmag, tsmag, ck1r, zph, rho;
+double ck2, ck2sq, tkmag, tsmag, ck1r, rho;
+extern double zph;
 complex double ct1, ct2, ct3, ck1, ck1sq, cksm;
 
 /* common /cntour/ */
-complex double a, b;
+complex double a;
+extern complex double b;
 
 /*common  /ggrid/ */
 int    nxa[3] = {11,17,9},    nya[3] = {10,5,8};
