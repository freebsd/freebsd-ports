--- SndUnix.c.orig	Sat Feb 28 10:19:49 2004
+++ SndUnix.c	Sat Feb 28 10:19:56 2004
@@ -75,7 +75,7 @@
 #else /* SUN_AUDIO */
 
 #ifdef __FreeBSD__
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
  
 #ifdef __NetBSD__
