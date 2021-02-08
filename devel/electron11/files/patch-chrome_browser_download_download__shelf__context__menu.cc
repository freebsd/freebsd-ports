--- chrome/browser/download/download_shelf_context_menu.cc.orig	2021-01-07 00:36:22 UTC
+++ chrome/browser/download/download_shelf_context_menu.cc
@@ -146,7 +146,7 @@ base::string16 DownloadShelfContextMenu::GetLabelForCo
                    : IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
         }
-#elif defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
         if (can_open_pdf_in_system_viewer) {
           id = IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
