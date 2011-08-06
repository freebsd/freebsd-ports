--- dcf77/dcfdemod.c.orig	2011-08-05 11:39:38.000000000 -0400
+++ dcf77/dcfdemod.c	2011-08-05 12:02:16.000000000 -0400
@@ -91,7 +91,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ void decode_ampl_bit(unsigned int bit, unsigned int samples)
+__inline__ void decode_ampl_bit(unsigned int bit, unsigned int samples)
 {
 	if (bit == 0) {
 		if (d.t.dcnt >= 59)
@@ -109,7 +109,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ void dcf77_process_ampl(int si, unsigned int samples)
+__inline__ void dcf77_process_ampl(int si, unsigned int samples)
 {
 	static int rodcnt = 0;
 	char* rod = "|/-\\ ";
