--- libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp.orig	2024-07-10 14:20:15 UTC
+++ libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp
@@ -44,6 +44,7 @@
 #include <cctype>
 #include <cstdio>
 #include <cstdarg>
+#include <cwctype>
 #include <utility>
 #include <complex>
 #include <cmath>
