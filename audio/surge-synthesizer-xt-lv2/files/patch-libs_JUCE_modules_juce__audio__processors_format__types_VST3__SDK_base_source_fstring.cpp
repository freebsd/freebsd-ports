--- libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp.orig	2022-03-20 14:18:51 UTC
+++ libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp
@@ -44,6 +44,7 @@
 #include <cctype>
 #include <cstdio>
 #include <cstdarg>
+#include <cwctype>
 #include <utility>
 
 #if SMTG_OS_WINDOWS
