--- ui/base/ui_base_features.h.orig	2025-03-24 20:50:14 UTC
+++ ui/base/ui_base_features.h
@@ -124,7 +124,7 @@ BASE_DECLARE_FEATURE(kWaylandUiScale);
 BASE_DECLARE_FEATURE(kWaylandUiScale);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kOverrideDefaultOzonePlatformHintToAuto);
 #endif  // BUILDFLAG(IS_LINUX)
