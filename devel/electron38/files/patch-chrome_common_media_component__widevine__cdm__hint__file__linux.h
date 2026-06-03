--- chrome/common/media/component_widevine_cdm_hint_file_linux.h.orig	2025-04-22 20:15:27 UTC
+++ chrome/common/media/component_widevine_cdm_hint_file_linux.h
@@ -14,7 +14,7 @@
 #error "This file only applies when Widevine used."
 #endif
 
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #error "This file only applies to desktop Linux and ChromeOS."
 #endif
 
