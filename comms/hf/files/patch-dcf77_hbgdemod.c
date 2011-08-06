--- dcf77/hbgdemod.c.orig	2011-08-05 12:15:27.000000000 -0400
+++ dcf77/hbgdemod.c	2011-08-05 12:15:37.000000000 -0400
@@ -109,7 +109,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ void hbg_process_ampl(int si, unsigned int samples)
+__inline__ void hbg_process_ampl(int si, unsigned int samples)
 {
 	static int rodcnt = 0;
 	char* rod = "|/-\\ ";
