--- sdr.c.orig	2011-11-26 16:01:22.000000000 -0800
+++ sdr.c	2014-06-02 03:45:08.000000000 -0700
@@ -26,6 +26,8 @@
 #include <fftw3.h>
 #include <string.h>
 
+double complex cexp(double complex z);
+
 #include "filter.h"
 #include "sdr.h"
 
@@ -56,7 +58,7 @@
 	// actually do the SDR bit
 	int i, j, k;
 	double y, accI, accQ;
-	complex c;
+	complex double c;
 	fft_data_t *fft = sdr->fft;
 	int size = sdr->size;
 	int block_size = MIN(size, FFT_SIZE);   // ensure we don't try to copy a block larger than FFT_SIZE
@@ -73,8 +75,8 @@
 
 	// copy this period to FFT buffer, or as much as will fit
 	// note that if the jack periodsize is greater than FFT_LEN, it will only copy FFT_LEN samples
-	memmove(fft->samples, fft->samples+block_size, sizeof(complex)*(FFT_SIZE-block_size)); // move the last lot up
-	memmove(fft->samples+FFT_SIZE-block_size, sdr->iqSample, sizeof(complex)*block_size);  // copy the current block
+	memmove(fft->samples, fft->samples+block_size, sizeof(complex double)*(FFT_SIZE-block_size)); // move the last lot up
+	memmove(fft->samples+FFT_SIZE-block_size, sdr->iqSample, sizeof(complex double)*block_size);  // copy the current block
 
 
 	// shift frequency
@@ -123,6 +125,7 @@
 			}
 			break;
 	}  
+	return 0;
 }
 
 void fft_setup(sdr_data_t *sdr) {
