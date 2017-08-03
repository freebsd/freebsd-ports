--- src/platform.c.orig	2017-07-02 11:38:48 UTC
+++ src/platform.c
@@ -163,14 +163,6 @@ AUDIO_RENDERER_CALLBACKS* platform_get_audio(enum plat
     if (audio_device == NULL || strcmp(audio_device, "local") == 0 || strcmp(audio_device, "hdmi") == 0)
       return (PAUDIO_RENDERER_CALLBACKS) dlsym(RTLD_DEFAULT, "audio_callbacks_omx");
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
