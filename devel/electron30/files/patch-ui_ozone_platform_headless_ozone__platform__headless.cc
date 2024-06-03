--- ui/ozone/platform/headless/ozone_platform_headless.cc.orig	2024-04-15 20:34:30 UTC
+++ ui/ozone/platform/headless/ozone_platform_headless.cc
@@ -103,7 +103,7 @@ class OzonePlatformHeadless : public OzonePlatform {
   }
 
 // Desktop Linux, not CastOS.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
   const PlatformProperties& GetPlatformProperties() override {
     static base::NoDestructor<OzonePlatform::PlatformProperties> properties;
     static bool initialized = false;
