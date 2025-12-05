--- cargo-crates/openssl-sys-0.9.61/build/main.rs.orig2021-01-01 00:00:00 UTC
+++ cargo-crates/openssl-sys-0.9.61/build/main.rs
@@ -243,7 +243,10 @@
         let openssl_version = openssl_version.unwrap();
         println!("cargo:version_number={:x}", openssl_version);
 
-        if openssl_version >= 0x1_01_02_00_0 {
+        if openssl_version >= 0x3_00_00_00_0 {
+            println!("cargo:version=300");
+            Version::Openssl11x
+        } else if openssl_version >= 0x1_01_02_00_0 {
             version_error()
         } else if openssl_version >= 0x1_01_01_00_0 {
             println!("cargo:version=111");
