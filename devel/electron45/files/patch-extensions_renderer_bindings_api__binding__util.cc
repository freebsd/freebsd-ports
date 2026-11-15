--- extensions/renderer/bindings/api_binding_util.cc.orig	2026-04-28 21:06:17 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -142,7 +142,7 @@ std::string_view GetPlatformString() {
 std::string_view GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
