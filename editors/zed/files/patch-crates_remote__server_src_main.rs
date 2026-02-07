--- crates/remote_server/src/main.rs.orig	2026-01-29 22:37:26 UTC
+++ crates/remote_server/src/main.rs
@@ -29,6 +29,7 @@ fn main() -> anyhow::Result<()> {
         return Ok(());
     }
 
+    #[cfg(not(target_os = "freebsd"))]
     if let Some(socket) = &cli.crash_handler {
         crashes::crash_server(socket.as_path());
         return Ok(());
