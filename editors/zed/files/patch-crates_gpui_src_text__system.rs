--- crates/gpui/src/text_system.rs.orig	2026-03-04 15:41:56 UTC
+++ crates/gpui/src/text_system.rs
@@ -45,11 +45,12 @@ pub const SUBPIXEL_VARIANTS_X: u8 = 4;
 pub const SUBPIXEL_VARIANTS_X: u8 = 4;
 
 /// Number of subpixel glyph variants along the Y axis.
-pub const SUBPIXEL_VARIANTS_Y: u8 = if cfg!(target_os = "windows") || cfg!(target_os = "linux") {
-    1
-} else {
-    SUBPIXEL_VARIANTS_X
-};
+pub const SUBPIXEL_VARIANTS_Y: u8 =
+    if cfg!(target_os = "windows") || cfg!(target_os = "linux") || cfg!(target_os = "freebsd") {
+        1
+    } else {
+        SUBPIXEL_VARIANTS_X
+    };
 
 /// The GPUI text rendering sub system.
 pub struct TextSystem {
