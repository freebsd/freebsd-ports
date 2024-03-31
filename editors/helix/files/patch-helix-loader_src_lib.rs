--- helix-loader/src/lib.rs.orig	2024-03-31 01:10:06 UTC
+++ helix-loader/src/lib.rs
@@ -65,6 +65,8 @@ fn prioritize_runtime_dirs() -> Vec<PathBuf> {
         rt_dirs.push(dir.into());
     }
 
+    rt_dirs.push(std::path::PathBuf::from("%%DATADIR%%").join(RT_DIR));
+
     // fallback to location of the executable being run
     // canonicalize the path in case the executable is symlinked
     let exe_rt_dir = std::env::current_exe()
