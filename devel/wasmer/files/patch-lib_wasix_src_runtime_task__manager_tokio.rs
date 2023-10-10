--- lib/wasix/src/runtime/task_manager/tokio.rs.orig	2023-10-04 17:50:14 UTC
+++ lib/wasix/src/runtime/task_manager/tokio.rs
@@ -58,7 +58,7 @@ impl TokioTaskManager {
         let concurrency = std::thread::available_parallelism()
             .unwrap_or(NonZeroUsize::new(1).unwrap())
             .get();
-        let max_threads = 200usize.max(concurrency * 100);
+        let max_threads = concurrency;
 
         Self {
             rt: rt.into(),
