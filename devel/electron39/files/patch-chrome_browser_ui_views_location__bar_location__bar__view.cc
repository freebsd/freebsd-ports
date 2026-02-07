--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2025-11-10 21:36:56 UTC
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -539,7 +539,7 @@ void LocationBarView::OnPopupOpened() {
 }
 
 void LocationBarView::OnPopupOpened() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // It's not great for promos to overlap the omnibox if the user opens the
   // drop-down after showing the promo. This especially causes issues on Mac and
   // Linux due to z-order/rendering issues, see crbug.com/1225046 and
