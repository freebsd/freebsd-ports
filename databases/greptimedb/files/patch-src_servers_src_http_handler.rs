--- src/servers/src/http/handler.rs.orig	2026-04-09 01:25:00 UTC
+++ src/servers/src/http/handler.rs
@@ -401,7 +401,7 @@ pub async fn metrics(
     // We do not need to explicitly collect process-related data.
     // But ProcessCollector only support on linux.
 
-    #[cfg(not(windows))]
+    #[cfg(not(any(windows, target_os = "freebsd")))]
     if let Some(c) = crate::metrics::jemalloc::JEMALLOC_COLLECTOR.as_ref()
         && let Err(e) = c.update()
     {
