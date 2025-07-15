--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2025-03-24 20:50:14 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.cc
@@ -23,8 +23,10 @@
 #include "build/build_config.h"
 #include "content/common/zygote/zygote_commands_linux.h"
 #include "content/common/zygote/zygote_communication_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "content/common/zygote/zygote_handle_impl_linux.h"
 #include "content/public/common/zygote/zygote_handle.h"
+#endif
 #include "sandbox/linux/services/credentials.h"
 #include "sandbox/linux/services/namespace_sandbox.h"
 #include "sandbox/linux/suid/client/setuid_sandbox_host.h"
@@ -42,6 +44,7 @@ namespace {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 // Receive a fixed message on fd and return the sender's PID.
 // Returns true if the message received matches the expected message.
 bool ReceiveFixedMessage(int fd,
@@ -64,6 +67,7 @@ bool ReceiveFixedMessage(int fd,
     return false;
   return true;
 }
+#endif
 
 }  // namespace
 
@@ -73,9 +77,13 @@ ZygoteHostImpl::ZygoteHostImpl()
 }
 
 ZygoteHostImpl::ZygoteHostImpl()
+#if !BUILDFLAG(IS_BSD)
     : use_namespace_sandbox_(false),
       use_suid_sandbox_(false),
       use_suid_sandbox_for_adj_oom_score_(false),
+#else
+    :
+#endif
       sandbox_binary_(),
       zygote_pids_lock_(),
       zygote_pids_() {}
@@ -88,6 +96,7 @@ void ZygoteHostImpl::Init(const base::CommandLine& com
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !BUILDFLAG(IS_BSD)
   if (command_line.HasSwitch(sandbox::policy::switches::kNoSandbox)) {
     return;
   }
@@ -142,6 +151,7 @@ void ZygoteHostImpl::Init(const base::CommandLine& com
            "you can try using --"
         << sandbox::policy::switches::kNoSandbox << ".";
   }
+#endif
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -166,6 +176,7 @@ pid_t ZygoteHostImpl::LaunchZygote(
     base::CommandLine* cmd_line,
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
+#if !BUILDFLAG(IS_BSD)
   int fds[2];
   CHECK_EQ(0, socketpair(AF_UNIX, SOCK_SEQPACKET | SOCK_CLOEXEC, 0, fds));
   CHECK(base::UnixDomainSocket::EnableReceiveProcessId(fds[0]));
@@ -234,9 +245,12 @@ pid_t ZygoteHostImpl::LaunchZygote(
 
   AddZygotePid(pid);
   return pid;
+#else
+  return 0;
+#endif
 }
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 void ZygoteHostImpl::AdjustRendererOOMScore(base::ProcessHandle pid,
                                             int score) {
   // 1) You can't change the oom_score_adj of a non-dumpable process
