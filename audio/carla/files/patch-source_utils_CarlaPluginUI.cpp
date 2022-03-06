- fix build on 12, see https://github.com/falkTX/Carla/issues/1597

--- source/utils/CarlaPluginUI.cpp.orig	2022-03-06 18:03:22 UTC
+++ source/utils/CarlaPluginUI.cpp
@@ -40,6 +40,8 @@
 # error CARLA_PLUGIN_UI_CLASS_PREFIX undefined
 #endif
 
+#include <pthread.h>
+
 // ---------------------------------------------------------------------------------------------------------------------
 // X11
 
