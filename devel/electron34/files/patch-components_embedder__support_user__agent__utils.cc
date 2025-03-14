--- components/embedder_support/user_agent_utils.cc.orig	2025-01-27 17:37:37 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -500,6 +500,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
