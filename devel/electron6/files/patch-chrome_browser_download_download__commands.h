--- chrome/browser/download/download_commands.h.orig	2019-09-10 10:42:29 UTC
+++ chrome/browser/download/download_commands.h
@@ -45,7 +45,7 @@ class DownloadCommands {
   bool IsCommandVisible(Command command) const;
   void ExecuteCommand(Command command);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
   Browser* GetBrowser() const;
