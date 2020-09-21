--- daemons/dump_config.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/dump_config.c
@@ -120,11 +120,11 @@ void fprint_remote_head(FILE * f, struct ir_remote *re
 	if (!is_raw(rem)) {
 		if (rem->pre_data_bits > 0) {
 			fprintf(f, "  pre_data_bits   %d\n", rem->pre_data_bits);
-			fprintf(f, "  pre_data       0x%llX\n", rem->pre_data);
+			fprintf(f, "  pre_data       0x%llX\n", (unsigned long long)rem->pre_data);
 		}
 		if (rem->post_data_bits > 0) {
 			fprintf(f, "  post_data_bits  %d\n", rem->post_data_bits);
-			fprintf(f, "  post_data      0x%llX\n", rem->post_data);
+			fprintf(f, "  post_data      0x%llX\n", (unsigned long long)rem->post_data);
 		}
 		if (rem->pre_p != 0 && rem->pre_s != 0) {
 			fprintf(f, "  pre         %5u %5u\n", (__u32) rem->pre_p, (__u32) rem->pre_s);
@@ -151,15 +151,15 @@ void fprint_remote_head(FILE * f, struct ir_remote *re
 		if (rem->min_code_repeat > 0) {
 			fprintf(f, "  min_code_repeat %d\n", rem->min_code_repeat);
 		}
-		fprintf(f, "  toggle_bit_mask 0x%llX\n", rem->toggle_bit_mask);
+		fprintf(f, "  toggle_bit_mask 0x%llX\n", (unsigned long long)rem->toggle_bit_mask);
 		if (has_toggle_mask(rem)) {
-			fprintf(f, "  toggle_mask    0x%llX\n", rem->toggle_mask);
+			fprintf(f, "  toggle_mask    0x%llX\n", (unsigned long long)rem->toggle_mask);
 		}
 		if (rem->rc6_mask != 0) {
-			fprintf(f, "  rc6_mask    0x%llX\n", rem->rc6_mask);
+			fprintf(f, "  rc6_mask    0x%llX\n", (unsigned long long)rem->rc6_mask);
 		}
 		if (has_ignore_mask(rem)) {
-			fprintf(f, "  ignore_mask 0x%llX\n", rem->ignore_mask);
+			fprintf(f, "  ignore_mask 0x%llX\n", (unsigned long long)rem->ignore_mask);
 		}
 		if (is_serial(rem)) {
 			fprintf(f, "  baud            %d\n", rem->baud);
