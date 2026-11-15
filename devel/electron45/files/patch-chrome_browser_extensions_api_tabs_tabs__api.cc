--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2026-11-10 20:19:00 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -1417,7 +1417,7 @@ ExtensionFunction::ResponseValue WindowsCreateFunction
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   if (BrowserInitState::From(new_window)->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->GetWindow()->Minimize();
