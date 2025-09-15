--- audio/drivers/pipewire.c.orig	2025-05-01 00:17:50 UTC
+++ audio/drivers/pipewire.c
@@ -157,7 +157,7 @@ static const struct pw_registry_events registry_events
       .global = registry_event_global,
 };
 
-static void *pipewire_init(const char *device, unsigned rate,
+static void *_pipewire_init(const char *device, unsigned rate,
       unsigned latency,
       unsigned block_frames,
       unsigned *new_rate)
@@ -443,7 +443,7 @@ audio_driver_t audio_pipewire = {
 }
 
 audio_driver_t audio_pipewire = {
-      pipewire_init,
+      _pipewire_init,
       pipewire_write,
       pipewire_stop,
       pipewire_start,
