--- audio_oss.c.orig	2008-07-29 14:07:50.000000000 -0400
+++ audio_oss.c	2008-09-07 22:22:15.000000000 -0400
@@ -12,8 +13,14 @@
 
 #include <errno.h>
 
+#if defined(__sparc__) || defined(__powerpc__)
+#define AFMT_S16_NE AFMT_S16_BE
+#else
+#define AFMT_S16_NE AFMT_S16_LE
+#endif
+
 /* FreeBSD uses a different identifier? what other BSDs? */
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#ifndef SNDCTL_DSP_SETDUPLEX
 #define SNDCTL_DSP_SETDUPLEX DSP_CAP_DUPLEX
 #endif
 
