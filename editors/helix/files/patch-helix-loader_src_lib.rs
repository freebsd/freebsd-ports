--- helix-loader/src/lib.rs.orig	2022-12-07 02:54:50 UTC
+++ helix-loader/src/lib.rs
@@ -41,6 +41,8 @@ pub fn runtime_dir() -> PathBuf {
         return conf_dir;
     }
 
+    return std::path::PathBuf::from("%%DATADIR%%").join(RT_DIR);
+
     // fallback to location of the executable being run
     // canonicalize the path in case the executable is symlinked
     std::env::current_exe()
