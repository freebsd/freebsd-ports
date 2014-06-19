--- sdr.h.orig	2011-11-26 16:01:22.000000000 -0800
+++ sdr.h	2014-06-02 02:33:44.000000000 -0700
@@ -46,9 +46,9 @@
 } fft_data_t;
 
 typedef struct {
-	complex *iqSample;  // the array of incoming samples
-	complex loVector;   // local oscillator vector
-	complex loPhase;	// local oscillator phase angle (sets tuning)
+	complex double *iqSample;  // the array of incoming samples
+	complex double loVector;   // local oscillator vector
+	complex double loPhase;	// local oscillator phase angle (sets tuning)
 	gdouble *output;	 // pointer to output samples
 
 	GtkObject *tuning;  // adjustment for tuning
@@ -63,7 +63,7 @@
 	filter_fir_t *filter;
 
 	// things to keep track of between callbacks
-	complex dc_remove;
+	complex double dc_remove;
 	gfloat agc_gain;
 	gfloat agc_speed;
 	// jack parameters
@@ -74,6 +74,9 @@
 
 sdr_data_t *sdr_new();
 int sdr_process(sdr_data_t *sdr);
+void sdr_destroy(sdr_data_t *sdr);
+void fft_setup(sdr_data_t *sdr);
+void fft_teardown(sdr_data_t *sdr);
 #endif
 
 /* vim: set noexpandtab ai ts=4 sw=4 tw=4: */
