--- dcf77/calccorr.c.orig	Sun Jul 30 15:17:56 2006
+++ dcf77/calccorr.c	Sun Jul 30 15:18:39 2006
@@ -197,7 +197,12 @@
 {
         static char head[256],  foot[256];
 	char factors[512];
+#ifdef __linux__
 	const char *configfilename =  "/etc/hf.conf";
+#endif
+#ifdef __FreeBSD__
+	const char *configfilename =  "/usr/local/etc/hf.conf";
+#endif
 	FILE *configfile = NULL;
 	static int prepared = 0;
 
