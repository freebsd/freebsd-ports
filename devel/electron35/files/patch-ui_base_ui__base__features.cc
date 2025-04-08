--- ui/base/ui_base_features.cc.orig	2025-03-24 20:50:14 UTC
+++ ui/base/ui_base_features.cc
@@ -133,7 +133,7 @@ BASE_FEATURE(kWaylandUiScale,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this feature is enabled, users not specify --ozone-platform-hint switch
 // will get --ozone-platform-hint=auto treatment. https://crbug.com/40250220.
 COMPONENT_EXPORT(UI_BASE_FEATURES)
@@ -215,7 +215,7 @@ BASE_FEATURE(kExperimentalFlingAnimation,
 // native apps on Windows.
 BASE_FEATURE(kExperimentalFlingAnimation,
              "ExperimentalFlingAnimation",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -291,7 +291,7 @@ BASE_FEATURE(kEyeDropper,
 BASE_FEATURE(kEyeDropper,
              "EyeDropper",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
