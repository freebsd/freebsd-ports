--- chrome/browser/ui/views/frame/browser_view.cc.orig	2021-04-14 01:08:41 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -1504,7 +1504,7 @@ void BrowserView::TabDraggingStatusChanged(bool is_dra
   // CrOS cleanup is done.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   contents_web_view_->SetFastResize(is_dragging);
   if (!is_dragging) {
     // When tab dragging is ended, we need to make sure the web contents get
@@ -1886,7 +1886,7 @@ void BrowserView::UserChangedTheme(BrowserThemeChangeT
   bool must_regenerate_frame;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // GTK and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   must_regenerate_frame = true;
