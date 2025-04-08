--- components/embedder_support/user_agent_utils.cc.orig	2025-03-24 20:50:14 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -451,6 +451,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
