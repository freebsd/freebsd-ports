--- libbristolaudio/audioGUIOSS.c.orig	2012-04-27 11:04:29 UTC
+++ libbristolaudio/audioGUIOSS.c
@@ -50,7 +50,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 
 static int setAudioOSS(int, duplexDev *, int, int, int);
 
