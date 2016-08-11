--- src/libsphinx2/blk_cdcn_norm.c.orig	2001-12-13 21:11:20 UTC
+++ src/libsphinx2/blk_cdcn_norm.c
@@ -36,6 +36,18 @@
 #include <math.h>
 #include "cdcn.h"
 
+static void
+block_actual_cdcn_norm(float variance[][NUM_COEFF+1], /* Speech cepstral variances of modes */
+		       float *prob,  /* Ratio of a-prori mode probs. to mod variance */
+		       float *tilt,  /* Spectral tilt cepstrum */
+		       float *noise, /* Noise estimate */
+		       float means[][NUM_COEFF+1], /* The cepstrum codebook */
+		       float corrbook[][NUM_COEFF+1], /* The correction factor's codebook */
+		       int num_codes, /* Number of codewords in codebook */
+		       float z[][NUM_COEFF+1], /* The input cepstrum */
+		       int num_frames); /* Number of frames in utterance */
+
+
 /************************************************************************
  *   Dummy routine to convert from suitcase to sane varibles
  ***************************************************************************/
@@ -46,7 +58,6 @@ void block_cdcn_norm (float z[][NUM_COEF
 {
     /* Multidimensional arrays in C suck, so we have to
        forward-declare-hack this. */
-    static void block_actual_cdcn_norm();
     float *variance, *prob, *tilt, *noise, *codebook, *corrbook;
     int    num_codes;
 
@@ -88,7 +99,6 @@ void block_cdcn_norm (float z[][NUM_COEF
  * Coded by Alex Acero (acero@s),  November 1989 
  *
  *************************************************************************/
-
 static void
 block_actual_cdcn_norm(float variance[][NUM_COEFF+1], /* Speech cepstral variances of modes */
 		       float *prob,  /* Ratio of a-prori mode probs. to mod variance */
