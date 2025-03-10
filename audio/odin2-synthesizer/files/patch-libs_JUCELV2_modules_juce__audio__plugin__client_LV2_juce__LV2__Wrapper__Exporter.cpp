--- libs/JUCELV2/modules/juce_audio_plugin_client/LV2/juce_LV2_Wrapper_Exporter.cpp.orig	2025-02-22 08:52:21 UTC
+++ libs/JUCELV2/modules/juce_audio_plugin_client/LV2/juce_LV2_Wrapper_Exporter.cpp
@@ -15,6 +15,8 @@
  #define PLUGIN_EXT ".dylib"
 #elif JUCE_LINUX
  #define PLUGIN_EXT ".so"
+#elif JUCE_BSD
+ #define PLUGIN_EXT ".so"
 #elif JUCE_WINDOWS
  #define PLUGIN_EXT ".dll"
 #endif
@@ -127,6 +129,8 @@ static const String makeManifestFile (AudioProcessor* 
  #if JUCE_MAC
         text += "    a ui:CocoaUI ;\n";
  #elif JUCE_LINUX
+        text += "    a ui:X11UI ;\n";
+ #elif JUCE_BSD
         text += "    a ui:X11UI ;\n";
  #elif JUCE_WINDOWS
         text += "    a ui:WindowsUI ;\n";
