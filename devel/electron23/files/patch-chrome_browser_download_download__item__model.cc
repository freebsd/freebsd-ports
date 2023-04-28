--- chrome/browser/download/download_item_model.cc.orig	2023-02-01 18:43:11 UTC
+++ chrome/browser/download/download_item_model.cc
@@ -801,7 +801,7 @@ bool DownloadItemModel::IsCommandChecked(
              download_crx_util::IsExtensionDownload(*download_);
     case DownloadCommands::ALWAYS_OPEN_TYPE:
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       if (download_commands->CanOpenPdfInSystemViewer()) {
         DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(profile());
         return prefs->ShouldOpenPdfInSystemReader();
@@ -844,7 +844,7 @@ void DownloadItemModel::ExecuteCommand(DownloadCommand
       base::UmaHistogramBoolean("Download.SetAlwaysOpenTo", !is_checked);
       DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(profile());
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       if (download_commands->CanOpenPdfInSystemViewer()) {
         prefs->SetShouldOpenPdfInSystemReader(!is_checked);
         SetShouldPreferOpeningInBrowser(is_checked);
@@ -1255,7 +1255,7 @@ void DownloadItemModel::DetermineAndSetShouldPreferOpe
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (download_->GetOriginalMimeType() == "application/x-x509-user-cert") {
     SetShouldPreferOpeningInBrowser(true);
     return;
