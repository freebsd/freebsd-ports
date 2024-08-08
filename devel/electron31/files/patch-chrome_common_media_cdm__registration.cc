--- chrome/common/media/cdm_registration.cc.orig	2024-06-18 21:43:25 UTC
+++ chrome/common/media/cdm_registration.cc
@@ -30,11 +30,11 @@
 
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #include "third_party/widevine/cdm/widevine_cdm_common.h"  // nogncheck
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "base/native_library.h"
 #include "chrome/common/chrome_paths.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/no_destructor.h"
 #include "chrome/common/media/component_widevine_cdm_hint_file_linux.h"
 #include "media/cdm/supported_audio_codecs.h"
@@ -60,7 +60,7 @@ using Robustness = content::CdmInfo::Robustness;
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #if (BUILDFLAG(BUNDLE_WIDEVINE_CDM) ||            \
      BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // Create a CdmInfo for a Widevine CDM, using |version|, |cdm_library_path|, and
 // |capability|.
 std::unique_ptr<content::CdmInfo> CreateWidevineCdmInfo(
@@ -105,7 +105,7 @@ std::unique_ptr<content::CdmInfo> CreateCdmInfoFromWid
         // BUILDFLAG(IS_CHROMEOS))
 
 #if BUILDFLAG(BUNDLE_WIDEVINE_CDM) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // On Linux/ChromeOS we have to preload the CDM since it uses the zygote
 // sandbox. On Windows and Mac, CDM registration is handled by Component
 // Update (as the CDM can be loaded only when needed).
@@ -129,7 +129,7 @@ content::CdmInfo* GetBundledWidevine() {
         // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 
 #if BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // This code checks to see if Component Updater picked a version of the Widevine
 // CDM to be used last time it ran. (Component Updater may choose the bundled
 // CDM if there is not a new version available for download.) If there is one
@@ -171,7 +171,7 @@ void AddSoftwareSecureWidevine(std::vector<content::Cd
       /*supports_sub_key_systems=*/false, kWidevineCdmDisplayName,
       kWidevineCdmType, base::Version(), base::FilePath());
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(WIDEVINE_CDM_MIN_GLIBC_VERSION)
   base::Version glibc_version(gnu_get_libc_version());
   DCHECK(glibc_version.IsValid());
@@ -429,7 +429,7 @@ void RegisterCdmInfo(std::vector<content::CdmInfo>* cd
   DVLOG(3) << __func__ << " done with " << cdms->size() << " cdms";
 }
 
-#if BUILDFLAG(ENABLE_WIDEVINE) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_WIDEVINE) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 std::vector<content::CdmInfo> GetSoftwareSecureWidevineForTesting() {
   std::vector<content::CdmInfo> cdms;
   AddSoftwareSecureWidevine(&cdms);
