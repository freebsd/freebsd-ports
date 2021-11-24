--- chrome/browser/apps/platform_apps/api/media_galleries/media_galleries_apitest.cc.orig	2021-07-15 19:13:32 UTC
+++ chrome/browser/apps/platform_apps/api/media_galleries/media_galleries_apitest.cc
@@ -299,7 +299,7 @@ IN_PROC_BROWSER_TEST_F(MediaGalleriesPlatformAppPpapiT
 
 // Test is flaky, it fails on certain bots, namely WinXP Tests(1) and Linux
 // (dbg)(1)(32).  See crbug.com/354425.
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define MAYBE_MediaGalleriesNoAccess DISABLED_MediaGalleriesNoAccess
 #else
 #define MAYBE_MediaGalleriesNoAccess MediaGalleriesNoAccess
@@ -337,7 +337,7 @@ IN_PROC_BROWSER_TEST_F(MediaGalleriesPlatformAppBrowse
 
 // Test is flaky, it fails on certain bots, namely WinXP Tests(1) and Linux
 // (dbg)(1)(32).  See crbug.com/354425.
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define MAYBE_MediaGalleriesCopyTo DISABLED_MediaGalleriesCopyTo
 #else
 #define MAYBE_MediaGalleriesCopyTo MediaGalleriesCopyTo
