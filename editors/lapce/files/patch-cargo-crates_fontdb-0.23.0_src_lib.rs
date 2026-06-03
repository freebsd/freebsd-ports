--- cargo-crates/fontdb-0.23.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/fontdb-0.23.0/src/lib.rs
@@ -485,7 +485,7 @@ impl Database {
     fn load_no_fontconfig(&mut self) {
         let mut seen = Default::default();
         self.load_fonts_dir_impl("/usr/share/fonts/".as_ref(), &mut seen);
-        self.load_fonts_dir_impl("/usr/local/share/fonts/".as_ref(), &mut seen);
+        self.load_fonts_dir_impl("%%PREFIX%%/share/fonts/".as_ref(), &mut seen);
 
         if let Ok(ref home) = std::env::var("HOME") {
             let home_path = std::path::Path::new(home);
@@ -527,9 +527,9 @@ impl Database {
             };
 
             if read_global {
-                let _ = fontconfig.merge_config(Path::new("/etc/fonts/local.conf"));
+                let _ = fontconfig.merge_config(Path::new("%%PREFIX%%/etc/fonts/local.conf"));
             }
-            let _ = fontconfig.merge_config(Path::new("/etc/fonts/fonts.conf"));
+            let _ = fontconfig.merge_config(Path::new("%%PREFIX%%/etc/fonts/fonts.conf"));
         }
 
         for fontconfig_parser::Alias {
