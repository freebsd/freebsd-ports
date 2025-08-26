--- build/rust/allocator/lib.rs.orig	2025-08-11 20:33:34 UTC
+++ build/rust/allocator/lib.rs
@@ -86,9 +86,8 @@ mod both_allocators {
     /// As part of rustc's contract for using `#[global_allocator]` without
     /// rustc-generated shims we must define this symbol, since we are opting in
     /// to unstable functionality. See https://github.com/rust-lang/rust/issues/123015
-    #[no_mangle]
-    #[linkage = "weak"]
-    static __rust_no_alloc_shim_is_unstable: u8 = 0;
+    #[rustc_std_internal_symbol]
+    fn __rust_no_alloc_shim_is_unstable_v2() {}
 
     // Mangle the symbol name as rustc expects.
     #[rustc_std_internal_symbol]
