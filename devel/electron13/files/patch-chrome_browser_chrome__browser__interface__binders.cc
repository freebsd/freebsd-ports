--- chrome/browser/chrome_browser_interface_binders.cc.orig	2021-07-15 19:13:32 UTC
+++ chrome/browser/chrome_browser_interface_binders.cc
@@ -148,7 +148,7 @@
 #include "mojo/public/cpp/bindings/self_owned_receiver.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
@@ -612,7 +612,7 @@ void PopulateChromeFrameBinders(
       base::BindRepeating(&BindCaptionContextHandler));
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(features::kWebAppWindowControlsOverlay) &&
       !render_frame_host->GetParent()) {
     map->Add<chrome::mojom::DraggableRegions>(
@@ -846,7 +846,7 @@ void PopulateChromeWebUIFrameBinders(
   }
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   RegisterWebUIControllerInterfaceBinder<discards::mojom::DetailsProvider,
                                          DiscardsUI>(map);
