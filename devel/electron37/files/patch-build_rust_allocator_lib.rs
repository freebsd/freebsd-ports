--- build/rust/allocator/lib.rs.orig	2025-08-11 20:33:34 UTC
+++ build/rust/allocator/lib.rs
@@ -90,7 +90,18 @@ mod both_allocators {
     #[linkage = "weak"]
     static __rust_no_alloc_shim_is_unstable: u8 = 0;
 
+    #[rustc_std_internal_symbol]
+    #[linkage = "weak"]
+    fn __rust_no_alloc_shim_is_unstable_v2() {}
+
+    #[rustc_std_internal_symbol]
+    #[linkage = "weak"]
+    fn __rust_alloc_error_handler_should_panic_v2() -> u8 {
+        0
+    }
+
     // Mangle the symbol name as rustc expects.
+    // TODO(crbug.com/440481922): Remove this after rolling past https://github.com/rust-lang/rust/pull/143387
     #[rustc_std_internal_symbol]
     #[allow(non_upper_case_globals)]
     #[linkage = "weak"]
