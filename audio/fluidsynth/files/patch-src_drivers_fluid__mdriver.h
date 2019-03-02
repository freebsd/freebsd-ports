--- src/drivers/fluid_mdriver.h.orig	2019-02-03 07:13:59 UTC
+++ src/drivers/fluid_mdriver.h
@@ -53,6 +53,15 @@ void delete_fluid_alsa_seq_driver(fluid_midi_driver_t 
 void fluid_alsa_seq_driver_settings(fluid_settings_t *settings);
 #endif
 
+/* SNDIO */
+#if SNDIO_SUPPORT
+void fluid_sndio_midi_driver_settings(fluid_settings_t *settings);
+fluid_midi_driver_t *new_fluid_sndio_midi_driver(fluid_settings_t *settings,
+        handle_midi_event_func_t handler,
+        void *data);
+void delete_fluid_sndio_midi_driver(fluid_midi_driver_t *p);
+#endif
+
 /* JACK */
 #if JACK_SUPPORT
 void fluid_jack_midi_driver_settings(fluid_settings_t *settings);
