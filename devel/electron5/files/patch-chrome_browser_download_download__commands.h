--- chrome/browser/download/download_commands.h.orig	2019-04-08 08:18:07 UTC
+++ chrome/browser/download/download_commands.h
@@ -42,7 +42,7 @@ class DownloadCommands {
   bool IsCommandVisible(Command command) const;
   void ExecuteCommand(Command command);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
 #endif
