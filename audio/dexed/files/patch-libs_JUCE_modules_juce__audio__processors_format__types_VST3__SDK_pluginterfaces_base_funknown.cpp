--- libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp.orig	2022-04-12 19:24:37 UTC
+++ libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp
@@ -56,7 +56,8 @@
 #endif
 
 #if defined (SMTG_USE_STDATOMIC_H) && SMTG_USE_STDATOMIC_H 
-#include <stdatomic.h>
+//#include <stdatomic.h>
+#include <atomic>
 #endif
 
 namespace Steinberg {
@@ -88,7 +89,7 @@ namespace FUnknownPrivate {
 int32 PLUGIN_API atomicAdd (int32& var, int32 d)
 {
 #if SMTG_USE_STDATOMIC_H
-	return atomic_fetch_add (reinterpret_cast<atomic_int_least32_t*> (&var), d) + d;
+	return atomic_fetch_add (reinterpret_cast<std::atomic_int_least32_t*> (&var), d) + d;
 #else
 #if SMTG_OS_WINDOWS
 #ifdef __MINGW32__
