--- chrome/renderer/pepper/pepper_flash_font_file_host.h.orig	2022-05-19 05:17:39 UTC
+++ chrome/renderer/pepper/pepper_flash_font_file_host.h
@@ -12,7 +12,7 @@
 #include "ppapi/c/private/pp_private_font_charset.h"
 #include "ppapi/host/resource_host.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file.h"
 #elif BUILDFLAG(IS_WIN)
 #include "third_party/skia/include/core/SkRefCnt.h"
@@ -52,7 +52,7 @@ class PepperFlashFontFileHost : public ppapi::host::Re
                          uint32_t table);
   bool GetFontData(uint32_t table, void* buffer, size_t* length);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::File font_file_;
 #elif BUILDFLAG(IS_WIN)
   sk_sp<SkTypeface> typeface_;
