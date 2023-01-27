--- remoting/host/policy_watcher.cc.orig	2022-10-24 13:33:33 UTC
+++ remoting/host/policy_watcher.cc
@@ -179,7 +179,7 @@ base::Value::Dict PolicyWatcher::GetDefaultPolicies() 
   result.Set(key::kRemoteAccessHostUdpPortRange, "");
   result.Set(key::kRemoteAccessHostClipboardSizeBytes, -1);
   result.Set(key::kRemoteAccessHostAllowRemoteSupportConnections, true);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result.Set(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
