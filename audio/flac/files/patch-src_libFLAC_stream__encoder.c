
$FreeBSD$

--- src/libFLAC/stream_encoder.c.orig
+++ src/libFLAC/stream_encoder.c
@@ -3784,7 +3784,7 @@
 		/* slightly pessimistic but still catches all common cases */
 		/* WATCHOUT: "+ bps" is an assumption that the average residual magnitude will not be more than "bps" bits */
 		if(FLAC__bitmath_ilog2(default_partition_samples) + bps < 32) {
-			FLAC__uint32 abs_residual_partition_sum;
+			FLAC__uint64 abs_residual_partition_sum;
 
 			for(partition = residual_sample = 0; partition < partitions; partition++) {
 				end += default_partition_samples;
