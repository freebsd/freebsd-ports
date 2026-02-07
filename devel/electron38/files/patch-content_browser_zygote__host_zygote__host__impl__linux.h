--- content/browser/zygote_host/zygote_host_impl_linux.h.orig	2025-03-24 20:50:14 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.h
@@ -46,12 +46,14 @@ class CONTENT_EXPORT ZygoteHostImpl : public ZygoteHos
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
 
@@ -66,9 +68,11 @@ class CONTENT_EXPORT ZygoteHostImpl : public ZygoteHos
 
   int renderer_sandbox_status_;
 
+#if !BUILDFLAG(IS_BSD)
   bool use_namespace_sandbox_;
   bool use_suid_sandbox_;
   bool use_suid_sandbox_for_adj_oom_score_;
+#endif
   std::string sandbox_binary_;
 
   // This lock protects the |zygote_pids_| set.
