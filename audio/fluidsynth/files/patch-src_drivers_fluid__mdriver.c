$OpenBSD: patch-src_drivers_fluid_mdriver_c,v 1.1 2013/03/29 12:37:43 sthen Exp $
--- src/drivers/fluid_mdriver.c.orig	2012-08-16 04:01:13 UTC
+++ src/drivers/fluid_mdriver.c
@@ -46,6 +46,15 @@ fluid_midi_driver_t *new_fluid_jack_midi
 int delete_fluid_jack_midi_driver(fluid_midi_driver_t *p);
 #endif
 
+/* SNDIO */
+#if SNDIO_SUPPORT
+fluid_midi_driver_t* new_fluid_sndio_midi_driver(fluid_settings_t* settings,
+					     handle_midi_event_func_t handler,
+					     void* event_handler_data);
+int delete_fluid_sndio_midi_driver(fluid_midi_driver_t* p);
+void fluid_sndio_midi_driver_settings(fluid_settings_t* settings);
+#endif
+
 /* OSS */
 #if OSS_SUPPORT
 fluid_midi_driver_t* new_fluid_oss_midi_driver(fluid_settings_t* settings,
@@ -96,6 +105,12 @@ struct fluid_mdriver_definition_t {
 
 
 struct fluid_mdriver_definition_t fluid_midi_drivers[] = {
+#if SNDIO_SUPPORT
+  { "sndio",
+    new_fluid_sndio_midi_driver,
+    delete_fluid_sndio_midi_driver,
+    fluid_sndio_midi_driver_settings },
+#endif
 #if JACK_SUPPORT
   { "jack",
     new_fluid_jack_midi_driver,
@@ -149,7 +164,9 @@ void fluid_midi_driver_settings(fluid_se
                                FLUID_DEFAULT_MIDI_RT_PRIO, 0, 99, 0, NULL, NULL);
 
   /* Set the default driver */
-#if ALSA_SUPPORT
+#if SNDIO_SUPPORT
+  fluid_settings_register_str(settings, "midi.driver", "sndio", 0, NULL, NULL);
+#elif ALSA_SUPPORT
   fluid_settings_register_str(settings, "midi.driver", "alsa_seq", 0, NULL, NULL);
 #elif JACK_SUPPORT
   fluid_settings_register_str(settings, "midi.driver", "jack", 0, NULL, NULL);
@@ -170,6 +187,9 @@ void fluid_midi_driver_settings(fluid_se
   fluid_settings_add_option(settings, "midi.driver", "alsa_seq");
   fluid_settings_add_option(settings, "midi.driver", "alsa_raw");
 #endif
+#if SNDIO_SUPPORT
+  fluid_settings_add_option(settings, "midi.driver", "sndio");
+#endif
 #if JACK_SUPPORT
   fluid_settings_add_option(settings, "midi.driver", "jack");
 #endif
