--- extensions/renderer/bindings/api_binding_util.cc.orig	2025-10-21 20:19:54 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -128,7 +128,7 @@ std::string GetPlatformString() {
 std::string GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
