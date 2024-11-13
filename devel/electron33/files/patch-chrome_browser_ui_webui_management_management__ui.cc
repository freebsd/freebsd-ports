--- chrome/browser/ui/webui/management/management_ui.cc.orig	2024-10-16 21:31:03 UTC
+++ chrome/browser/ui/webui/management/management_ui.cc
@@ -108,11 +108,11 @@ content::WebUIDataSource* CreateAndAddManagementUIHtml
        IDS_MANAGEMENT_FILE_TRANSFER_VISIBLE_DATA},
       {kManagementReportFileEvents, IDS_MANAGEMENT_REPORT_FILE_EVENTS},
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {kManagementScreenCaptureEvent, IDS_MANAGEMENT_SCREEN_CAPTURE_EVENT},
       {kManagementScreenCaptureData, IDS_MANAGEMENT_SCREEN_CAPTURE_DATA},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {kManagementDeviceSignalsDisclosure,
        IDS_MANAGEMENT_DEVICE_SIGNALS_DISCLOSURE},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
