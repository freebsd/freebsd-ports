--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2022-11-30 08:12:58 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.cc
@@ -19,8 +19,10 @@
 #include "build/chromeos_buildflags.h"
 #include "content/common/zygote/zygote_commands_linux.h"
 #include "content/common/zygote/zygote_communication_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "content/common/zygote/zygote_handle_impl_linux.h"
 #include "content/public/common/zygote/zygote_handle.h"
+#endif
 #include "sandbox/linux/services/credentials.h"
 #include "sandbox/linux/services/namespace_sandbox.h"
 #include "sandbox/linux/suid/client/setuid_sandbox_host.h"
@@ -38,6 +40,7 @@ namespace content {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 // Receive a fixed message on fd and return the sender's PID.
 // Returns true if the message received matches the expected message.
 bool ReceiveFixedMessage(int fd,
@@ -59,6 +62,7 @@ bool ReceiveFixedMessage(int fd,
     return false;
   return true;
 }
+#endif
 
 }  // namespace
 
@@ -68,9 +72,13 @@ ZygoteHost* ZygoteHost::GetInstance() {
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
@@ -83,6 +91,7 @@ ZygoteHostImpl* ZygoteHostImpl::GetInstance() {
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !BUILDFLAG(IS_BSD)
   if (command_line.HasSwitch(sandbox::policy::switches::kNoSandbox)) {
     return;
   }
@@ -133,6 +142,7 @@ void ZygoteHostImpl::Init(const base::CommandLine& com
            "you can try using --"
         << sandbox::policy::switches::kNoSandbox << ".";
   }
+#endif
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -157,6 +167,7 @@ pid_t ZygoteHostImpl::LaunchZygote(
     base::CommandLine* cmd_line,
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
+#if !BUILDFLAG(IS_BSD)
   int fds[2];
   CHECK_EQ(0, socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds));
   CHECK(base::UnixDomainSocket::EnableReceiveProcessId(fds[0]));
@@ -224,9 +235,12 @@ pid_t ZygoteHostImpl::LaunchZygote(
 
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
