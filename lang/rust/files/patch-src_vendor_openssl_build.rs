--- src/vendor/openssl/build.rs.orig	2018-09-11 04:49:47 UTC
+++ src/vendor/openssl/build.rs
@@ -49,5 +49,9 @@ fn main() {
         if version >= 0x2_07_03_00_0 {
             println!("cargo:rustc-cfg=libressl273");
         }
+
+        if version >= 0x2_08_00_00_0 {
+            println!("cargo:rustc-cfg=libressl280");
+        }
     }
 }
