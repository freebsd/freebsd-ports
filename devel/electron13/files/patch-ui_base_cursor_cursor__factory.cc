--- ui/base/cursor/cursor_factory.cc.orig	2021-07-15 19:14:08 UTC
+++ ui/base/cursor/cursor_factory.cc
@@ -69,7 +69,7 @@ void CursorFactory::ObserveThemeChanges() {
 
 void CursorFactory::SetDeviceScaleFactor(float scale) {}
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Returns a cursor name compatible with either X11 or the FreeDesktop.org
 // cursor spec ([1] and [2]), followed by fallbacks that can work as
@@ -190,6 +190,6 @@ std::vector<std::string> CursorNamesFromType(mojom::Cu
   return {"left_ptr"};
 }
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace ui
