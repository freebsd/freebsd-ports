--- src/libsphinx2/cdcn_update.c.orig	Fri Sep 17 14:17:51 2004
+++ src/libsphinx2/cdcn_update.c	Fri Sep 17 14:26:32 2004
@@ -57,8 +57,8 @@
     float	*noise, *tilt, *codebook, *prob, *variance, *corrbook;
     int 	num_codes;
     /* Multidimensional arrays, gar gar gar */
-    static float initialize (float *, int, float *, float *, float,
-			     float *, float *, float *, int);
+    static float initialize (float [][NUM_COEFF+1], int, float *, float *, float,
+			     float [][NUM_COEFF+1], float *, float [][NUM_COEFF+1], int);
     static void correction(float *, float *, float *, float *, int);
     static float max_q (float *, float *, float *, float *, float *,
 			float *, int, float *, int);
