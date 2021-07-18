--- JuceLibraryCode/modules/juce_core/native/juce_linux_SystemStats.cpp.orig	2021-05-09 14:57:33 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_linux_SystemStats.cpp
@@ -139,8 +139,13 @@ static String getLocaleValue (nl_item key)
     return result;
 }
 
+#if JUCE_BSD
+String SystemStats::getUserLanguage()     { return String(); }
+String SystemStats::getUserRegion()       { return String(); }
+#else
 String SystemStats::getUserLanguage()     { return getLocaleValue (_NL_IDENTIFICATION_LANGUAGE); }
 String SystemStats::getUserRegion()       { return getLocaleValue (_NL_IDENTIFICATION_TERRITORY); }
+#endif
 String SystemStats::getDisplayLanguage()  { return getUserLanguage() + "-" + getUserRegion(); }
 
 //==============================================================================
