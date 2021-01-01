--- services/service_manager/zygote/host/zygote_host_impl_linux.cc.orig	2019-09-10 10:42:44 UTC
+++ services/service_manager/zygote/host/zygote_host_impl_linux.cc
@@ -72,6 +72,7 @@ ZygoteHostImpl* ZygoteHostImpl::GetInstance() {
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !defined(OS_BSD)
   if (command_line.HasSwitch(service_manager::switches::kNoSandbox)) {
     return;
   }
@@ -122,6 +123,7 @@ void ZygoteHostImpl::Init(const base::CommandLine& com
            "you can try using --"
         << service_manager::switches::kNoSandbox << ".";
   }
+#endif
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -146,6 +148,7 @@ pid_t ZygoteHostImpl::LaunchZygote(
     base::CommandLine* cmd_line,
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
+#if !defined(OS_BSD)
   int fds[2];
   CHECK_EQ(0, socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds));
   CHECK(base::UnixDomainSocket::EnableReceiveProcessId(fds[0]));
@@ -210,9 +213,12 @@ pid_t ZygoteHostImpl::LaunchZygote(
 
   AddZygotePid(pid);
   return pid;
+#else
+  return 0;
+#endif
 }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 void ZygoteHostImpl::AdjustRendererOOMScore(base::ProcessHandle pid,
                                             int score) {
   // 1) You can't change the oom_score_adj of a non-dumpable process
