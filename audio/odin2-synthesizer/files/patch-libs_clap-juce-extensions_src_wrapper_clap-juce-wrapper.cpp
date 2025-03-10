--- libs/clap-juce-extensions/src/wrapper/clap-juce-wrapper.cpp.orig	2025-02-22 09:13:25 UTC
+++ libs/clap-juce-extensions/src/wrapper/clap-juce-wrapper.cpp
@@ -35,7 +35,7 @@ JUCE_END_IGNORE_WARNINGS_GCC_LIKE
 
 #include <clap-juce-extensions/clap-juce-extensions.h>
 
-#if JUCE_LINUX
+#if JUCE_LINUX || JUCE_BSD
 #include <juce_audio_plugin_client/utility/juce_LinuxMessageThread.h>
 #endif
 
