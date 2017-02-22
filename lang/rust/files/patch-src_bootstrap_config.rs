--- src/bootstrap/config.rs.orig	2017-02-09 01:37:48 UTC
+++ src/bootstrap/config.rs
@@ -85,10 +85,10 @@ pub struct Config {
     pub quiet_tests: bool,
     // Fallback musl-root for all targets
     pub musl_root: Option<PathBuf>,
-    pub prefix: Option<String>,
-    pub docdir: Option<String>,
-    pub libdir: Option<String>,
-    pub mandir: Option<String>,
+    pub prefix: Option<PathBuf>,
+    pub docdir: Option<PathBuf>,
+    pub libdir: Option<PathBuf>,
+    pub mandir: Option<PathBuf>,
     pub codegen_tests: bool,
     pub nodejs: Option<PathBuf>,
     pub gdb: Option<PathBuf>,
@@ -443,16 +443,16 @@ impl Config {
                     self.channel = value.to_string();
                 }
                 "CFG_PREFIX" => {
-                    self.prefix = Some(value.to_string());
+                    self.prefix = Some(PathBuf::from(value));
                 }
                 "CFG_DOCDIR" => {
-                    self.docdir = Some(value.to_string());
+                    self.docdir = Some(PathBuf::from(value));
                 }
                 "CFG_LIBDIR" => {
-                    self.libdir = Some(value.to_string());
+                    self.libdir = Some(PathBuf::from(value));
                 }
                 "CFG_MANDIR" => {
-                    self.mandir = Some(value.to_string());
+                    self.mandir = Some(PathBuf::from(value));
                 }
                 "CFG_LLVM_ROOT" if value.len() > 0 => {
                     let target = self.target_config.entry(self.build.clone())
