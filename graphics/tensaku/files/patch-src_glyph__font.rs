--- src/glyph_font.rs.orig	2026-09-05 20:50:03 UTC
+++ src/glyph_font.rs
@@ -214,7 +214,7 @@ fn ensure_file(path: &Path, bytes: &[u8]) -> std::io::
 // libfontconfig is already linked transitively through GTK/Pango and is
 // the same instance Pango resolves families against, so faces added
 // here are visible to the tooltip markup.
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 unsafe extern "C" {
     #[link_name = "FcConfigAppFontAddFile"]
     fn fc_config_app_font_add_file(
@@ -223,7 +223,7 @@ unsafe extern "C" {
     ) -> std::os::raw::c_int;
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 fn register_app_font(path: &Path) -> bool {
     use std::ffi::CString;
     use std::os::unix::ffi::OsStrExt;
@@ -237,7 +237,7 @@ fn register_app_font(path: &Path) -> bool {
     unsafe { fc_config_app_font_add_file(std::ptr::null_mut(), c_path.as_ptr().cast()) != 0 }
 }
 
-#[cfg(not(target_os = "linux"))]
+#[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
 fn register_app_font(_path: &Path) -> bool {
     false
 }
