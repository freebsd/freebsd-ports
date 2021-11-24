--- ui/platform_window/platform_window_init_properties.h.orig	2021-07-15 19:14:08 UTC
+++ ui/platform_window/platform_window_init_properties.h
@@ -47,7 +47,7 @@ enum class PlatformWindowShadowType {
 
 class WorkspaceExtensionDelegate;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -93,7 +93,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW) PlatformWindo
 
   PlatformWindowShadowType shadow_type = PlatformWindowShadowType::kDefault;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool prefer_dark_theme = false;
   gfx::ImageSkia* icon = nullptr;
   base::Optional<int> background_color;
