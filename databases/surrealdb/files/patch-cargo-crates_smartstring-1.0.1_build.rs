-- workaround for smartstring-1.0.1 incorrectly using the rust-native 'alloc' crate

--- cargo-crates/smartstring-1.0.1/build.rs.orig	2026-10-09 00:12:02 UTC
+++ cargo-crates/smartstring-1.0.1/build.rs
@@ -7,7 +7,7 @@ fn main() {
 fn main() {
     let ac = autocfg::new();
     let has_feature = Some(true) == rustc::supports_feature("allocator_api");
-    let has_api = ac.probe_trait("alloc::alloc::Allocator");
+    let has_api = false;
     if has_feature || has_api {
         autocfg::emit("has_allocator");
     }
