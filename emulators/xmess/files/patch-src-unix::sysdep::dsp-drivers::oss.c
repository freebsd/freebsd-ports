--- ./src/unix/sysdep/dsp-drivers/oss.c.orig	Sun Sep  8 01:12:54 2002
+++ ./src/unix/sysdep/dsp-drivers/oss.c	Sun Sep  8 01:13:03 2002
@@ -29,9 +29,7 @@
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
