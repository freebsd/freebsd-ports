--- crates/remote_server/src/main.rs.orig	2026-01-14 15:30:09 UTC
+++ crates/remote_server/src/main.rs
@@ -28,6 +28,7 @@ fn main() -> anyhow::Result<()> {
         return Ok(());
     }
 
+    #[cfg(not(target_os = "freebsd"))]
     if let Some(socket) = &cli.crash_handler {
         crashes::crash_server(socket.as_path());
         return Ok(());
