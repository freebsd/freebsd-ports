--- JuceLibraryCode/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp
@@ -90,7 +90,7 @@ File PropertiesFile::Options::getDefaultFile() const
     if (folderName.isNotEmpty())
         dir = dir.getChildFile (folderName);
 
-   #elif JUCE_LINUX || JUCE_ANDROID
+   #elif JUCE_BSD || JUCE_LINUX || JUCE_ANDROID
     auto dir = File (commonToAllUsers ? "/var" : "~")
                       .getChildFile (folderName.isNotEmpty() ? folderName
                                                              : ("." + applicationName));
