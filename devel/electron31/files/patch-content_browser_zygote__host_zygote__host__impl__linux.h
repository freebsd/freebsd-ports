--- content/browser/zygote_host/zygote_host_impl_linux.h.orig	2023-02-01 18:43:19 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.h
@@ -47,12 +47,14 @@ class CONTENT_EXPORT ZygoteHostImpl : public ZygoteHos
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !BUILDFLAG(IS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
 #if BUILDFLAG(IS_CHROMEOS)
   void ReinitializeLogging(uint32_t logging_dest,
                            base::PlatformFile log_file_fd) override;
 #endif  // BUILDFLAG(IS_CHROMEOS)
+#endif
 
   bool HasZygote() { return !zygote_pids_.empty(); }
 
@@ -67,9 +69,11 @@ class CONTENT_EXPORT ZygoteHostImpl : public ZygoteHos
 
   int renderer_sandbox_status_;
 
+#if !BUILDFLAG(IS_BSD)
   bool use_namespace_sandbox_;
   bool use_suid_sandbox_;
   bool use_suid_sandbox_for_adj_oom_score_;
+#endif
   std::string sandbox_binary_;
 
   // This lock protects the |zygote_pids_| set.
