--- src/drivers/fluid_adriver.h.orig	2019-02-03 07:07:02 UTC
+++ src/drivers/fluid_adriver.h
@@ -90,6 +90,14 @@ fluid_audio_driver_t *new_fluid_portaudio_driver(fluid
 void delete_fluid_portaudio_driver(fluid_audio_driver_t *p);
 #endif
 
+#if SNDIO_SUPPORT
+fluid_audio_driver_t *new_fluid_sndio_audio_driver(fluid_settings_t *settings, fluid_synth_t *synth);
+fluid_audio_driver_t *new_fluid_sndio_audio_driver2(fluid_settings_t *settings,
+        fluid_audio_func_t func, void *data);
+void delete_fluid_sndio_audio_driver(fluid_audio_driver_t *p);
+void fluid_sndio_audio_driver_settings(fluid_settings_t *settings);
+#endif
+
 #if JACK_SUPPORT
 fluid_audio_driver_t *new_fluid_jack_audio_driver(fluid_settings_t *settings, fluid_synth_t *synth);
 fluid_audio_driver_t *new_fluid_jack_audio_driver2(fluid_settings_t *settings,
