--- electron/shell/common/api/electron_api_clipboard.cc.orig	2026-03-17 08:46:52 UTC
+++ electron/shell/common/api/electron_api_clipboard.cc
@@ -62,7 +62,7 @@ std::string Clipboard::Read(const std::string& format_
       ui::ClipboardFormatType::CustomPlatformType(format_string));
   bool rawFormatAvailable = clipboard->IsFormatAvailable(
       rawFormat, ui::ClipboardBuffer::kCopyPaste, /* data_dst = */ nullptr);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!rawFormatAvailable) {
     rawFormatAvailable = clipboard->IsFormatAvailable(
         rawFormat, ui::ClipboardBuffer::kSelection, /* data_dst = */ nullptr);
@@ -88,7 +88,7 @@ std::string Clipboard::Read(const std::string& format_
             &custom_format_names, run_loop.QuitClosure()));
     run_loop.Run();
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!custom_format_names.contains(format_string)) {
     base::RunLoop run_loop(base::RunLoop::Type::kNestableTasksAllowed);
     clipboard->ExtractCustomPlatformNames(
