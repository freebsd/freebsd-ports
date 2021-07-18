--- chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc.orig	2021-04-14 01:08:41 UTC
+++ chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc
@@ -22,7 +22,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -61,7 +61,7 @@ void ChromeNativeAppWindowViewsAura::OnBeforeWidgetIni
     views::Widget* widget) {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   std::string app_name =
       web_app::GenerateApplicationNameFromAppId(app_window()->extension_id());
   // Set up a custom WM_CLASS for app windows. This allows task switchers in
@@ -71,7 +71,7 @@ void ChromeNativeAppWindowViewsAura::OnBeforeWidgetIni
   init_params->wm_class_class = shell_integration_linux::GetProgramClassClass();
   const char kX11WindowRoleApp[] = "app";
   init_params->wm_role_name = std::string(kX11WindowRoleApp);
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
   ChromeNativeAppWindowViews::OnBeforeWidgetInit(create_params, init_params,
                                                  widget);
