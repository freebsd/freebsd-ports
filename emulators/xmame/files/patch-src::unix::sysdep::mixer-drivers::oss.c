--- src/unix/sysdep/mixer-drivers/oss.c.orig	Fri May  3 02:53:54 2002
+++ src/unix/sysdep/mixer-drivers/oss.c	Thu Oct 31 12:46:55 2002
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
