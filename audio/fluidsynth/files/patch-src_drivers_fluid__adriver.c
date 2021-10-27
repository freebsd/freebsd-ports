--- src/drivers/fluid_adriver.c.orig	2021-09-11 16:26:35 UTC
+++ src/drivers/fluid_adriver.c
@@ -40,6 +40,16 @@ struct _fluid_audriver_definition_t
 /* Available audio drivers, listed in order of preference */
 static const fluid_audriver_definition_t fluid_audio_drivers[] =
 {
+#if SNDIO_SUPPORT
+    {
+       "sndio",
+       new_fluid_sndio_audio_driver,
+       new_fluid_sndio_audio_driver2,
+       delete_fluid_sndio_audio_driver,
+       fluid_sndio_audio_driver_settings
+    },
+#endif
+
 #if ALSA_SUPPORT
     {
         "alsa",
