--- ./src/audio_oss.c.orig	Sun Sep  8 03:18:56 2002
+++ ./src/audio_oss.c	Sun Sep  8 03:19:06 2002
@@ -33,9 +33,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
-#if defined(__FreeBSD__)
-#include <machine/soundcard.h>
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <soundcard.h>
 #else
 #include <sys/soundcard.h>
