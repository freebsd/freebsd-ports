--- chrome/browser/download/download_file_picker.cc.orig	2023-02-01 18:43:11 UTC
+++ chrome/browser/download/download_file_picker.cc
@@ -17,7 +17,7 @@
 #include "content/public/browser/download_manager.h"
 #include "content/public/browser/web_contents.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_window.h"
 #include "ui/aura/window.h"
@@ -82,7 +82,7 @@ DownloadFilePicker::DownloadFilePicker(download::Downl
   // dialog in Linux (See SelectFileImpl() in select_file_dialog_linux_gtk.cc).
   // and windows.Here we make owning_window host to browser current active
   // window if it is null. https://crbug.com/1301898
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (!owning_window || !owning_window->GetHost()) {
     owning_window = BrowserList::GetInstance()
                         ->GetLastActive()
