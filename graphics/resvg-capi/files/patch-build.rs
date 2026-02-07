-- add SONAME

--- build.rs.orig	1970-01-01 00:00:00 UTC
+++ build.rs
@@ -0,0 +1,3 @@
+fn main() {
+	println!("cargo:rustc-cdylib-link-arg=-Wl,-soname,libresvg.so");
+}
