--- chrome/renderer/pepper/pepper_flash_font_file_host.cc.orig	2022-05-19 05:17:39 UTC
+++ chrome/renderer/pepper/pepper_flash_font_file_host.cc
@@ -16,7 +16,7 @@
 #include "ppapi/proxy/ppapi_messages.h"
 #include "ppapi/proxy/serialized_structs.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "pdf/font_table_linux.h"
 #elif BUILDFLAG(IS_WIN)
@@ -30,7 +30,7 @@ PepperFlashFontFileHost::PepperFlashFontFileHost(
     const ppapi::proxy::SerializedFontDescription& description,
     PP_PrivateFontCharset charset)
     : ResourceHost(host->GetPpapiHost(), instance, resource) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The global SkFontConfigInterface is configured and initialized with a
   // SkFontconfigInterface compatible font_service::FontLoader in
   // RendererBlinkPlatformImpl (called from RenderThreadImpl::Init) at startup
@@ -75,7 +75,7 @@ bool PepperFlashFontFileHost::GetFontData(uint32_t tab
                                           void* buffer,
                                           size_t* length) {
   bool result = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (font_file_.IsValid()) {
     result =
         pdf::GetFontTable(font_file_.GetPlatformFile(), table, /*offset=*/0,
