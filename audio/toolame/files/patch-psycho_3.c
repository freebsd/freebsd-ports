--- psycho_3.c.orig	Thu Mar 27 16:46:02 2003
+++ psycho_3.c	Thu Mar 27 16:51:53 2003
@@ -131,10 +131,10 @@
   int i;
   static int init = 0;
   static FLOAT *window;
+  register const FLOAT sqrt_8_over_3 = pow (8.0 / 3.0, 0.5);
 
   if (!init) { /* calculate window function for the Fourier transform */
     window = (FLOAT *) mem_alloc (sizeof (DFFT), "window");
-    register FLOAT sqrt_8_over_3 = pow (8.0 / 3.0, 0.5);
     for (i = 0; i < BLKSIZE; i++) {
       window[i] = sqrt_8_over_3 * 0.5 * (1 - cos (2.0 * PI * i / (BLKSIZE))) / BLKSIZE;
     }
@@ -340,6 +340,7 @@
   int i,j,k;
   FLOAT LTtm[SUBSIZE];
   FLOAT LTnm[SUBSIZE];
+  FLOAT av,dz,vf;
 
   for (i=0;i<SUBSIZE;i++) {
     LTtm[i] = DBMIN;
@@ -353,10 +354,9 @@
     if (tonelabel[k]==TONE) {
       for (j=0;j<SUBSIZE;j++) {
 	/* figure out how it masks the levels around it */  
-	FLOAT dz = bark[freq_subset[j]] - bark[k];     
+	dz = bark[freq_subset[j]] - bark[k];     
 	if (dz >= -3.0 && dz < 8.0) {
-	  FLOAT vf;
-	  FLOAT av = -1.525 - 0.275 * bark[k] - 4.5 + Xtm[k];
+	  av = -1.525 - 0.275 * bark[k] - 4.5 + Xtm[k];
 	  /* masking function for lower & upper slopes */
 	  if (dz < -1)
 	    vf = 17 * (dz + 1) - (0.4 * Xtm[k] + 6);
@@ -434,6 +434,7 @@
 void psycho_3_init(options *glopts) {
   int i;
   int cbase = 0; /* current base index for the bark range calculation */
+  register const FLOAT sfreq = (FLOAT) s_freq[header->version][header->sampling_frequency] * 1000;
 
   fft_buf = (D1408 *) mem_alloc ((long) sizeof (D1408) * 2, "fft_buf");
   
@@ -441,7 +442,6 @@
   psycho_3_init_add_db();
   
   /* For each spectral line calculate the bark and the ATH (in dB) */
-  FLOAT sfreq = (FLOAT) s_freq[header->version][header->sampling_frequency] * 1000;
   for (i=1;i<HBLKSIZE; i++) {
     FLOAT freq = i * sfreq/BLKSIZE;
     bark[i] = freq2bark(freq);
