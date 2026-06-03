--- chrome/browser/ui/views/frame/custom_corners_background.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/ui/views/frame/custom_corners_background.cc
@@ -117,7 +117,7 @@ CustomCornersBackground::Corner CustomCornersBackgroun
   } else {
     corner.type = CornerType::kSquare;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* const widget = browser_view().browser_widget()) {
     if (auto* const frame = widget->GetFrameView()) {
       const auto rrect = frame->GetRestoredClipRegion();
