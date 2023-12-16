--- modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp.orig	2023-03-05 05:39:00 UTC
+++ modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp
@@ -44,7 +44,7 @@
 #endif // !SMTG_USE_STDATOMIC_H
 #endif // SMTG_OS_MACOS
 
-#if SMTG_OS_LINUX
+#if SMTG_OS_LINUX && !JUCE_BSD
 #if !defined (SMTG_USE_STDATOMIC_H)
 #if defined (__ANDROID__) || defined(_LIBCPP_VERSION)
 #define SMTG_USE_STDATOMIC_H 1
@@ -100,7 +100,7 @@ int32 PLUGIN_API atomicAdd (int32& var, int32 d)
 	return OSAtomicAdd32Barrier (d, (int32_t*)&var);
 #elif defined(__ANDROID__)
 	return atomic_fetch_add ((atomic_int*)&var, d) + d;
-#elif SMTG_OS_LINUX
+#elif SMTG_OS_LINUX && !JUCE_BSD
 	__gnu_cxx::__atomic_add (&var, d);
 	return var;
 #else
@@ -177,7 +177,7 @@ bool FUID::generate ()
 	}
 	return false;
 
-#elif SMTG_OS_LINUX
+#elif SMTG_OS_LINUX && !JUCE_BSD
 	srand ((size_t)this);
 	for (int32 i = 0; i < 16; i++)
 		data[i] = static_cast<unsigned char>(rand ());
