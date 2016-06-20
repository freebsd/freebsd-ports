--- src/libsphinx2/cdcn_update.c.orig	2001-12-13 21:11:20 UTC
+++ src/libsphinx2/cdcn_update.c
@@ -47,6 +47,11 @@
  * Modified by Uday Jain, June 95
  *
  *************************************************************************/
+static float initialize (float [][NUM_COEFF+1], int, float *, float *, float,
+			     float [][NUM_COEFF+1], float *, float [][NUM_COEFF+1], int);
+static void correction(float *, float *, float *, float *, int);
+static float max_q (float *, float *, float *, float *, float *,
+			float *, int, float *, int);
 
 float
 cdcn_update (float *z,		/* The observed cepstrum vectors */
@@ -56,13 +61,7 @@ cdcn_update (float *z,		/* The observed 
     float       distortion;
     float	*noise, *tilt, *codebook, *prob, *variance, *corrbook;
     int 	num_codes;
-    /* Multidimensional arrays, gar gar gar */
-    static float initialize (float *, int, float *, float *, float,
-			     float *, float *, float *, int);
-    static void correction(float *, float *, float *, float *, int);
-    static float max_q (float *, float *, float *, float *, float *,
-			float *, int, float *, int);
-
+    
     /*
      * If error, dont bother
      */
