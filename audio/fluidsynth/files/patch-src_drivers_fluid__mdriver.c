$OpenBSD: patch-src_drivers_fluid_mdriver_c,v 1.1 2013/03/29 12:37:43 sthen Exp $
--- src/drivers/fluid_mdriver.c.orig	2018-12-30 11:42:00 UTC
+++ src/drivers/fluid_mdriver.c
@@ -52,6 +52,14 @@ static const fluid_mdriver_definition_t fluid_midi_dri
         fluid_alsa_rawmidi_driver_settings
     },
 #endif
+#if SNDIO_SUPPORT
+    {
+        "sndio",
+        new_fluid_sndio_midi_driver,
+        delete_fluid_sndio_midi_driver,
+        fluid_sndio_midi_driver_settings
+    },
+#endif
 #if JACK_SUPPORT
     {
         "jack",
