--- src/alignment_mutual_information.c.orig	2012-01-22 16:25:06 UTC
+++ src/alignment_mutual_information.c
@@ -28,6 +28,13 @@
 #include "amitk_data_set_DOUBLE_0D_SCALING.h"
 #include "alignment_mutual_information.h"
 
+#if __FreeBSD__ >= 2
+#include <osreldate.h>
+#if __FreeBSD_version <= 802502
+#define log2(x) 	(log(x) / M_LN2)
+#endif
+#endif
+
 /* this algorithm will calculate the amount of mutual information between two data sets in their current orientations    */
 /* it is a re-write of the original algorithm for purposes of improved speed. the hope is that it won't affect accuracy. */
 /* rather than computing mutual information for the whole volume of data, the algorithm computes it for three orthogonal */
@@ -209,7 +216,7 @@ gdouble calculate_mutual_information(Ami
       //g_print("\t\%i", mutual_information_array[i][j] );  // for point-wise counts
       // g_print("\t\%4.3f", incremental_mi );               // for point-wise probability
       
-      if isinf(incremental_mi) {
+      if(isinf(incremental_mi)) {
         //count it (because lots and lots of zeroes mean bad registration) and go to the next loop
         mi_nan_count++;
         // this is most often a problem when the incemental MI is infinity, due to divide by zero
