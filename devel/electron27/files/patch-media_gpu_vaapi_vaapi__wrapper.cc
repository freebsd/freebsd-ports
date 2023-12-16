--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2023-10-19 19:58:27 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -70,7 +70,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
@@ -1441,7 +1441,7 @@ bool IsVBREncodingSupported(VAProfile va_profile) {
   return VASupportedProfiles::Get().IsProfileSupported(mode, va_profile);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Some VA-API drivers (vdpau-va-driver) will crash if used with VA/DRM on
 // NVIDIA GPUs. This function checks if such drivers are present.
 bool IsBrokenNvidiaVaapiDriverPresent() {
@@ -1502,7 +1502,7 @@ void VADisplayStateSingleton::PreSandboxInitialization
   VADisplayStateSingleton& va_display_state = GetInstance();
   base::AutoLock lock(va_display_state.lock_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string va_driver_name;
   auto env = base::Environment::Create();
   if (env->GetVar("LIBVA_DRIVER_NAME", &va_driver_name) &&
@@ -1539,7 +1539,7 @@ void VADisplayStateSingleton::PreSandboxInitialization
     if (base::EqualsCaseInsensitiveASCII(version_name, "vgem")) {
       continue;
     }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Skip NVIDIA GPUs if the VA-API driver used for them is known for crashing
     // with VA/DRM.
     if (is_nvidia_va_drm_broken &&
@@ -1572,7 +1572,7 @@ VADisplayStateHandle VADisplayStateSingleton::GetHandl
     return {};
   }
 
-#if BUILDFLAG(IS_OZONE) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_OZONE) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // TODO(crbug.com/1116701): add vaapi support for other Ozone platforms on
   // Linux. See comment in OzonePlatform::PlatformProperties::supports_vaapi
   // for more details. This will also require revisiting everything that's
@@ -2403,7 +2403,7 @@ scoped_refptr<VASurface> VaapiWrapper::CreateVASurface
     return nullptr;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1326754): enable use DRIME_PRIME_2 API on Linux with the
   // iHD driver.
   const bool use_drm_prime_2 = false;
