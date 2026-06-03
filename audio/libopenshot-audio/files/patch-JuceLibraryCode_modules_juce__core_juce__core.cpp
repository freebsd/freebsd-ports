--- JuceLibraryCode/modules/juce_core/juce_core.cpp.orig	2026-04-21 21:01:11 UTC
+++ JuceLibraryCode/modules/juce_core/juce_core.cpp
@@ -119,6 +119,11 @@
 
 #undef check
 
+/* workaround for <machine/atomic.h> defining dumb things on arm */
+#ifdef mb
+#undef mb
+#endif
+
 //==============================================================================
 #include "containers/juce_AbstractFifo.cpp"
 #include "containers/juce_ArrayBase.cpp"
