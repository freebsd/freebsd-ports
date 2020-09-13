--- JuceLibraryCode/modules/juce_core/native/juce_linux_SystemStats.cpp.orig	2020-09-11 12:10:25 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_linux_SystemStats.cpp
@@ -91,10 +91,13 @@ int SystemStats::getCpuSpeedInMegahertz()
 
 int SystemStats::getMemorySizeInMegabytes()
 {
+#if JUCE_BSD
+#else
     struct sysinfo sysi;
 
     if (sysinfo (&sysi) == 0)
         return (int) (sysi.totalram * sysi.mem_unit / (1024 * 1024));
+#endif
 
     return 0;
 }
@@ -139,8 +142,13 @@ static String getLocaleValue (nl_item key)
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
