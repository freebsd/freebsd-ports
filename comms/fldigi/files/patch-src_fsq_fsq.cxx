--- src/fsq/fsq.cxx.orig	2015-08-15 03:43:43 UTC
+++ src/fsq/fsq.cxx
@@ -1198,8 +1198,9 @@ int fsq::rx_process(const double *buf, i
 						BLOCK_SIZE*sizeof(*rx_stream));	// # bytes
 				memset(fft_data, 0, sizeof(fft_data));
 				for (int i = 0; i < BLOCK_SIZE; i++)
-					fft_data[i].real() = fft_data[i].imag() =
-						rx_stream[i] * a_blackman[i];
+					fft_data[i] = complex <double>
+							(rx_stream[i] * a_blackman[i],
+							 rx_stream[i] * a_blackman[i]);
 				fft->ComplexFFT(fft_data);
 				process_tones();
 			}
