--- filter.c.orig	2011-11-26 16:01:22.000000000 -0800
+++ filter.c	2014-06-02 03:50:20.000000000 -0700
@@ -22,16 +22,19 @@
 #include <stdlib.h>
 #include <complex.h>
 #include <math.h>
+
+double complex cexp(double complex z);
+
 #include "filter.h"
 #include "sdr.h"
 
 #define IS_ALMOST_DENORMAL(f) (fabs(f) < 3.e-34)
 
-static void make_impulse(complex fir_imp[], float sample_rate, int taps, float bw, float centre) {
+static void make_impulse(complex double fir_imp[], float sample_rate, int taps, float bw, float centre) {
 
 	float K = bw * taps / sample_rate;
 	float w;
-	complex z;
+	complex double z;
 	int k, i=0;
 
 	float tune = 2.0 * M_PI * centre / sample_rate;
@@ -57,7 +60,7 @@
 	filter_fir_t *filter = malloc(sizeof(filter_fir_t));
 	filter->taps = taps;
 	filter->size = size;
-	filter->impulse = malloc(sizeof(complex)*taps);
+	filter->impulse = malloc(sizeof(complex double)*taps);
 	filter->imp_I = malloc(sizeof(double)*taps);
 	filter->imp_Q = malloc(sizeof(double)*taps);
 	filter->buf_I = malloc(sizeof(double)*taps);
@@ -89,11 +92,11 @@
 	} 
 }
 
-void filter_fir_process(filter_fir_t *filter, complex *samples) {
+void filter_fir_process(filter_fir_t *filter, complex double *samples) {
 	// Perform an FIR filter on the data "in place"
 	// this routine is slow and has a horrible hack to avoid denormals
 	int i, j, k;
-	complex c;
+	complex double c;
 	double accI, accQ;
 	double *buf_I = filter->buf_I;
 	double *buf_Q = filter->buf_Q;
