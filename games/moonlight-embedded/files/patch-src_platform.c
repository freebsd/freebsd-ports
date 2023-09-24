--- src/platform.c.orig	2023-09-01 23:40:56 UTC
+++ src/platform.c
@@ -77,8 +77,8 @@ enum platform platform_check(char* name) {
   bool x11 = strcmp(name, "x11") == 0;
   bool vdpau = strcmp(name, "x11_vdpau") == 0;
   bool vaapi = strcmp(name, "x11_vaapi") == 0;
-  if (std || x11 || vdpau || vaapi) {
-    int init = x11_init(std || vdpau, std || vaapi);
+  if (x11 || vdpau || vaapi) {
+    int init = x11_init(vdpau, vaapi);
     #ifdef HAVE_VAAPI
     if (init == INIT_VAAPI)
       return X11_VAAPI;
@@ -87,11 +87,7 @@ enum platform platform_check(char* name) {
     if (init == INIT_VDPAU)
       return X11_VDPAU;
     #endif
-    #ifdef HAVE_SDL
-    return SDL;
-    #else
     return X11;
-    #endif
   }
   #endif
   #ifdef HAVE_SDL
@@ -195,13 +191,7 @@ AUDIO_RENDERER_CALLBACKS* platform_get_audio(enum plat
     // fall-through
   #endif
   default:
-    #ifdef HAVE_PULSE
-    if (audio_pulse_init(audio_device))
-      return &audio_callbacks_pulse;
-    #endif
-    #ifdef HAVE_ALSA
-    return &audio_callbacks_alsa;
-    #endif
+    return &audio_callbacks_oss;
   }
   return NULL;
 }
