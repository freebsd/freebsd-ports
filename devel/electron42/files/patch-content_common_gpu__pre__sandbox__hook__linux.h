--- content/common/gpu_pre_sandbox_hook_linux.h.orig	2025-08-26 20:49:50 UTC
+++ content/common/gpu_pre_sandbox_hook_linux.h
@@ -7,7 +7,15 @@
 
 #include <vector>
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#include "sandbox/linux/syscall_broker/broker_command.h"
+#include "sandbox/linux/syscall_broker/broker_file_permission.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace sandbox::syscall_broker {
 class BrokerFilePermission;
