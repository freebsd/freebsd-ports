--- printing/sandbox/print_backend_sandbox_hook_linux.cc.orig	2022-02-28 16:54:41 UTC
+++ printing/sandbox/print_backend_sandbox_hook_linux.cc
@@ -9,21 +9,28 @@
 #include "base/files/file_util.h"
 #include "base/path_service.h"
 #include "build/build_config.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/linux/syscall_broker/broker_command.h"
 #include "sandbox/linux/syscall_broker/broker_file_permission.h"
 #include "sandbox/policy/export.h"
 #include "sandbox/policy/linux/sandbox_linux.h"
 #include "services/network/network_sandbox_hook_linux.h"
+#else
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS) && defined(USE_CUPS)
 #include "printing/backend/cups_connection_pool.h"
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace printing {
 
+#if !BUILDFLAG(IS_BSD)
 namespace {
 
 sandbox::syscall_broker::BrokerCommandSet GetPrintBackendBrokerCommandSet() {
@@ -84,9 +91,11 @@ std::vector<BrokerFilePermission> GetPrintBackendFileP
 }
 
 }  // namespace
+#endif
 
 bool PrintBackendPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS) && defined(USE_CUPS)
   // Create the socket connections to the CUPS server before engaging the
   // sandbox, since new connections cannot be made after that.
@@ -100,6 +109,7 @@ bool PrintBackendPreSandboxHook(
       sandbox::policy::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
