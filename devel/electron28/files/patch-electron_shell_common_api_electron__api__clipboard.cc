--- electron/shell/common/api/electron_api_clipboard.cc.orig	2023-08-14 18:19:06 UTC
+++ electron/shell/common/api/electron_api_clipboard.cc
@@ -57,7 +57,7 @@ std::string Clipboard::Read(const std::string& format_
       ui::ClipboardFormatType::CustomPlatformType(format_string));
   bool rawFormatAvailable = clipboard->IsFormatAvailable(
       rawFormat, ui::ClipboardBuffer::kCopyPaste, /* data_dst = */ nullptr);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!rawFormatAvailable) {
     rawFormatAvailable = clipboard->IsFormatAvailable(
         rawFormat, ui::ClipboardBuffer::kSelection, /* data_dst = */ nullptr);
@@ -73,7 +73,7 @@ std::string Clipboard::Read(const std::string& format_
   custom_format_names =
       clipboard->ExtractCustomPlatformNames(ui::ClipboardBuffer::kCopyPaste,
                                             /* data_dst = */ nullptr);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::Contains(custom_format_names, format_string)) {
     custom_format_names =
         clipboard->ExtractCustomPlatformNames(ui::ClipboardBuffer::kSelection,
