--- components/feature_engagement/public/event_constants.cc.orig	2019-03-15 06:37:14 UTC
+++ components/feature_engagement/public/event_constants.cc
@@ -24,9 +24,9 @@ const char kIncognitoWindowSessionTimeMet[] =
 
 #endif  // BUILDFLAG(ENABLE_DESKTOP_IN_PRODUCT_HELP)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 
 #if defined(OS_IOS)
 const char kChromeOpened[] = "chrome_opened";
