--- libbristolaudio/audioEngine.c.orig	2012-04-27 11:04:29 UTC
+++ libbristolaudio/audioEngine.c
@@ -59,8 +59,10 @@ extern int alsaDevAudioStart(duplexDev *
 #include <fcntl.h>
 #ifdef SUBFRAGMENT
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
 #endif
+#endif
 
 #include <sys/ioctl.h>
 
