--- components/feature_engagement/public/feature_list.h.orig	2021-04-14 01:08:45 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -147,7 +147,7 @@ DEFINE_VARIATION_PARAM(kIPHDiscoverFeedHeaderFeature,
                        "IPH_DiscoverFeedHeaderMenu");
 #endif  // defined(OS_IOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 DEFINE_VARIATION_PARAM(kIPHDesktopTabGroupsNewGroupFeature,
                        "IPH_DesktopTabGroupsNewGroup");
@@ -159,7 +159,7 @@ DEFINE_VARIATION_PARAM(kIPHPasswordsAccountStorageFeat
 DEFINE_VARIATION_PARAM(kIPHReopenTabFeature, "IPH_ReopenTab");
 DEFINE_VARIATION_PARAM(kIPHWebUITabStripFeature, "IPH_WebUITabStrip");
 DEFINE_VARIATION_PARAM(kIPHDesktopPwaInstallFeature, "IPH_DesktopPwaInstall");
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 }  // namespace
@@ -230,7 +230,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHBadgedReadingListFeature),
         VARIATION_ENTRY(kIPHBadgedTranslateManualTriggerFeature),
         VARIATION_ENTRY(kIPHDiscoverFeedHeaderFeature),
-#elif defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#elif defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
         VARIATION_ENTRY(kIPHDesktopTabGroupsNewGroupFeature),
         VARIATION_ENTRY(kIPHFocusModeFeature),
@@ -240,7 +240,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHReopenTabFeature),
         VARIATION_ENTRY(kIPHWebUITabStripFeature),
         VARIATION_ENTRY(kIPHDesktopPwaInstallFeature),
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 };
 
