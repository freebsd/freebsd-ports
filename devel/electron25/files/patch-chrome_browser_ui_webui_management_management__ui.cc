--- chrome/browser/ui/webui/management/management_ui.cc.orig	2023-03-30 00:33:44 UTC
+++ chrome/browser/ui/webui/management/management_ui.cc
@@ -92,7 +92,7 @@ content::WebUIDataSource* CreateAndAddManagementUIHtml
     {kManagementOnFileTransferVisibleData,
      IDS_MANAGEMENT_FILE_TRANSFER_VISIBLE_DATA},
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {kManagementScreenCaptureEvent, IDS_MANAGEMENT_SCREEN_CAPTURE_EVENT},
     {kManagementScreenCaptureData, IDS_MANAGEMENT_SCREEN_CAPTURE_DATA},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
