--- chrome/common/webui_url_constants.h.orig	2019-09-10 11:13:46 UTC
+++ chrome/common/webui_url_constants.h
@@ -262,7 +262,7 @@ extern const char kChromeUIMetroFlowURL[];
 extern const char kChromeUICastHost[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kChromeUIDiscardsHost[];
 extern const char kChromeUIDiscardsURL[];
 extern const char kChromeUIHatsHost[];
@@ -274,17 +274,17 @@ extern const char kChromeUIHatsURL[];
 extern const char kChromeUILinuxProxyConfigHost[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 extern const char kChromeUISandboxHost[];
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kChromeUIBrowserSwitchHost[];
 extern const char kChromeUIBrowserSwitchURL[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
 #endif
 
