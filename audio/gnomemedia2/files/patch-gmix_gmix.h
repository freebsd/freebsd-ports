--- gmix/gmix.h.orig	Sat Aug 16 15:13:57 2003
+++ gmix/gmix.h	Sat Aug 16 15:14:47 2003
@@ -25,7 +25,7 @@
  */
 #define GMIX_VERSION 0x030000
 
-#if defined(ALSA) || defined(__FreeBSD__)
+#if defined(ALSA) || (defined(__FreeBSD__) && !defined(SOUND_MIXER_INFO))
 /* stolen from OSS's soundcard.h */
 typedef struct mixer_info
 {
