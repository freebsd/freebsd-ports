--- src/tl/tl/tlTimer.cc.orig	2026-07-10 21:21:50 UTC
+++ src/tl/tl/tlTimer.cc
@@ -274,7 +274,7 @@ Timer::memory_size ()
   return size_t (memsize) * size_t (getpagesize ());
 
 #else
-#  error Unsupported platform
+  return 0;
 #endif
 }
 
