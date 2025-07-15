--- ui/base/ui_base_features.h.orig	2025-06-30 07:04:30 UTC
+++ ui/base/ui_base_features.h
@@ -129,7 +129,7 @@ BASE_DECLARE_FEATURE(kWaylandSessionManagement);
 BASE_DECLARE_FEATURE(kWaylandSessionManagement);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kOverrideDefaultOzonePlatformHintToAuto);
 #endif  // BUILDFLAG(IS_LINUX)
