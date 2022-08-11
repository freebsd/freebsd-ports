--- headless/lib/headless_macros.h.orig	2022-05-11 07:16:52 UTC
+++ headless/lib/headless_macros.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 #define HEADLESS_USE_BREAKPAD
 #endif  // defined(OS_POSIX) && !defined(OS_MAC)
 
