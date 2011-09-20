--- src/alignment_mutual_information.c.orig	2011-07-15 07:08:17.000000000 +0200
+++ src/alignment_mutual_information.c	2011-09-19 14:55:39.733328817 +0200
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
