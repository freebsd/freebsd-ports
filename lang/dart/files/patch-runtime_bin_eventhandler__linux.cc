FreeBSD has no epoll: don't build the epoll event handler there; it
uses the kqueue one from eventhandler_macos.cc (series 0012).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/eventhandler_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/eventhandler_linux.cc
@@ -3,7 +3,8 @@
 // BSD-style license that can be found in the LICENSE file.
 
 #include "platform/globals.h"
-#if defined(DART_HOST_OS_LINUX) || defined(DART_HOST_OS_ANDROID)
+#if (defined(DART_HOST_OS_LINUX) && !defined(__FreeBSD__)) ||               \
+    defined(DART_HOST_OS_ANDROID)
 
 #include "bin/eventhandler.h"
 #include "bin/eventhandler_linux.h"
@@ -430,4 +431,5 @@ uint32_t EventHandlerImplementation::GetHashmapHashFro
 }  // namespace bin
 }  // namespace dart
 
-#endif  // defined(DART_HOST_OS_LINUX) || defined(DART_HOST_OS_ANDROID)
+#endif  // (defined(DART_HOST_OS_LINUX) && !defined(__FreeBSD__)) ||
+        // defined(DART_HOST_OS_ANDROID)
