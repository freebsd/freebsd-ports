--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2024-02-21 00:20:34 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -836,7 +836,7 @@ ExtensionFunction::ResponseAction WindowsCreateFunctio
 // minimized.
 // TODO(crbug.com/1410400): Remove this workaround when linux is fixed.
 // TODO(crbug.com/1410400): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   if (new_window->initial_show_state() == ui::SHOW_STATE_MINIMIZED) {
     new_window->window()->Minimize();
   }
