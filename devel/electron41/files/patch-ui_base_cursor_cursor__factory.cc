--- ui/base/cursor/cursor_factory.cc.orig	2026-08-14 04:05:02 UTC
+++ ui/base/cursor/cursor_factory.cc
@@ -98,7 +98,7 @@ void CursorFactory::ObserveThemeChanges() {
   NOTIMPLEMENTED();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 bool IsValidCursorThemeName(std::string_view name) {
   if (name.empty() || name == ".") {
