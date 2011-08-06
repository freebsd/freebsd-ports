--- hfkernel/fsk/fskl1.c.orig	2011-08-05 10:57:44.000000000 -0400
+++ hfkernel/fsk/fskl1.c	2011-08-05 10:58:19.000000000 -0400
@@ -376,7 +376,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ unsigned int output_one_sample(l1_time_t tm)
+__inline__ unsigned int output_one_sample(l1_time_t tm)
 {
 	int i, j, k;
 
