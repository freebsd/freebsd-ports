--- ./src/unix/sysdep/mixer-drivers/oss.c.orig	Sun Sep  8 01:13:30 2002
+++ ./src/unix/sysdep/mixer-drivers/oss.c	Sun Sep  8 01:13:35 2002
@@ -28,9 +28,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
-#ifdef __ARCH_freebsd
-#include <machine/soundcard.h>
-#elif defined (__ARCH_openbsd)
+#if defined (__ARCH_openbsd)
 #include <soundcard.h>
 #else
 #include <sys/soundcard.h>
