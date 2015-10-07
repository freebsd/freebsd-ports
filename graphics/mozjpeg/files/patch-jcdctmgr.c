--- jcdctmgr.c.orig	2015-05-18 14:28:09 UTC
+++ jcdctmgr.c
@@ -6,7 +6,7 @@
  * libjpeg-turbo Modifications:
  * Copyright (C) 1999-2006, MIYASAKA Masaru.
  * Copyright 2009 Pierre Ossman <ossman@cendio.se> for Cendio AB
- * Copyright (C) 2011, 2014 D. R. Commander
+ * Copyright (C) 2011, 2014-2015 D. R. Commander
  * mozjpeg Modifications:
  * Copyright (C) 2014, Mozilla Corporation.
  * For conditions of distribution and use, see the accompanying README file.
@@ -185,6 +185,19 @@ compute_reciprocal (UINT16 divisor, DCTE
   UDCTELEM c;
   int b, r;
 
+  if (divisor == 1) {
+    /* divisor == 1 means unquantized, so these reciprocal/correction/shift
+     * values will cause the C quantization algorithm to act like the
+     * identity function.  Since only the C quantization algorithm is used in
+     * these cases, the scale value is irrelevant.
+     */
+    dtbl[DCTSIZE2 * 0] = (DCTELEM) 1;                       /* reciprocal */
+    dtbl[DCTSIZE2 * 1] = (DCTELEM) 0;                       /* correction */
+    dtbl[DCTSIZE2 * 2] = (DCTELEM) 1;                       /* scale */
+    dtbl[DCTSIZE2 * 3] = (DCTELEM) (-sizeof(DCTELEM) * 8);  /* shift */
+    return 0;
+  }
+
   b = flss(divisor) - 1;
   r  = sizeof(DCTELEM) * 8 + b;
 
@@ -589,7 +602,8 @@ quantize (JCOEFPTR coef_block, DCTELEM *
 
 #if BITS_IN_JSAMPLE == 8
 
-  UDCTELEM recip, corr, shift;
+  UDCTELEM recip, corr;
+  int shift;
   UDCTELEM2 product;
 
   for (i = 0; i < DCTSIZE2; i++) {
