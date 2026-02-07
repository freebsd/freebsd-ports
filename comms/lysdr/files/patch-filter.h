--- filter.h.orig	2014-06-02 02:18:30.000000000 -0700
+++ filter.h	2014-06-02 02:18:39.000000000 -0700
@@ -30,7 +30,7 @@
 
 // FIR filter defs
 typedef struct {
-	complex *impulse;
+	complex double *impulse;
 	double *buf_I;
 	double *buf_Q;
 	double *imp_I;
@@ -43,7 +43,7 @@
 filter_fir_t *filter_fir_new(int taps, int size);
 void filter_fir_destroy(filter_fir_t *filter);
 void filter_fir_set_response(filter_fir_t *filter, int sample_rate, float bw, float centre);
-void filter_fir_process(filter_fir_t *filter, complex *samples);
+void filter_fir_process(filter_fir_t *filter, complex double *samples);
 #endif
 
 /* vim: set noexpandtab ai ts=4 sw=4 tw=4: */
