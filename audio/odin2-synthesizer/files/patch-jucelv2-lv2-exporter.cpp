-- Add BSD support to JUCELV2 LV2 wrapper exporter.

--- libs/JUCELV2/modules/juce_audio_plugin_client/LV2/juce_LV2_Wrapper_Exporter.cpp.orig	2026-05-17 03:55:19 UTC
+++ libs/JUCELV2/modules/juce_audio_plugin_client/LV2/juce_LV2_Wrapper_Exporter.cpp
@@ -13,7 +13,7 @@
 
 #if JUCE_MAC
  #define PLUGIN_EXT ".dylib"
-#elif JUCE_LINUX
+#elif JUCE_LINUX || JUCE_BSD
  #define PLUGIN_EXT ".so"
 #elif JUCE_WINDOWS
  #define PLUGIN_EXT ".dll"
@@ -126,7 +126,7 @@ static const String makeManifestFile (AudioProcessor* 
         text += "<" + pluginURI + "#ParentUI>\n";
  #if JUCE_MAC
         text += "    a ui:CocoaUI ;\n";
- #elif JUCE_LINUX
+ #elif JUCE_LINUX || JUCE_BSD
         text += "    a ui:X11UI ;\n";
  #elif JUCE_WINDOWS
         text += "    a ui:WindowsUI ;\n";
