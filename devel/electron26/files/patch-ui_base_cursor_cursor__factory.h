--- ui/base/cursor/cursor_factory.h.orig	2023-08-10 01:49:09 UTC
+++ ui/base/cursor/cursor_factory.h
@@ -86,7 +86,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR) CursorFactory {
   base::ObserverList<CursorFactoryObserver>::Unchecked observers_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
