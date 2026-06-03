--- content/browser/child_thread_type_switcher_linux.h.orig	2025-04-22 20:15:27 UTC
+++ content/browser/child_thread_type_switcher_linux.h
@@ -36,7 +36,7 @@ class ChildThreadTypeSwitcher : public mojom::ThreadTy
   void SetPid(base::ProcessId child_pid);
 
   // mojom::ThreadTypeSwitcher:
-  void SetThreadType(int32_t ns_tid, base::ThreadType thread_type) override;
+  void SetThreadType(uint64_t ns_tid, base::ThreadType thread_type) override;
 
  private:
   base::ProcessId child_pid_ = base::kNullProcessHandle;
