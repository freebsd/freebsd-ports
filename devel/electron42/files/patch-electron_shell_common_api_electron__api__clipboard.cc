--- electron/shell/common/api/electron_api_clipboard.cc.orig	2026-05-08 13:54:01 UTC
+++ electron/shell/common/api/electron_api_clipboard.cc
@@ -95,7 +95,7 @@ std::string Clipboard::Read(const std::string& format_
       ui::ClipboardFormatType::CustomPlatformType(format_string));
   bool rawFormatAvailable =
       IsFormatAvailable(clipboard, rawFormat, ui::ClipboardBuffer::kCopyPaste);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!rawFormatAvailable) {
     rawFormatAvailable = IsFormatAvailable(clipboard, rawFormat,
                                            ui::ClipboardBuffer::kSelection);
@@ -133,7 +133,7 @@ std::string Clipboard::Read(const std::string& format_
             &custom_format_names, run_loop.QuitClosure()));
     run_loop.Run();
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!custom_format_names.contains(format_string)) {
     base::RunLoop run_loop(base::RunLoop::Type::kNestableTasksAllowed);
     clipboard->ExtractCustomPlatformNames(
