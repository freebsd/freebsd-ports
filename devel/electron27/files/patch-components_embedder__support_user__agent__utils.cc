--- components/embedder_support/user_agent_utils.cc.orig	2023-10-19 19:58:18 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -432,6 +432,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
