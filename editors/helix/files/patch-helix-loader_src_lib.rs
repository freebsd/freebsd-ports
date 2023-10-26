--- helix-loader/src/lib.rs.orig	2023-10-25 16:37:27 UTC
+++ helix-loader/src/lib.rs
@@ -90,6 +90,8 @@ fn prioritize_runtime_dirs() -> Vec<PathBuf> {
         rt_dirs.push(dir.into());
     }
 
+    rt_dirs.push(std::path::PathBuf::from("%%DATADIR%%").join(RT_DIR));
+
     // fallback to location of the executable being run
     // canonicalize the path in case the executable is symlinked
     let exe_rt_dir = std::env::current_exe()
