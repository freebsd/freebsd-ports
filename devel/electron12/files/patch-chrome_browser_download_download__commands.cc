--- chrome/browser/download/download_commands.cc.orig	2021-01-07 00:36:22 UTC
+++ chrome/browser/download/download_commands.cc
@@ -27,7 +27,7 @@
 #include "net/base/url_util.h"
 #include "ui/base/clipboard/scoped_clipboard_writer.h"
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
@@ -155,7 +155,7 @@ void DownloadCommands::ExecuteCommand(Command command)
   model_->ExecuteCommand(this, command);
 }
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 Browser* DownloadCommands::GetBrowser() const {
@@ -179,12 +179,12 @@ bool DownloadCommands::CanOpenPdfInSystemViewer() cons
   return IsDownloadPdf() &&
          (IsAdobeReaderDefaultPDFViewer() ? is_adobe_pdf_reader_up_to_date
                                           : true);
-#elif defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return IsDownloadPdf();
 #endif
 }
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 void DownloadCommands::CopyFileAsImageToClipboard() {
