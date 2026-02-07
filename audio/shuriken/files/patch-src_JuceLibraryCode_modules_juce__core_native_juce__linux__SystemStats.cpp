--- src/JuceLibraryCode/modules/juce_core/native/juce_linux_SystemStats.cpp.orig	2023-02-22 04:43:54 UTC
+++ src/JuceLibraryCode/modules/juce_core/native/juce_linux_SystemStats.cpp
@@ -142,8 +142,8 @@ static String getLocaleValue (nl_item key)
     return result;
 }
 
-String SystemStats::getUserLanguage()    { return getLocaleValue (_NL_IDENTIFICATION_LANGUAGE); }
-String SystemStats::getUserRegion()      { return getLocaleValue (_NL_IDENTIFICATION_TERRITORY); }
+String SystemStats::getUserLanguage()    { return String(); }
+String SystemStats::getUserRegion()      { return String(); }
 String SystemStats::getDisplayLanguage() { return getUserLanguage() + "-" + getUserRegion(); }
 
 //==============================================================================
