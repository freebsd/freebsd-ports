--- src/main.rs.orig	2025-07-13 01:04:13 UTC
+++ src/main.rs
@@ -23,6 +23,8 @@ fn determine_static_files_path() -> std::path::PathBuf
     
     // List of possible static file locations in order of preference
     let possible_paths = vec![
+        // FreeBSD
+        PathBuf::from("%%WWWDIR%%"),
         // Docker/production environment - frontend build copied to /app/frontend/dist
         current_dir.join("frontend/dist"),
         // Development environment - frontend build in local frontend/dist
