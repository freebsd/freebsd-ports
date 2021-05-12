--- content/public/browser/font_access_context.h.orig	2021-04-14 01:08:48 UTC
+++ content/public/browser/font_access_context.h
@@ -10,7 +10,7 @@
 #include "content/common/content_export.h"
 #include "third_party/blink/public/mojom/font_access/font_access.mojom.h"
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
 #define PLATFORM_HAS_LOCAL_FONT_ENUMERATION_IMPL 1
 #endif
