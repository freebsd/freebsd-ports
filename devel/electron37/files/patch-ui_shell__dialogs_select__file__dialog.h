--- ui/shell_dialogs/select_file_dialog.h.orig	2024-10-28 21:05:17 UTC
+++ ui/shell_dialogs/select_file_dialog.h
@@ -224,7 +224,7 @@ class SHELL_DIALOGS_EXPORT SelectFileDialog
                   const GURL* caller = nullptr);
   bool HasMultipleFileTypeChoices();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the label used for the file select button.
   virtual void SetButtonLabel(const std::string& label) = 0;
 
