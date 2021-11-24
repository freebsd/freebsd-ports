--- components/feature_engagement/public/feature_constants.h.orig	2021-07-15 19:13:37 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -16,7 +16,7 @@ extern const base::Feature kIPHDemoMode;
 // A feature to ensure all arrays can contain at least one feature.
 extern const base::Feature kIPHDummyFeature;
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 extern const base::Feature kIPHDesktopTabGroupsNewGroupFeature;
 extern const base::Feature kIPHFocusModeFeature;
@@ -30,7 +30,7 @@ extern const base::Feature kIPHWebUITabStripFeature;
 extern const base::Feature kIPHDesktopSnoozeFeature;
 extern const base::Feature kIPHDesktopPwaInstallFeature;
 extern const base::Feature kIPHProfileSwitchFeature;
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 // All the features declared for Android below that are also used in Java,
