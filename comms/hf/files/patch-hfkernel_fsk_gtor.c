--- hfkernel/fsk/gtor.c.orig	2011-08-05 09:19:37.000000000 -0400
+++ hfkernel/fsk/gtor.c	2011-08-05 10:51:40.000000000 -0400
@@ -780,7 +780,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ void soft_deinterleave(const int *inp, unsigned short *out, 
+__inline__ void soft_deinterleave(const int *inp, unsigned short *out, 
 					 unsigned int ntrib, unsigned int spacing, int inv)
 {
 	unsigned int invm = inv ? 0 : ~0;
