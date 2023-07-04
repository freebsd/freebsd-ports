--- crates/cairo-lang-language-server/src/lib.rs.orig	2023-07-04 19:07:27 UTC
+++ crates/cairo-lang-language-server/src/lib.rs
@@ -264,6 +264,8 @@ impl Backend {
                         let root_path: PathBuf = value.into();
 
                         let mut path = root_path.clone();
+                        path.push("lib");
+                        path.push("cairo-lang");
                         path.push("corelib");
                         path.push("src");
                         if path.exists() {
