--- crates/cairo-lang-filesystem/src/detect.rs.orig	2023-07-04 19:04:42 UTC
+++ crates/cairo-lang-filesystem/src/detect.rs
@@ -7,6 +7,8 @@ pub fn detect_corelib() -> Option<PathBuf> {
             for _ in 0..$up {
                 path.pop();
             }
+            path.push("lib");
+            path.push("cairo-lang");
             path.push("corelib");
             path.push("src");
             if path.exists() {
