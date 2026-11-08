--- chrome/common/media/cdm_registration.h.orig	2025-04-22 20:15:27 UTC
+++ chrome/common/media/cdm_registration.h
@@ -15,7 +15,7 @@ void RegisterCdmInfo(std::vector<content::CdmInfo>* cd
 void RegisterCdmInfo(std::vector<content::CdmInfo>* cdms);
 
 #if BUILDFLAG(ENABLE_WIDEVINE) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // Returns the software secure Widevine CDM, if one exists.
 std::vector<content::CdmInfo> GetSoftwareSecureWidevine();
 #endif
