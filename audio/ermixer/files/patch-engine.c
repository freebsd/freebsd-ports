--- ./src/engine.c.orig	Sat May 10 00:12:23 2003
+++ ./src/engine.c	Sat May 10 00:12:28 2003
@@ -6,11 +6,7 @@
 #include <errno.h>
 #include <sys/ioctl.h>
 
-#ifdef __FreeBSD__
-#include <machine/soundcard.h>
-#else
 #include <sys/soundcard.h>
-#endif
 
 #include <string.h>
 #include <unistd.h>
