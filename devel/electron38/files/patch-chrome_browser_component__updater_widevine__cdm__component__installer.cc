--- chrome/browser/component_updater/widevine_cdm_component_installer.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/component_updater/widevine_cdm_component_installer.cc
@@ -41,7 +41,7 @@
 #include "third_party/widevine/cdm/buildflags.h"
 #include "third_party/widevine/cdm/widevine_cdm_common.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/path_service.h"
 #include "chrome/common/chrome_paths.h"
 #include "chrome/common/media/component_widevine_cdm_hint_file_linux.h"
@@ -73,7 +73,7 @@ const char ImageLoaderComponentName[] = "WidevineCdm";
 const char ImageLoaderComponentName[] = "WidevineCdm";
 #endif
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 // On Linux and ChromeOS the Widevine CDM is loaded at startup before the
 // zygote is locked down. As a result there is no need to register the CDM
 // with Chrome as it can't be used until Chrome is restarted.
@@ -101,7 +101,7 @@ void RegisterWidevineCdmWithChrome(const base::Version
 }
 #endif  // !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // On Linux and ChromeOS the Widevine CDM is loaded at startup before the
 // zygote is locked down. To locate the Widevine CDM at startup, a hint file
 // is used. Update the hint file with the new Widevine CDM path.
@@ -392,7 +392,7 @@ void WidevineCdmComponentInstallerPolicy::UpdateCdmPat
     return;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   VLOG(1) << "Updating hint file with Widevine CDM " << cdm_version;
 
   // This is running on a thread that allows IO, so simply update the hint file.
