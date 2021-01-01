--- components/content_settings/core/browser/website_settings_registry.cc.orig	2019-03-15 06:37:13 UTC
+++ components/content_settings/core/browser/website_settings_registry.cc
@@ -67,7 +67,7 @@ const WebsiteSettingsInfo* WebsiteSettingsRegistry::Re
 #if defined(OS_WIN)
   if (!(platform & PLATFORM_WINDOWS))
     return nullptr;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (!(platform & PLATFORM_LINUX))
     return nullptr;
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
