--- lapce-core/src/directory.rs.orig	2025-08-30 05:01:02 UTC
+++ lapce-core/src/directory.rs
@@ -176,17 +176,7 @@ impl Directory {
     }
 
     pub fn grammars_directory() -> Option<PathBuf> {
-        if let Some(dir) = Self::data_local_directory() {
-            let dir = dir.join("grammars");
-            if !dir.exists() {
-                if let Err(err) = std::fs::create_dir(&dir) {
-                    tracing::error!("{:?}", err);
-                }
-            }
-
-            Some(dir)
-        } else {
-            None
-        }
+         let mut dir = PathBuf::from(r"%%DATADIR%%/tree-sitter-grammars");
+         Some(dir)
     }
 }
