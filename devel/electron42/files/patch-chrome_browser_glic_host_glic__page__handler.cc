--- chrome/browser/glic/host/glic_page_handler.cc.orig	2026-05-18 23:17:45 UTC
+++ chrome/browser/glic/host/glic_page_handler.cc
@@ -195,7 +195,7 @@ constexpr mojom::Platform kPlatform = mojom::Platform:
 constexpr mojom::Platform kPlatform = mojom::Platform::kMacOS;
 #elif BUILDFLAG(IS_WIN)
 constexpr mojom::Platform kPlatform = mojom::Platform::kWindows;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr mojom::Platform kPlatform = mojom::Platform::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
 constexpr mojom::Platform kPlatform = mojom::Platform::kChromeOS;
