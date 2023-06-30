LibreSSL >3.7.1 isn't explicitly supported.

Index: vendor/openssl-sys/build/main.rs
--- vendor/openssl-sys/build/main.rs.orig
+++ vendor/openssl-sys/build/main.rs
@@ -284,7 +284,7 @@ See rust-openssl documentation for more information:
             (3, 6, _) => ('3', '6', 'x'),
             (3, 7, 0) => ('3', '7', '0'),
             (3, 7, 1) => ('3', '7', '1'),
-            _ => version_error(),
+            _ => ('3', '7', '1'),
         };
 
         println!("cargo:libressl=true");
