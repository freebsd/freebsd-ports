--- libbristolaudio/audioGUIOSS.c.orig	2012-04-27 13:04:29.000000000 +0200
+++ libbristolaudio/audioGUIOSS.c	2012-09-24 15:42:10.570849586 +0200
@@ -50,7 +50,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 
 static int setAudioOSS(int, duplexDev *, int, int, int);
 
