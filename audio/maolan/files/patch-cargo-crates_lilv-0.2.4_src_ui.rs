--- cargo-crates/lilv-0.2.4/src/ui.rs.orig	2026-05-28 08:42:48 UTC
+++ cargo-crates/lilv-0.2.4/src/ui.rs
@@ -140,8 +140,8 @@ unsafe extern "C" fn supported_func<S: UISupport>(
 }
 
 unsafe extern "C" fn supported_func<S: UISupport>(
-    container_type_uri: *const i8,
-    ui_type_uri: *const i8,
+    container_type_uri: *const std::os::raw::c_char,
+    ui_type_uri: *const std::os::raw::c_char,
 ) -> u32 {
     S::supported(
         CStr::from_ptr(container_type_uri).to_str().unwrap(),
