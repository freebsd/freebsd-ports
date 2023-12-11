--- ui/base/x/x11_cursor_factory.h.orig	2023-08-10 01:49:09 UTC
+++ ui/base/x/x11_cursor_factory.h
@@ -20,7 +20,7 @@ namespace ui {
 class X11Cursor;
 class XCursorLoader;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class LinuxUi;
 #endif
 
@@ -60,7 +60,7 @@ class COMPONENT_EXPORT(UI_BASE_X) X11CursorFactory
 
   std::map<mojom::CursorType, scoped_refptr<X11Cursor>> default_cursors_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<LinuxUi, CursorThemeManagerObserver>
       cursor_theme_observation_{this};
 #endif
