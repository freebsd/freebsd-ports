--- src/platform.c.orig	2023-11-03 06:08:34 UTC
+++ src/platform.c
@@ -202,6 +202,9 @@ AUDIO_RENDERER_CALLBACKS* platform_get_audio(enum plat
     #ifdef HAVE_ALSA
     return &audio_callbacks_alsa;
     #endif
+    #ifdef __FreeBSD__
+    return &audio_callbacks_oss;
+    #endif
   }
   return NULL;
 }
