--- audio_oss.c.orig	Tue Jun  4 08:55:37 2002
+++ audio_oss.c	Sun Jun  9 01:55:21 2002
@@ -10,9 +10,14 @@
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
 
