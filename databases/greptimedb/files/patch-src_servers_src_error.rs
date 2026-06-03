--- src/servers/src/error.rs.orig	2026-04-09 01:36:45 UTC
+++ src/servers/src/error.rs
@@ -487,7 +487,7 @@ pub enum Error {
     #[snafu(display("Failed to dump pprof data"))]
     DumpPprof { source: common_pprof::error::Error },
 
-    #[cfg(not(windows))]
+    #[cfg(not(any(windows, target_os = "freebsd")))]
     #[snafu(display("Failed to update jemalloc metrics"))]
     UpdateJemallocMetrics {
         #[snafu(source)]
@@ -731,7 +731,7 @@ impl ErrorExt for Error {
 
             UnsupportedDataType { .. } => StatusCode::Unsupported,
 
-            #[cfg(not(windows))]
+            #[cfg(not(any(windows, target_os = "freebsd")))]
             UpdateJemallocMetrics { .. } => StatusCode::Internal,
 
             CollectRecordbatch { .. } => StatusCode::EngineExecuteQuery,
