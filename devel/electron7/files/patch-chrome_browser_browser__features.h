--- chrome/browser/browser_features.h.orig	2019-12-12 12:39:07 UTC
+++ chrome/browser/browser_features.h
@@ -20,9 +20,9 @@ namespace features {
 extern const base::Feature kDoubleTapToZoomInTabletMode;
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 extern const base::Feature kSyncClipboardServiceFeature;
-#endif  // OS_WIN || OS_MACOSX || OS_LINUX
+#endif  // OS_WIN || OS_MACOSX || OS_LINUX || defined(OS_BSD)
 
 }  // namespace features
 
