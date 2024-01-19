--- cargo-crates/fontdb-0.16.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/fontdb-0.16.0/src/lib.rs
@@ -444,8 +444,10 @@ impl Database {
 
             if read_global {
                 let _ = fontconfig.merge_config(Path::new("/etc/fonts/local.conf"));
+                let _ = fontconfig.merge_config(Path::new("/usr/local/etc/fonts/local.conf"));
             }
             let _ = fontconfig.merge_config(Path::new("/etc/fonts/fonts.conf"));
+            let _ = fontconfig.merge_config(Path::new("/usr/local/etc/fonts/fonts.conf"));
         }
 
         for fontconfig_parser::Alias {
