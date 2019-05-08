--- JuceLibraryCode/modules/juce_core/maths/juce_MathsFunctions.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/maths/juce_MathsFunctions.h
@@ -76,10 +76,11 @@ using uint32    = unsigned int;
   /** An unsigned integer type that's guaranteed to be large enough to hold a pointer without truncating it. */
   using pointer_sized_uint = _W64 unsigned int;
 #else
+# include <cstdint>
   /** A signed integer type that's guaranteed to be large enough to hold a pointer without truncating it. */
-  using pointer_sized_int  = int;
+  using pointer_sized_int  = intptr_t;
   /** An unsigned integer type that's guaranteed to be large enough to hold a pointer without truncating it. */
-  using pointer_sized_uint = unsigned int;
+  using pointer_sized_uint = uintptr_t;
 #endif
 
 #if JUCE_WINDOWS && ! JUCE_MINGW
