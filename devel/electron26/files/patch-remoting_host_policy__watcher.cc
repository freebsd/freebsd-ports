--- remoting/host/policy_watcher.cc.orig	2023-05-25 00:42:01 UTC
+++ remoting/host/policy_watcher.cc
@@ -183,7 +183,7 @@ base::Value::Dict PolicyWatcher::GetDefaultPolicies() 
   result.Set(key::kRemoteAccessHostAllowEnterpriseRemoteSupportConnections,
              true);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result.Set(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
