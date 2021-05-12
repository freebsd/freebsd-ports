--- components/feature_engagement/public/feature_list.cc.orig	2021-04-14 01:08:45 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -78,7 +78,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHBadgedTranslateManualTriggerFeature,
     &kIPHDiscoverFeedHeaderFeature,
 #endif  // defined(OS_IOS)
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     &kIPHDesktopTabGroupsNewGroupFeature,
     &kIPHFocusModeFeature,
@@ -88,7 +88,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHReopenTabFeature,
     &kIPHWebUITabStripFeature,
     &kIPHDesktopPwaInstallFeature,
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 };
 }  // namespace
