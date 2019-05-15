--- vendor/openssl/build.rs.orig	2019-05-13 21:50:34 UTC
+++ vendor/openssl/build.rs
@@ -46,12 +46,20 @@ fn main() {
             println!("cargo:rustc-cfg=libressl270");
         }
 
+        if version >= 0x2_07_01_00_0 {
+            println!("cargo:rustc-cfg=libressl271");
+        }
+
         if version >= 0x2_07_03_00_0 {
             println!("cargo:rustc-cfg=libressl273");
         }
 
         if version >= 0x2_08_00_00_0 {
             println!("cargo:rustc-cfg=libressl280");
+        }
+
+        if version >= 0x2_09_01_00_0 {
+            println!("cargo:rustc-cfg=libressl291");
         }
     }
 }
