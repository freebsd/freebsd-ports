$FreeBSD$

--- src/common.h.orig	Thu Jun  6 19:50:10 2002
+++ src/common.h	Thu Jun  6 19:51:01 2002
@@ -24,18 +24,14 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-/* "The nice thing about standards..." */
-#if defined (__FreeBSD__)
-#include <machine/soundcard.h>
-#else
+/* "The nice thing about standards..." */
 #if defined (__NetBSD__) || defined (__OpenBSD__)
 #include <soundcard.h>		/* OSS emulation */
 #undef ioctl
 #else
-/* BSDI, Linux, Solaris */
+/* FreeBSD, BSDI, Linux, Solaris */
 #include <sys/soundcard.h>
 #endif				/* __NetBSD__ or __OpenBSD__ */
-#endif				/* __FreeBSD__ */
 #ifdef HAVE_ALSA
 #include <sys/asoundlib.h>
 #endif				/* HAVE_ALSA */
