--- src/vendor/openssl-sys/build.rs.orig	2017-10-09 21:52:49 UTC
+++ src/vendor/openssl-sys/build.rs
@@ -307,8 +307,14 @@ fn validate_headers(include_dirs: &[PathBuf]) -> Versi
 #include <openssl/opensslv.h>
 #include <openssl/opensslconf.h>
 
-#if LIBRESSL_VERSION_NUMBER >= 0x20601000
+#if LIBRESSL_VERSION_NUMBER >= 0x20604000
 RUST_LIBRESSL_NEW
+#elif LIBRESSL_VERSION_NUMBER >= 0x20603000
+RUST_LIBRESSL_263
+#elif LIBRESSL_VERSION_NUMBER >= 0x20602000
+RUST_LIBRESSL_262
+#elif LIBRESSL_VERSION_NUMBER >= 0x20601000
+RUST_LIBRESSL_261
 #elif LIBRESSL_VERSION_NUMBER >= 0x20600000
 RUST_LIBRESSL_260
 #elif LIBRESSL_VERSION_NUMBER >= 0x20506000
@@ -403,42 +409,70 @@ See rust-openssl README for more information:
         println!("cargo:rustc-cfg=libressl");
         println!("cargo:rustc-cfg=libressl250");
         println!("cargo:libressl=true");
+        println!("cargo:libressl_version=250");
         println!("cargo:version=101");
         Version::Libressl
     } else if expanded.contains("RUST_LIBRESSL_251") {
         println!("cargo:rustc-cfg=libressl");
         println!("cargo:rustc-cfg=libressl251");
         println!("cargo:libressl=true");
+        println!("cargo:libressl_version=251");
         println!("cargo:version=101");
         Version::Libressl
     } else if expanded.contains("RUST_LIBRESSL_252") {
         println!("cargo:rustc-cfg=libressl");
         println!("cargo:rustc-cfg=libressl252");
         println!("cargo:libressl=true");
+        println!("cargo:libressl_version=252");
         println!("cargo:version=101");
         Version::Libressl
     } else if expanded.contains("RUST_LIBRESSL_253") {
         println!("cargo:rustc-cfg=libressl");
         println!("cargo:rustc-cfg=libressl253");
         println!("cargo:libressl=true");
+        println!("cargo:libressl_version=253");
         println!("cargo:version=101");
         Version::Libressl
     } else if expanded.contains("RUST_LIBRESSL_254") {
         println!("cargo:rustc-cfg=libressl");
         println!("cargo:rustc-cfg=libressl254");
         println!("cargo:libressl=true");
+        println!("cargo:libressl_version=254");
         println!("cargo:version=101");
         Version::Libressl
     } else if expanded.contains("RUST_LIBRESSL_255") {
         println!("cargo:rustc-cfg=libressl");
         println!("cargo:rustc-cfg=libressl255");
         println!("cargo:libressl=true");
+        println!("cargo:libressl_version=255");
         println!("cargo:version=101");
         Version::Libressl
     } else if expanded.contains("RUST_LIBRESSL_260") {
         println!("cargo:rustc-cfg=libressl");
         println!("cargo:rustc-cfg=libressl260");
         println!("cargo:libressl=true");
+        println!("cargo:libressl_version=260");
+        println!("cargo:version=101");
+        Version::Libressl
+    } else if expanded.contains("RUST_LIBRESSL_261") {
+        println!("cargo:rustc-cfg=libressl");
+        println!("cargo:rustc-cfg=libressl261");
+        println!("cargo:libressl=true");
+        println!("cargo:libressl_version=261");
+        println!("cargo:version=101");
+        Version::Libressl
+    } else if expanded.contains("RUST_LIBRESSL_262") {
+        println!("cargo:rustc-cfg=libressl");
+        println!("cargo:rustc-cfg=libressl262");
+        println!("cargo:libressl=true");
+        println!("cargo:libressl_version=262");
+        println!("cargo:version=101");
+        Version::Libressl
+    } else if expanded.contains("RUST_LIBRESSL_263") {
+        println!("cargo:rustc-cfg=libressl");
+        println!("cargo:rustc-cfg=libressl263");
+        println!("cargo:libressl=true");
+        println!("cargo:libressl_version=263");
         println!("cargo:version=101");
         Version::Libressl
     } else if expanded.contains("RUST_OPENSSL_110F") {
