--- modules/juce_core/native/juce_SystemStats_linux.cpp.orig	2026-07-21 10:18:06 UTC
+++ modules/juce_core/native/juce_SystemStats_linux.cpp
@@ -32,6 +32,10 @@
   ==============================================================================
 */
 
+#if JUCE_BSD
+#include <sys/user.h>
+#endif
+
 namespace juce
 {
 
