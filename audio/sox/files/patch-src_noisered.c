
$FreeBSD$

--- src/noisered.c.orig
+++ src/noisered.c
@@ -126,6 +126,7 @@
  * due to overlapping windows. */
 static void reduce_noise(chandata_t* chan, float* window, float level)
 {
+    int i;
     float *inr   = (float*)calloc(WINDOWSIZE, sizeof(float));
     float *ini   = (float*)calloc(WINDOWSIZE, sizeof(float));
     float *outr  = (float*)calloc(WINDOWSIZE, sizeof(float));
@@ -135,8 +136,6 @@
     static int callnum = 0;
 
     callnum ++;
-
-    int i;
 
     for (i = 0; i < FREQCOUNT; i ++) {
         assert(smoothing[i] >= 0 && smoothing[i] <= 1);
