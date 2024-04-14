--- chrome/browser/apps/app_service/publishers/extension_apps.cc.orig	2024-02-21 00:20:33 UTC
+++ chrome/browser/apps/app_service/publishers/extension_apps.cc
@@ -24,7 +24,7 @@ bool ExtensionApps::Accepts(const extensions::Extensio
 
 bool ExtensionApps::Accepts(const extensions::Extension* extension) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile(),
                                                       extension->id())) {
     return false;
