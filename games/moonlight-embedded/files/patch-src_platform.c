--- src/platform.c.orig	2021-12-20 00:24:48 UTC
+++ src/platform.c
@@ -188,14 +188,6 @@ AUDIO_RENDERER_CALLBACKS* platform_get_audio(enum plat
       return (PAUDIO_RENDERER_CALLBACKS) dlsym(RTLD_DEFAULT, "audio_callbacks_omx");
     // fall-through
   #endif
-  default:
-    #ifdef HAVE_PULSE
-    if (audio_pulse_init(audio_device))
-      return &audio_callbacks_pulse;
-    #endif
-    #ifdef HAVE_ALSA
-    return &audio_callbacks_alsa;
-    #endif
   }
   return NULL;
 }
