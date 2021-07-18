--- components/previews/core/previews_features.cc.orig	2021-04-14 01:08:46 UTC
+++ components/previews/core/previews_features.cc
@@ -14,12 +14,12 @@ namespace features {
 // are enabled are controlled by other features.
 const base::Feature kPreviews {
   "Previews",
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // Previews allowed for Android (but also allow on Linux for dev/debug).
       base::FEATURE_ENABLED_BY_DEFAULT
-#else   // !defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#else   // !defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 };
 
 // Provides slow page triggering parameters.
