--- jack/pcm_jack.c.orig	2009-09-16 04:33:36.000000000 +0800
+++ jack/pcm_jack.c	2009-09-16 04:33:55.000000000 +0800
@@ -20,7 +20,9 @@
  *
  */
 
+#ifndef __FreeBSD__
 #include <byteswap.h>
+#endif
 #include <sys/shm.h>
 #include <sys/types.h>
 #include <sys/socket.h>
