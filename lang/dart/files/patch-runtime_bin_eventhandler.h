FreeBSD has no epoll: use the kqueue event handler that macOS uses
(series 0012). See patch-runtime_bin_eventhandler__macos.cc.
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/eventhandler.h.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/eventhandler.h
@@ -596,9 +596,11 @@ class DescriptorInfoMultipleMixin : public DI {
 // The event handler delegation class is OS specific.
 #if defined(DART_HOST_OS_FUCHSIA)
 #include "bin/eventhandler_fuchsia.h"
-#elif defined(DART_HOST_OS_LINUX) || defined(DART_HOST_OS_ANDROID)
+#elif (defined(DART_HOST_OS_LINUX) && !defined(__FreeBSD__)) ||               \
+    defined(DART_HOST_OS_ANDROID)
 #include "bin/eventhandler_linux.h"
-#elif defined(DART_HOST_OS_MACOS)
+#elif defined(DART_HOST_OS_MACOS) || defined(__FreeBSD__)
+// FreeBSD has no epoll; it shares the kqueue based implementation.
 #include "bin/eventhandler_macos.h"
 #elif defined(DART_HOST_OS_WINDOWS)
 #include "bin/eventhandler_win.h"
