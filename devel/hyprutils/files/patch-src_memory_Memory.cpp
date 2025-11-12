--- src/memory/Memory.cpp.orig	2025-11-12 06:55:16 UTC
+++ src/memory/Memory.cpp
@@ -1,6 +1,7 @@
 #include <hyprutils/memory/WeakPtr.hpp>
 #include <hyprutils/memory/Atomic.hpp>
 #include <hyprutils/memory/Casts.hpp>
+#include <thread>
 
 using namespace Hyprutils::Memory;
 
@@ -176,4 +177,4 @@ TEST(Memory, memory) {
     testAtomicImpl();
 }
 
-#endif
\ No newline at end of file
+#endif
