$FreeBSD$

--- src/s_inter.c.orig	Mon Jul 28 16:49:04 2003
+++ src/s_inter.c	Tue Nov 11 22:46:26 2003
@@ -893,8 +893,8 @@ void sys_bail(int n)
 #ifndef __linux  /* sys_close_audio() hangs if you're in a signal? */
 	fprintf(stderr, "closing audio...\n");
     	sys_close_audio();
-	fprintf(stderr, "closing MIDI...\n");
-	sys_close_midi();
+//	fprintf(stderr, "closing MIDI...\n");
+//	sys_close_midi();
 	fprintf(stderr, "... done.\n");
 #endif
 	exit(1);
