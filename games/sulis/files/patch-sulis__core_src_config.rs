--- sulis_core/src/config.rs.orig	2024-12-15 06:48:25 UTC
+++ sulis_core/src/config.rs
@@ -352,7 +352,7 @@ const CONFIG_FILENAME: &str = "config.yml";
 }
 
 const CONFIG_FILENAME: &str = "config.yml";
-pub const CONFIG_BASE: &str = "config.sample.yml";
+pub const CONFIG_BASE: &str = "%%ETCDIR%%/config.yml";
 
 pub fn create_dir_and_warn(path: &Path) {
     if let Err(e) = fs::create_dir_all(path) {
