--- plugins/carlabase/carla.h.orig	2022-04-24 08:49:10 UTC
+++ plugins/carlabase/carla.h
@@ -34,10 +34,10 @@
     #include "CarlaBackend.h"
     #include "CarlaNative.h"
     #include "CarlaUtils.h"
-    CARLA_EXPORT
+    CARLA_PLUGIN_EXPORT
     const NativePluginDescriptor* carla_get_native_patchbay_plugin();
 
-    CARLA_EXPORT
+    CARLA_PLUGIN_EXPORT
     const NativePluginDescriptor* carla_get_native_rack_plugin();
 #endif
 
