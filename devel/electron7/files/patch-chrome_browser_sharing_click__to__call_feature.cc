--- chrome/browser/sharing/click_to_call/feature.cc.orig	2019-12-12 12:39:15 UTC
+++ chrome/browser/sharing/click_to_call/feature.cc
@@ -9,12 +9,12 @@ const base::Feature kClickToCallReceiver{"ClickToCallR
                                          base::FEATURE_ENABLED_BY_DEFAULT};
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const base::Feature kClickToCallContextMenuForSelectedText{
     "ClickToCallContextMenuForSelectedText", base::FEATURE_DISABLED_BY_DEFAULT};
 
 const base::Feature kClickToCallUI{"ClickToCallUI",
                                    base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
