--- src/audio.h.orig	2008-04-20 13:44:11.457927908 +0200
+++ src/audio.h	2008-04-20 13:45:31.343228414 +0200
@@ -53,6 +53,10 @@
 namespace ost {
 #endif
 
+#ifndef CCXX_CLASS_EXPORT
+#define CCXX_CLASS_EXPORT __EXPORT
+#endif
+
 #define	AUDIO_SIGNED_LINEAR_RAW	1
 #define	AUDIO_LINEAR_CONVERSION 1
 #define	AUDIO_CODEC_MODULES	1
