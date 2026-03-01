--- src/infra/export/dot.rs.orig	2026-02-25 15:32:51 UTC
+++ src/infra/export/dot.rs
@@ -62,7 +62,7 @@ impl ViewerLauncher for SystemViewerLauncher {
                 .spawn()
                 .map_err(ViewerError::LaunchFailed)?;
         }
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "freebsd", target_os = "linux"))]
         {
             Command::new("xdg-open")
                 .arg(path)
