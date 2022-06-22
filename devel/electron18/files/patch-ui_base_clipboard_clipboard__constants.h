--- ui/base/clipboard/clipboard_constants.h.orig	2022-05-19 03:47:20 UTC
+++ ui/base/clipboard/clipboard_constants.h
@@ -46,7 +46,7 @@ extern const char kMimeTypeDataTransferEndpoint[];
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 // Linux-specific MIME type constants (also used in Fuchsia).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeLinuxUtf8String[];
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
