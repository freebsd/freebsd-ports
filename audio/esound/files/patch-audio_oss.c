
$FreeBSD$

--- audio_oss.c	2001/10/09 14:15:03	1.1
+++ audio_oss.c	2001/10/09 14:15:40
@@ -12,7 +12,7 @@
 
 
 /* FreeBSD uses a different identifier? what other BSDs? */
-#ifdef __FreeBSD__
+#ifndef SNDCTL_DSP_SETDUPLEX
 #define SNDCTL_DSP_SETDUPLEX DSP_CAP_DUPLEX
 #endif
 
