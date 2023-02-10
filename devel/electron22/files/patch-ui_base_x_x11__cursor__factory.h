--- ui/base/x/x11_cursor_factory.h.orig	2022-08-31 12:19:35 UTC
+++ ui/base/x/x11_cursor_factory.h
@@ -16,7 +16,7 @@
 #include "ui/base/cursor/mojom/cursor_type.mojom-shared.h"
 #include "ui/linux/cursor_theme_manager_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -59,7 +59,7 @@ class COMPONENT_EXPORT(UI_BASE_X) X11CursorFactory
 
   std::map<mojom::CursorType, scoped_refptr<X11Cursor>> default_cursors_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<LinuxUi,
                           CursorThemeManagerObserver,
                           &LinuxUi::AddCursorThemeObserver,
