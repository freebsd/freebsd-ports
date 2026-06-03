--- src/frequency_sort.c.orig	2026-03-01 17:09:43 UTC
+++ src/frequency_sort.c
@@ -1,5 +1,5 @@
 #include "bliss.h"
-#include <libavcodec/avfft.h>
+#include <libavutil/tx.h>
 #include <math.h>
 
 // Number of bits in the FFT, log2 of the length
@@ -19,15 +19,18 @@ float bl_frequency_sort(struct bl_song const *const so
 
 float bl_frequency_sort(struct bl_song const *const song) {
   // FFT transform context
-  RDFTContext *fft;
+  AVTXContext *fft = NULL;
+  av_tx_fn tx_fn;
   // Hann window values
   float hann_window[WINDOW_SIZE];
   // Number of frames, that is number of juxtaposed windows in the music
   int n_frames;
   // Complex DFT of input
-  FFTSample *x;
+  float *x;
+  // Complex output from FFT
+  AVComplexFloat *x_out;
   // Hold FFT power spectrum
-  FFTSample *power_spectrum;
+  float *power_spectrum;
   // Power maximum value
   float peak = 0;
 
@@ -50,19 +53,28 @@ float bl_frequency_sort(struct bl_song const *const so
   n_frames = floor((song->nSamples / song->channels) / WINDOW_SIZE);
 
   // Allocate memory for x vector
-  x = (FFTSample *)av_malloc(WINDOW_SIZE * sizeof(FFTSample));
+  x = (float *)av_malloc(WINDOW_SIZE * sizeof(float));
 
+  // Allocate memory for complex output
+  x_out = (AVComplexFloat *)av_malloc(WINDOW_SIZE * sizeof(AVComplexFloat));
+
   // Zero-initialize power spectrum
-  power_spectrum = (FFTSample *)av_malloc(
-      (WINDOW_SIZE * sizeof(FFTSample)) / 2 + 1 * sizeof(FFTSample));
+  power_spectrum = (float *)av_malloc(
+      (WINDOW_SIZE / 2 + 1) * sizeof(float));
   for (int i = 0; i <= WINDOW_SIZE / 2;
        ++i) { // 2 factor due to x's complex nature and power_spectrum's real
               // nature.
     power_spectrum[i] = 0.0f;
   }
 
-  // Initialize fft
-  fft = av_rdft_init(WIN_BITS, DFT_R2C);
+  // Initialize fft with new AVTXContext API
+  float scale = 1.0f;
+  if (av_tx_init(&fft, &tx_fn, AV_TX_FLOAT_RDFT, 0, WINDOW_SIZE, &scale, 0) < 0) {
+    av_free(x);
+    av_free(x_out);
+    av_free(power_spectrum);
+    return 0.0f;
+  }
 
   for (int i = 0; i < n_frames * WINDOW_SIZE * song->channels;
        i += song->channels * WINDOW_SIZE) {
@@ -80,14 +92,13 @@ float bl_frequency_sort(struct bl_song const *const so
     }
 
     // Compute FFT
-    av_rdft_calc(fft, x);
+    tx_fn(fft, x_out, x, sizeof(float));
 
     // Fill-in power spectrum
-    power_spectrum[0] =
-        x[0] * x[0]; // Ignore x[1] due to ffmpeg's fft specifity
+    power_spectrum[0] = x_out[0].re * x_out[0].re;
     for (int d = 1; d < WINDOW_SIZE / 2; ++d) {
-      float re = x[d * 2];
-      float im = x[d * 2 + 1];
+      float re = x_out[d].re;
+      float im = x_out[d].im;
       float raw = (re * re) + (im * im);
       power_spectrum[d] += raw;
     }
@@ -130,8 +141,9 @@ float bl_frequency_sort(struct bl_song const *const so
 
   // Clean everything
   av_free(x);
+  av_free(x_out);
   av_free(power_spectrum);
-  av_rdft_end(fft);
+  av_tx_uninit(&fft);
 
   // Return final score, weighted by coefficients in order to have -4 for a
   // panel of calm songs, and 4 for a panel of loud songs. (only useful if you
