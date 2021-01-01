--- chrome/common/pref_names.cc.orig	2019-03-15 06:37:09 UTC
+++ chrome/common/pref_names.cc
@@ -918,7 +918,7 @@ const char kAllowedDomainsForApps[] = "settings.allowe
 // See the SafeSitesFilterBehavior policy for details.
 const char kSafeSitesFilterBehavior[] = "settings.safe_sites_filter_behavior";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1001,7 +1001,7 @@ const char kShowUpdatePromotionInfoBar[] =
     "browser.show_update_promotion_info_bar";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Boolean that is false if we should show window manager decorations.  If
 // true, we draw a custom chrome frame (thicker title bar and blue border).
 const char kUseCustomChromeFrame[] = "browser.custom_chrome_frame";
@@ -1363,7 +1363,7 @@ const char kDownloadDefaultDirectory[] = "download.def
 // upgrade a unsafe location to a safe location.
 const char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
