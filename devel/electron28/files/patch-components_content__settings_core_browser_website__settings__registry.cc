--- components/content_settings/core/browser/website_settings_registry.cc.orig	2022-02-28 16:54:41 UTC
+++ components/content_settings/core/browser/website_settings_registry.cc
@@ -66,7 +66,7 @@ const WebsiteSettingsInfo* WebsiteSettingsRegistry::Re
 #if BUILDFLAG(IS_WIN)
   if (!(platform & PLATFORM_WINDOWS))
     return nullptr;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!(platform & PLATFORM_LINUX))
     return nullptr;
 #elif BUILDFLAG(IS_MAC)
