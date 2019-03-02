--- src/drivers/fluid_adriver.c.orig	2018-12-30 11:42:00 UTC
+++ src/drivers/fluid_adriver.c
@@ -39,6 +39,16 @@ struct _fluid_audriver_definition_t
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
 #if JACK_SUPPORT
     {
         "jack",
