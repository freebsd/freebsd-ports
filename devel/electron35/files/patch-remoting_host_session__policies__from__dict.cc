--- remoting/host/session_policies_from_dict.cc.orig	2025-01-27 17:37:37 UTC
+++ remoting/host/session_policies_from_dict.cc
@@ -76,7 +76,7 @@ std::optional<SessionPolicies> SessionPoliciesFromDict
       .curtain_required =
           dict.FindBool(policy::key::kRemoteAccessHostRequireCurtain),
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       .host_username_match_required =
           dict.FindBool(policy::key::kRemoteAccessHostMatchUsername),
 #endif
