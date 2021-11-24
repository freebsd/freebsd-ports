--- ui/base/cursor/cursor_factory.h.orig	2021-07-15 19:14:08 UTC
+++ ui/base/cursor/cursor_factory.h
@@ -73,7 +73,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR_BASE) CursorFact
   virtual void SetDeviceScaleFactor(float scale);
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR_BASE)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
