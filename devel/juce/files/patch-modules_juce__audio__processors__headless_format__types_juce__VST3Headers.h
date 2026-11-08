--- modules/juce_audio_processors_headless/format_types/juce_VST3Headers.h.orig	2026-07-21 10:18:06 UTC
+++ modules/juce_audio_processors_headless/format_types/juce_VST3Headers.h
@@ -35,7 +35,7 @@
 #pragma once
 
 #if JUCE_BSD && ! JUCE_CUSTOM_VST3_SDK
- #error To build JUCE VST3 plug-ins or hosts on BSD you must use an external BSD-compatible VST3 SDK with JUCE_CUSTOM_VST3_SDK=1
+ // The bundled VST3 SDK is patched for FreeBSD in this port.
 #endif
 
 // It's important to include this *before* any of the Steinberg headers.
