$FreeBSD$
--- ogg123/ogg123.c.orig	Mon Jun 18 18:16:50 2001
+++ ogg123/ogg123.c	Tue Jul 17 01:43:22 2001
@@ -24,6 +24,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <errno.h>
@@ -85,8 +86,10 @@ void usage(void)
 	    "  -V, --version  display Ogg123 version\n"
 	    "  -d, --device=d uses 'd' as an output device\n"
 	    "      Possible devices are (some may not be compiled):\n"
-	    "      null (output nothing), oss (for Linux and *BSD),\n"
-	    "      irix, solaris, wav (write to a .WAV file)\n"
+	    "      null (output nothing), oss (for Linux and FreeBSD),\n"
+	    "      alsa (for Linux), sun (for NetBSD, OpenBSD, Solaris),\n"
+	    "      irix, arts (aRts sound daemon), esd (ESounD daemon),\n"
+	    "      raw (write to a file), wav (write to a .WAV file)\n"
 	    "  -k n, --skip n  Skip the first 'n' seconds\n"
 	    "  -o, --device-option=k:v passes special option k with value\n"
 	    "      v to previously specified device (with -d).  See\n"
