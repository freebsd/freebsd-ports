--- chrome/browser/browser_features.cc.orig	2019-12-12 12:39:07 UTC
+++ chrome/browser/browser_features.cc
@@ -13,9 +13,9 @@ const base::Feature kDoubleTapToZoomInTabletMode{
     "DoubleTapToZoomInTabletMode", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const base::Feature kSyncClipboardServiceFeature{
     "SyncClipboardService", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // OS_WIN || OS_MACOSX || OS_LINUX
+#endif  // OS_WIN || OS_MACOSX || OS_LINUX || defined(OS_BSD)
 
 }  // namespace features
