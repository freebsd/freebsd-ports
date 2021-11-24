--- content/browser/zygote_host/zygote_host_impl_linux.h.orig	2021-01-07 00:36:33 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.h
@@ -42,8 +42,10 @@ class CONTENT_EXPORT ZygoteHostImpl : public ZygoteHos
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !defined(OS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
+#endif
   bool HasZygote() { return !zygote_pids_.empty(); }
 
  private:
