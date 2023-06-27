--- ui/base/clipboard/clipboard_constants.h.orig	2023-02-01 18:43:51 UTC
+++ ui/base/clipboard/clipboard_constants.h
@@ -47,7 +47,7 @@ extern const char kMimeTypeDataTransferEndpoint[];
 
 // ----- LINUX & CHROMEOS & FUCHSIA MIME TYPES -----
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeLinuxUtf8String[];
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
