--- chrome/browser/extensions/api/tabs/tabs_api_non_android.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api_non_android.cc
@@ -756,7 +756,7 @@ ExtensionFunction::ResponseAction WindowsCreateFunctio
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   if (new_window->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->window()->Minimize();
