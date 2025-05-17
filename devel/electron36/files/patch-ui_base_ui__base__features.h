--- ui/base/ui_base_features.h.orig	2025-04-22 20:15:27 UTC
+++ ui/base/ui_base_features.h
@@ -126,7 +126,7 @@ BASE_DECLARE_FEATURE(kWaylandSessionManagement);
 BASE_DECLARE_FEATURE(kWaylandSessionManagement);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kOverrideDefaultOzonePlatformHintToAuto);
 #endif  // BUILDFLAG(IS_LINUX)
