--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -890,7 +890,7 @@ ExtensionFunction::ResponseAction WindowsCreateFunctio
 // minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   if (new_window->initial_show_state() == ui::SHOW_STATE_MINIMIZED) {
     new_window->window()->Minimize();
   }
