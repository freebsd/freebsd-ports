--- helix-core/src/lib.rs.orig	2021-09-18 05:55:12 UTC
+++ helix-core/src/lib.rs
@@ -73,6 +73,8 @@ pub fn runtime_dir() -> std::path::PathBuf {
         // this is the directory of the crate being run by cargo, we need the workspace path so we take the parent
         return std::path::PathBuf::from(dir).parent().unwrap().join(RT_DIR);
     }
+        
+    return std::path::PathBuf::from("%%DATADIR%%").join(RT_DIR);
 
     // fallback to location of the executable being run
     std::env::current_exe()
