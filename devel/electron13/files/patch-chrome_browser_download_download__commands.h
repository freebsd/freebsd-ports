--- chrome/browser/download/download_commands.h.orig	2021-07-15 19:13:32 UTC
+++ chrome/browser/download/download_commands.h
@@ -49,7 +49,7 @@ class DownloadCommands {
   bool IsCommandVisible(Command command) const;
   void ExecuteCommand(Command command);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
