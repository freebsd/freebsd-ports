--- crates/remote_server/src/main.rs.orig	2025-11-15 04:26:31 UTC
+++ crates/remote_server/src/main.rs
@@ -36,6 +36,7 @@ fn main() -> anyhow::Result<()> {
         return Ok(());
     }
 
+    #[cfg(not(target_os = "freebsd"))]
     if let Some(socket) = &cli.crash_handler {
         crashes::crash_server(socket.as_path());
         return Ok(());
