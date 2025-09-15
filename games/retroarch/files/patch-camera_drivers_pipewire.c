--- camera/drivers/pipewire.c.orig	2025-05-01 00:17:50 UTC
+++ camera/drivers/pipewire.c
@@ -364,7 +364,7 @@ static void pipewire_free(void *data)
    free(camera);
 }
 
-static void *pipewire_init(const char *device, uint64_t caps,
+static void *_pipewire_init(const char *device, uint64_t caps,
       unsigned width, unsigned height)
 {
    int               res, n_params;
@@ -457,7 +457,7 @@ camera_driver_t camera_pipewire = {
 }
 
 camera_driver_t camera_pipewire = {
-      pipewire_init,
+      _pipewire_init,
       pipewire_free,
       pipewire_start,
       pipewire_stop,
