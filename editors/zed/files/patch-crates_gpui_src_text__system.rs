--- crates/gpui/src/text_system.rs.orig	2025-11-15 06:24:54 UTC
+++ crates/gpui/src/text_system.rs
@@ -44,7 +44,7 @@ pub(crate) const SUBPIXEL_VARIANTS_Y: u8 =
 pub(crate) const SUBPIXEL_VARIANTS_X: u8 = 4;
 
 pub(crate) const SUBPIXEL_VARIANTS_Y: u8 =
-    if cfg!(target_os = "windows") || cfg!(target_os = "linux") {
+    if cfg!(target_os = "windows") || cfg!(target_os = "linux") || cfg!(target_os = "freebsd") {
         1
     } else {
         SUBPIXEL_VARIANTS_X
