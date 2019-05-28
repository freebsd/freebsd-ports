--- chrome/common/webui_url_constants.cc.orig	2019-03-15 06:37:09 UTC
+++ chrome/common/webui_url_constants.cc
@@ -237,7 +237,7 @@ const char kChromeUICastHost[] = "cast";
 const char kChromeUICastURL[] = "chrome://cast/";
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kChromeUIDiscardsHost[] = "discards";
 const char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
@@ -246,11 +246,11 @@ const char kChromeUIDiscardsURL[] = "chrome://discards
 const char kChromeUILinuxProxyConfigHost[] = "linux-proxy-config";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 const char kChromeUISandboxHost[] = "sandbox";
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogHost[] = "tab-modal-confirm-dialog";
 #endif
 
@@ -398,13 +398,13 @@ const char* const kChromeHostURLs[] = {
     kChromeUIInternetDetailDialogHost,
     kChromeUIAssistantOptInHost,
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     kChromeUIDiscardsHost,
 #endif
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
     kChromeUILinuxProxyConfigHost,
 #endif
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     kChromeUISandboxHost,
 #endif
 #if defined(OS_WIN)
