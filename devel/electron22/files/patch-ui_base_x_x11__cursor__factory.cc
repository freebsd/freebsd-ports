--- ui/base/x/x11_cursor_factory.cc.orig	2022-08-31 12:19:35 UTC
+++ ui/base/x/x11_cursor_factory.cc
@@ -56,7 +56,7 @@ scoped_refptr<PlatformCursor> X11CursorFactory::Create
 }
 
 void X11CursorFactory::ObserveThemeChanges() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = LinuxUi::instance();
   DCHECK(linux_ui);
   cursor_theme_observation_.Observe(linux_ui);
