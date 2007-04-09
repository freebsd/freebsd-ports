--- convolution_init.c.orig	Mon Nov 28 00:24:57 2005
+++ convolution_init.c	Mon Apr  2 09:26:43 2007
@@ -17,8 +17,19 @@
 */
 
 #include "convolve.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <math.h>
+#include <errno.h>
+
+int my_posix_memalign(void **memptr, size_t alignment, size_t size)
+{
+	*memptr = malloc(size);
+
+	if (*memptr != NULL)
+		return 0;
+	else
+		return errno;
+}
 
 int convolution_init (convolution_t *conv,
                       int number_of_responses,
@@ -47,12 +58,12 @@
 	// allocate FFT buffers
 	// as r2c stores only N/2+1 results, we don't need the padded size for this
 	// conv->fft_complex = (fftwf_complex*)malloc (sizeof(fftwf_complex) * (conv->chunk_length + 1));
-	posix_memalign(&conv->fft_complex, 16, sizeof(fftwf_complex) * (conv->chunk_length + 1));
+	my_posix_memalign(&conv->fft_complex, 16, sizeof(fftwf_complex) * (conv->chunk_length + 1));
 
 
 	// this one still needs to be 2 * chunk_length as we zero pad it
 	// conv->fft_real   = (float*)malloc (sizeof(float) * 2 * conv->chunk_length);
-	posix_memalign(&conv->fft_real, 16, sizeof(float) * 2 * conv->chunk_length);
+	my_posix_memalign(&conv->fft_real, 16, sizeof(float) * 2 * conv->chunk_length);
 
 	// create fftw plans
 	conv->fft_plan_forward = fftwf_plan_dft_r2c_1d (2 * conv->chunk_length, 
@@ -100,7 +111,7 @@
                                          * (conv->chunk_length + 1)
                                          * conv->fft_responses[index]->number_of_chunks);
 			*/
-			posix_memalign(&conv->fft_responses[index]->channel_data[index2],
+			my_posix_memalign(&conv->fft_responses[index]->channel_data[index2],
 			               16,
 			               sizeof(fftwf_complex) 
 			               * (conv->chunk_length + 1)
@@ -169,7 +180,7 @@
 
 			// need to divide (integer divide) the index by number_of_responses to get
 			// a valid index into the list of responses.
-			posix_memalign(&conv->input_chunk_ringbuffers[index], 16,
+			my_posix_memalign(&conv->input_chunk_ringbuffers[index], 16,
 			               sizeof(fftwf_complex) * conv->fft_responses[index/conv->number_of_response_channels]->number_of_chunks
 			               * (conv->chunk_length + 1));
 
@@ -189,7 +200,7 @@
 			    = (fftwf_complex*)malloc (sizeof(fftwf_complex) * conv->fft_responses[index]->number_of_chunks
 			                              * (conv->chunk_length + 1));
 			*/
-			posix_memalign(&conv->input_chunk_ringbuffers[index], 16,
+			my_posix_memalign(&conv->input_chunk_ringbuffers[index], 16,
 			               sizeof(fftwf_complex) * conv->fft_responses[index]->number_of_chunks
 			               * (conv->chunk_length + 1));
 
@@ -222,7 +233,7 @@
 	for (index = 0; index < conv->number_of_response_channels; ++index) { 
 	
 		// conv->overlap_buffers[index] = (float*)malloc (sizeof(float) * conv->chunk_length);
-		posix_memalign(&conv->overlap_buffers[index], 16, sizeof(float) * conv->chunk_length);
+		my_posix_memalign(&conv->overlap_buffers[index], 16, sizeof(float) * conv->chunk_length);
 
 		// zero out
 		for (index2 = 0; index2 < conv->chunk_length; ++index2) {
