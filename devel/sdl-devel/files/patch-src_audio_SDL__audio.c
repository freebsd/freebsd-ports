--- src/audio/SDL_audio.c	2001/01/03 11:25:01	1.1
+++ src/audio/SDL_audio.c	2001/01/03 11:25:24
@@ -41,7 +41,7 @@
 
 /* Available audio drivers */
 static AudioBootStrap *bootstrap[] = {
-#if defined(unix) && !defined(linux)
+#if defined(unix) && !defined(linux) && !defined(__FreeBSD__)
 	&AUDIO_bootstrap,
 #endif
 #ifdef OSS_SUPPORT
