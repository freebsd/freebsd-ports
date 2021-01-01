--- components/previews/core/previews_features.cc.orig	2019-12-12 12:39:32 UTC
+++ components/previews/core/previews_features.cc
@@ -14,12 +14,12 @@ namespace features {
 // are enabled are controlled by other features.
 const base::Feature kPreviews {
   "Previews",
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
       // Previews allowed for Android (but also allow on Linux for dev/debug).
       base::FEATURE_ENABLED_BY_DEFAULT
-#else   // !defined(OS_ANDROID) || defined(OS_LINUX)
+#else   // !defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 };
 
 // Enables the Offline previews on android slow connections.
