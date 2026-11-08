--- base/process/internal_linux.h.orig	2026-03-13 16:54:03 UTC
+++ base/process/internal_linux.h
@@ -142,6 +142,9 @@ void ForEachProcessTask(base::ProcessHandle process, L
 // arguments to the lambda.
 template <typename Lambda>
 void ForEachProcessTask(base::ProcessHandle process, Lambda&& lambda) {
+#if BUILDFLAG(IS_BSD)
+  return;
+#else
   // Iterate through the different threads tracked in /proc/<pid>/task.
   FilePath fd_path = GetProcPidDir(process).Append("task");
 
@@ -166,6 +169,7 @@ void ForEachProcessTask(base::ProcessHandle process, L
     FilePath task_path = fd_path.Append(tid_str);
     lambda(tid, task_path);
   }
+#endif
 }
 
 }  // namespace internal
