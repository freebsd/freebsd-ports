--- src/git/remote_ops.rs.orig	2026-10-14 17:30:38 UTC
+++ src/git/remote_ops.rs
@@ -689,14 +689,18 @@ pub fn clone_repository(
 
         stream_git_progress(child, Some(url), on_progress)?;
 
-        rustix::fs::renameat_with(
+        #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+        let moved = rustix::fs::renameat_with(
             rustix::fs::CWD,
             repository,
             rustix::fs::CWD,
             destination,
             rustix::fs::RenameFlags::NOREPLACE,
-        )
-        .map_err(|error| format!("Failed to move cloned repository to '{}': {error}", destination.display()))
+        );
+        #[cfg(not(any(target_os = "linux", target_os = "android", target_os = "macos")))]
+        let moved = std::fs::rename(repository, destination);
+
+        moved.map_err(|error| format!("Failed to move cloned repository to '{}': {error}", destination.display()))
     })();
 
     let staging_path = staging.path().to_path_buf();
