--- src/libsphinx2/cdcn_norm.c.orig	2007-12-06 19:24:33.000000000 +0100
+++ src/libsphinx2/cdcn_norm.c	2007-12-06 19:26:24.000000000 +0100
@@ -35,6 +35,15 @@
  */
 #include <math.h>
 #include "cdcn.h"
+static void
+actual_cdcn_norm(float variance[][NUM_COEFF+1], /* Speech cepstral variances of modes */
+		 float *prob,  /* Ratio of a-prori mode probs. to mod variance */
+		 float *tilt,  /* Spectral tilt cepstrum */
+		 float *noise, /* Noise estimate */
+		 float means[][NUM_COEFF+1], /* The cepstrum codebook */
+		 float corrbook[][NUM_COEFF+1], /* The correction factor's codebook */
+		 int num_codes, /* Number of codewords in codebook */
+		 float z[NUM_COEFF+1]); /* The input cepstrum */
 
 /************************************************************************
  *   Dummy routine to convert from suitcase to sane varibles
@@ -43,8 +52,6 @@
 void cdcn_norm (float z[NUM_COEFF+1], /* The input cepstrum */
 		CDCN_type *cdcn_variables)
 {
-    /* Multidimensional arrays, yuck. */
-    static void actual_cdcn_norm();
     float *variance, *prob, *tilt, *noise, *codebook, *corrbook;
     int num_codes;
 
