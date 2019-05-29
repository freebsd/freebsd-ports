--- JuceLibraryCode/modules/juce_core/text/juce_CharPointer_ASCII.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/text/juce_CharPointer_ASCII.h
@@ -335,7 +335,7 @@ class CharPointer_ASCII  final (public)
     /** Parses this string as a 64-bit integer. */
     int64 getIntValue64() const noexcept
     {
-       #if JUCE_LINUX || JUCE_ANDROID || JUCE_MINGW
+       #if JUCE_BSD || JUCE_LINUX || JUCE_ANDROID || JUCE_MINGW
         return atoll (data);
        #elif JUCE_WINDOWS
         return _atoi64 (data);
