https://github.com/sfackler/rust-openssl/commit/9fd7584a8416

--- src/vendor/openssl-sys/build/main.rs.orig	2018-12-03 20:08:24 UTC
+++ src/vendor/openssl-sys/build/main.rs
@@ -1,9 +1,9 @@
 extern crate cc;
+#[cfg(feature = "vendored")]
+extern crate openssl_src;
 extern crate pkg_config;
 #[cfg(target_env = "msvc")]
 extern crate vcpkg;
-#[cfg(feature = "vendored")]
-extern crate openssl_src;
 
 use std::collections::HashSet;
 use std::env;
@@ -103,20 +103,23 @@ fn main() {
 
 #[cfg(feature = "vendored")]
 mod imp {
-	use std::path::PathBuf;
-	use openssl_src;
+    use openssl_src;
+    use std::path::PathBuf;
 
-	pub fn get_openssl(_target: &str) -> (PathBuf, PathBuf) {
-		let artifacts = openssl_src::Build::new().build();
-		(artifacts.lib_dir().to_path_buf(), artifacts.include_dir().to_path_buf())
-	}
+    pub fn get_openssl(_target: &str) -> (PathBuf, PathBuf) {
+        let artifacts = openssl_src::Build::new().build();
+        (
+            artifacts.lib_dir().to_path_buf(),
+            artifacts.include_dir().to_path_buf(),
+        )
+    }
 }
 
 #[cfg(not(feature = "vendored"))]
 mod imp {
     use pkg_config;
-    use std::path::{Path, PathBuf};
     use std::ffi::OsString;
+    use std::path::{Path, PathBuf};
     use std::process::{self, Command};
 
     use super::env;
@@ -500,6 +503,7 @@ See rust-openssl README for more information:
             (7, _) => ('7', 'x'),
             (8, 0) => ('8', '0'),
             (8, 1) => ('8', '1'),
+            (8, _) => ('8', 'x'),
             _ => version_error(),
         };
 
