--- content/public/browser/font_access_context.h.orig	2022-05-11 07:16:51 UTC
+++ content/public/browser/font_access_context.h
@@ -11,7 +11,7 @@
 #include "third_party/blink/public/mojom/font_access/font_access.mojom.h"
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC) || defined(OS_FUCHSIA)
+    defined(OS_MAC) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #define PLATFORM_HAS_LOCAL_FONT_ENUMERATION_IMPL 1
 #endif
 
