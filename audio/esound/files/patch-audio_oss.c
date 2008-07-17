--- audio_oss.c.orig	2008-07-15 12:00:03.000000000 -0400
+++ audio_oss.c	2008-07-17 13:56:25.000000000 -0400
@@ -1,4 +1,5 @@
 #include "config.h"
+#include <errno.h>
 
 #ifdef HAVE_MACHINE_SOUNDCARD_H
 #  include <machine/soundcard.h>
@@ -10,9 +11,14 @@
 #  endif
 #endif
 
+#if defined(__sparc__) || defined(__powerpc__)
+#define AFMT_S16_NE AFMT_S16_BE
+#else
+#define AFMT_S16_NE AFMT_S16_LE
+#endif
 
 /* FreeBSD uses a different identifier? what other BSDs? */
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#ifndef SNDCTL_DSP_SETDUPLEX
 #define SNDCTL_DSP_SETDUPLEX DSP_CAP_DUPLEX
 #endif
 
