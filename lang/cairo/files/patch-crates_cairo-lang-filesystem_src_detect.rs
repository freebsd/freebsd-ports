--- crates/cairo-lang-filesystem/src/detect.rs.orig	2024-08-02 16:35:10 UTC
+++ crates/cairo-lang-filesystem/src/detect.rs
@@ -8,6 +8,8 @@ pub fn detect_corelib() -> Option<PathBuf> {
             for _ in 0..$up {
                 path.pop();
             }
+            path.push("lib");
+            path.push("cairo-lang");
             path.push("corelib");
             path.push("src");
             if path.exists() {
