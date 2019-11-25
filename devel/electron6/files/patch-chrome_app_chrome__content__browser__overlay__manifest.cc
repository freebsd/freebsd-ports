--- chrome/app/chrome_content_browser_overlay_manifest.cc.orig	2019-09-10 11:13:35 UTC
+++ chrome/app/chrome_content_browser_overlay_manifest.cc
@@ -79,7 +79,7 @@
 #include "chrome/services/app_service/public/cpp/manifest.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/performance_manager/webui_graph_dump.mojom.h"  // nogncheck
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
@@ -240,7 +240,7 @@ const service_manager::Manifest& GetChromeContentBrows
 #else
                 app_management::mojom::PageHandlerFactory,
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
                 mojom::DiscardsDetailsProvider,
                 performance_manager::mojom::WebUIGraphDump,
