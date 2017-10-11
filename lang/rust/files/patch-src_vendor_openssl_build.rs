--- src/vendor/openssl/build.rs.orig	2017-10-10 20:21:28 UTC
+++ src/vendor/openssl/build.rs
@@ -20,6 +20,10 @@ fn main() {
         println!("cargo:rustc-cfg=libressl");
     }
 
+    if let Ok(v) = env::var("DEP_OPENSSL_LIBRESSL_VERSION") {
+        println!("cargo:rustc-cfg=libressl{}", v);
+    }
+
     if let Ok(vars) = env::var("DEP_OPENSSL_CONF") {
         for var in vars.split(",") {
             println!("cargo:rustc-cfg=osslconf=\"{}\"", var);
