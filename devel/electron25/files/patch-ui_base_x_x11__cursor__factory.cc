--- ui/base/x/x11_cursor_factory.cc.orig	2023-02-01 18:43:51 UTC
+++ ui/base/x/x11_cursor_factory.cc
@@ -13,7 +13,7 @@
 #include "ui/gfx/geometry/point.h"
 #include "ui/gfx/x/connection.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -60,7 +60,7 @@ scoped_refptr<PlatformCursor> X11CursorFactory::Create
 }
 
 void X11CursorFactory::ObserveThemeChanges() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = LinuxUi::instance();
   DCHECK(linux_ui);
   cursor_theme_observation_.Observe(linux_ui);
