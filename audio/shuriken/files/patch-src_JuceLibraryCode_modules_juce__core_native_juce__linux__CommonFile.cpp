--- src/JuceLibraryCode/modules/juce_core/native/juce_linux_CommonFile.cpp.orig	2023-02-22 02:02:45 UTC
+++ src/JuceLibraryCode/modules/juce_core/native/juce_linux_CommonFile.cpp
@@ -26,6 +26,8 @@
   ==============================================================================
 */
 
+#include <dirent.h>
+
 bool File::copyInternal (const File& dest) const
 {
     FileInputStream in (*this);
