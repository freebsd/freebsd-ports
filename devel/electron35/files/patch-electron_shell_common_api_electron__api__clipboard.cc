--- electron/shell/common/api/electron_api_clipboard.cc.orig	2025-03-10 00:01:50 UTC
+++ electron/shell/common/api/electron_api_clipboard.cc
@@ -58,7 +58,7 @@ std::string Clipboard::Read(const std::string& format_
       ui::ClipboardFormatType::CustomPlatformType(format_string));
   bool rawFormatAvailable = clipboard->IsFormatAvailable(
       rawFormat, ui::ClipboardBuffer::kCopyPaste, /* data_dst = */ nullptr);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!rawFormatAvailable) {
     rawFormatAvailable = clipboard->IsFormatAvailable(
         rawFormat, ui::ClipboardBuffer::kSelection, /* data_dst = */ nullptr);
@@ -74,7 +74,7 @@ std::string Clipboard::Read(const std::string& format_
   custom_format_names =
       clipboard->ExtractCustomPlatformNames(ui::ClipboardBuffer::kCopyPaste,
                                             /* data_dst = */ nullptr);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!custom_format_names.contains(format_string)) {
     custom_format_names =
         clipboard->ExtractCustomPlatformNames(ui::ClipboardBuffer::kSelection,
