--- cargo-crates/fontdb-0.16.2/src/lib.rs.orig	2025-06-28 19:11:51 UTC
+++ cargo-crates/fontdb-0.16.2/src/lib.rs
@@ -404,7 +404,7 @@ impl Database {
             #[cfg(not(feature = "fontconfig"))]
             {
                 self.load_fonts_dir("/usr/share/fonts/");
-                self.load_fonts_dir("/usr/local/share/fonts/");
+                self.load_fonts_dir("%%PREFIX%%/share/fonts/");
 
                 if let Ok(ref home) = std::env::var("HOME") {
                     let home_path = std::path::Path::new(home);
@@ -449,8 +449,10 @@ impl Database {
 
             if read_global {
                 let _ = fontconfig.merge_config(Path::new("/etc/fonts/local.conf"));
+                let _ = fontconfig.merge_config(Path::new("%%PREFIX%%/etc/fonts/local.conf"));
             }
             let _ = fontconfig.merge_config(Path::new("/etc/fonts/fonts.conf"));
+            let _ = fontconfig.merge_config(Path::new("%%PREFIX%%/etc/fonts/fonts.conf"));
         }
 
         for fontconfig_parser::Alias {
