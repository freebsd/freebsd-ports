--- chrome/test/base/test_browser_window.h.orig	2021-07-15 19:13:35 UTC
+++ chrome/test/base/test_browser_window.h
@@ -179,7 +179,7 @@ class TestBrowserWindow : public BrowserWindow {
   void MaybeShowProfileSwitchIPH() override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   void ShowHatsDialog(
       const std::string& site_id,
       base::OnceClosure success_callback,
