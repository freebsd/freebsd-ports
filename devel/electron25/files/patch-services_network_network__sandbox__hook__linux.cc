--- services/network/network_sandbox_hook_linux.cc.orig	2023-05-25 00:42:01 UTC
+++ services/network/network_sandbox_hook_linux.cc
@@ -14,11 +14,14 @@
 #include "sandbox/policy/features.h"
 #include "third_party/abseil-cpp/absl/types/optional.h"
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace network {
 
+#if !BUILDFLAG(IS_BSD)
 sandbox::syscall_broker::BrokerCommandSet GetNetworkBrokerCommandSet() {
   return MakeBrokerCommandSet({
       sandbox::syscall_broker::COMMAND_ACCESS,
@@ -102,9 +105,11 @@ void LoadNetworkLibraries() {
   }
 }
 #endif  // BUILDFLAG(IS_CHROMEOS)
+#endif
 
 bool NetworkPreSandboxHook(std::vector<std::string> network_context_parent_dirs,
                            sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS)
   LoadNetworkLibraries();
 #endif
@@ -117,6 +122,7 @@ bool NetworkPreSandboxHook(std::vector<std::string> ne
       GetNetworkBrokerCommandSet(),
       GetNetworkFilePermissions(std::move(network_context_parent_dirs)),
       sandbox::policy::SandboxLinux::PreSandboxHook(), options);
+#endif
 
   return true;
 }
