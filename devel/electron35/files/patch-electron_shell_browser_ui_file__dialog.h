--- electron/shell/browser/ui/file_dialog.h.orig	2025-06-25 20:51:20 UTC
+++ electron/shell/browser/ui/file_dialog.h
@@ -79,7 +79,7 @@ void ShowSaveDialog(const DialogSettings& settings,
 void ShowSaveDialog(const DialogSettings& settings,
                     gin_helper::Promise<gin_helper::Dictionary> promise);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Rewrite of SelectFileDialogLinuxPortal equivalent functions with primary
 // difference being that dbus_thread_linux::GetSharedSessionBus is not used
 // so that version detection can be initiated and compeleted on the dbus thread
