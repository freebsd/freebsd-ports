--- src/effects/vamp/LoadVamp.cpp.orig	2016-07-26 13:34:06 UTC
+++ src/effects/vamp/LoadVamp.cpp
@@ -266,7 +266,7 @@ Plugin *VampEffectsModule::FindPlugin(co
    Plugin *vp = PluginLoader::getInstance()->loadPlugin(key, 48000); // rate doesn't matter here
    if (!vp)
    {
-      return false;
+      return NULL;
    }
 
    // We limit the listed plugin outputs to those whose results can
