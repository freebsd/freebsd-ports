--- src/libFLAC/fixed.c.orig	Sun Apr  1 07:35:25 2001
+++ src/libFLAC/fixed.c	Sun May 20 13:37:20 2001
@@ -81,11 +81,11 @@ unsigned FLAC__fixed_compute_best_predic
 	residual_bits_per_sample[3] = (real)((data_len > 0) ? log(M_LN2 * (real)(int64)total_error_3  / (real) data_len) / M_LN2 : 0.0);
 	residual_bits_per_sample[4] = (real)((data_len > 0) ? log(M_LN2 * (real)(int64)total_error_4  / (real) data_len) / M_LN2 : 0.0);
 #else
-	residual_bits_per_sample[0] = (real)((data_len > 0) ? log(M_LN2 * (real)total_error_0  / (real) data_len) / M_LN2 : 0.0);
-	residual_bits_per_sample[1] = (real)((data_len > 0) ? log(M_LN2 * (real)total_error_1  / (real) data_len) / M_LN2 : 0.0);
-	residual_bits_per_sample[2] = (real)((data_len > 0) ? log(M_LN2 * (real)total_error_2  / (real) data_len) / M_LN2 : 0.0);
-	residual_bits_per_sample[3] = (real)((data_len > 0) ? log(M_LN2 * (real)total_error_3  / (real) data_len) / M_LN2 : 0.0);
-	residual_bits_per_sample[4] = (real)((data_len > 0) ? log(M_LN2 * (real)total_error_4  / (real) data_len) / M_LN2 : 0.0);
+	residual_bits_per_sample[0] = (real)((data_len > 0 && total_error_0 > 0) ? log(M_LN2 * (real)total_error_0  / (real) data_len) / M_LN2 : 0.0);
+	residual_bits_per_sample[1] = (real)((data_len > 0 && total_error_1 > 0) ? log(M_LN2 * (real)total_error_1  / (real) data_len) / M_LN2 : 0.0);
+	residual_bits_per_sample[2] = (real)((data_len > 0 && total_error_2 > 0) ? log(M_LN2 * (real)total_error_2  / (real) data_len) / M_LN2 : 0.0);
+	residual_bits_per_sample[3] = (real)((data_len > 0 && total_error_3 > 0) ? log(M_LN2 * (real)total_error_3  / (real) data_len) / M_LN2 : 0.0);
+	residual_bits_per_sample[4] = (real)((data_len > 0 && total_error_4 > 0) ? log(M_LN2 * (real)total_error_4  / (real) data_len) / M_LN2 : 0.0);
 #endif
 
 	return order;
@@ -152,7 +152,7 @@ unsigned FLAC__fixed_compute_best_predic
 
 void FLAC__fixed_compute_residual(const int32 data[], unsigned data_len, unsigned order, int32 residual[])
 {
-	unsigned i;
+	int i;
 
 	switch(order) {
 		case 0:
@@ -190,7 +190,7 @@ void FLAC__fixed_compute_residual(const 
 
 void FLAC__fixed_restore_signal(const int32 residual[], unsigned data_len, unsigned order, int32 data[])
 {
-	unsigned i;
+	int i;
 
 	switch(order) {
 		case 0:
