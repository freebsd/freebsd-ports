--- util/reffreq.c.orig	Wed Jan 26 10:03:20 2005
+++ util/reffreq.c	Sun Jul 30 14:45:10 2006
@@ -50,7 +50,10 @@
 #include <asm/page.h>
 #include <endian.h>
 #endif
-
+#ifdef __FreeBSD__
+#include <sys/soundcard.h>
+#include <sys/endian.h>
+#endif
 #if TIME_WITH_SYS_TIME
 # include <sys/time.h>
 # include <time.h>
@@ -108,7 +111,12 @@
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
 
