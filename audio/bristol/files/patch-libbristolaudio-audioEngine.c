--- libbristolaudio/audioEngine.c.orig	2012-04-27 13:04:29.000000000 +0200
+++ libbristolaudio/audioEngine.c	2012-09-24 15:41:49.609845763 +0200
@@ -59,8 +59,10 @@
 #include <fcntl.h>
 #ifdef SUBFRAGMENT
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
 #endif
+#endif
 
 #include <sys/ioctl.h>
 
