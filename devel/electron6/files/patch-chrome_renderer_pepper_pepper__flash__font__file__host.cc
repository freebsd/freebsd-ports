--- chrome/renderer/pepper/pepper_flash_font_file_host.cc.orig	2019-09-10 10:42:32 UTC
+++ chrome/renderer/pepper/pepper_flash_font_file_host.cc
@@ -15,7 +15,7 @@
 #include "ppapi/proxy/ppapi_messages.h"
 #include "ppapi/proxy/serialized_structs.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "content/public/common/common_sandbox_support_linux.h"
 #elif defined(OS_WIN)
@@ -29,7 +29,7 @@ PepperFlashFontFileHost::PepperFlashFontFileHost(
     const ppapi::proxy::SerializedFontDescription& description,
     PP_PrivateFontCharset charset)
     : ResourceHost(host->GetPpapiHost(), instance, resource) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // The global SkFontConfigInterface is configured and initialized with a
   // SkFontconfigInterface compatible font_service::FontLoader in
   // RendererBlinkPlatformImpl (called from RenderThreadImpl::Init) at startup
@@ -74,7 +74,7 @@ bool PepperFlashFontFileHost::GetFontData(uint32_t tab
                                           void* buffer,
                                           size_t* length) {
   bool result = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (font_file_.IsValid()) {
     result = content::GetFontTable(font_file_.GetPlatformFile(), table,
                                    0 /* offset */,
