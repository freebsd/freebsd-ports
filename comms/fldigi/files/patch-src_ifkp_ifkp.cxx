--- src/ifkp/ifkp.cxx.orig	2015-10-02 23:20:08 UTC
+++ src/ifkp/ifkp.cxx
@@ -580,9 +580,12 @@ int ifkp::rx_process(const double *buf, 
 						&rx_stream[IFKP_SHIFT_SIZE],			// from
 						IFKP_BLOCK_SIZE*sizeof(*rx_stream));	// # bytes
 				memset(fft_data, 0, sizeof(fft_data));
-				for (int i = 0; i < IFKP_BLOCK_SIZE; i++)
-					fft_data[i].real() = fft_data[i].imag() =
-						rx_stream[i] * a_blackman[i];
+				for (int i = 0; i < IFKP_BLOCK_SIZE; i++) {
+					fft_data[i].real(
+							 rx_stream[i] * a_blackman[i]);
+					fft_data[i].imag(
+							 rx_stream[i] * a_blackman[i]);
+				}
 				fft->ComplexFFT(fft_data);
 				process_tones();
 			}
