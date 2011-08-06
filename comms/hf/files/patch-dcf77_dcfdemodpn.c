--- dcf77/dcfdemodpn.c.orig	2011-08-05 12:03:43.000000000 -0400
+++ dcf77/dcfdemodpn.c	2011-08-05 12:13:40.000000000 -0400
@@ -132,7 +132,7 @@
 #define PN_TRKTAU          (PN_SEQINC/3)
 #define PN_TRKADJ          (PN_SEQINC/8)
 	
-extern __inline__  void trk_sample(int sq, unsigned int samples)
+__inline__  void trk_sample(int sq, unsigned int samples)
 {
 	if (d.d.sec_ph > 0x3fffffff) {
 		trk_init();
@@ -201,7 +201,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__  void srch_sample(int sq)
+__inline__  void srch_sample(int sq)
 {
 	unsigned int u, k;
 	int asq = abs(sq);
