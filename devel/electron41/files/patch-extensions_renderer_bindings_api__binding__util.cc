--- extensions/renderer/bindings/api_binding_util.cc.orig	2026-03-13 16:54:03 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -142,7 +142,7 @@ std::string GetPlatformString() {
 std::string GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
