--- remoting/host/session_policies_from_dict.cc.orig	2025-04-22 20:15:27 UTC
+++ remoting/host/session_policies_from_dict.cc
@@ -75,7 +75,7 @@ std::optional<SessionPolicies> SessionPoliciesFromDict
   session_policies.curtain_required =
       dict.FindBool(policy::key::kRemoteAccessHostRequireCurtain);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   session_policies.host_username_match_required =
       dict.FindBool(policy::key::kRemoteAccessHostMatchUsername);
 #endif
