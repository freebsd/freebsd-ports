- workaround for https://github.com/vlaci/pyperscan/issues/38

--- hyperscan-sys/build.rs.orig	2023-12-15 06:47:41 UTC
+++ hyperscan-sys/build.rs
@@ -118,6 +118,8 @@ fn main() {
         println!("cargo:rustc-link-lib=hs");
     }
 
+    config = config.clang_arg(format!("-I{}/include", env::var("FREEBSD_LOCALBASE").unwrap()));
+    config = config.clang_arg(format!("-L{}/lib", env::var("FREEBSD_LOCALBASE").unwrap()));
     config
         .generate()
         .expect("Unable to generate bindings")
