--- crates/languages/src/zig.rs.orig	2026-03-26 00:34:06 UTC
+++ crates/languages/src/zig.rs
@@ -40,6 +40,12 @@ impl ZigLspAdapter {
     const OS_NAME: &str = "linux";
 }
 
+#[cfg(target_os = "freebsd")]
+impl ZigLspAdapter {
+    const ARCHIVE_TYPE: AssetKind = AssetKind::TarGz;
+    const OS_NAME: &str = "linux";
+}
+
 #[cfg(target_os = "windows")]
 impl ZigLspAdapter {
     const ARCHIVE_TYPE: AssetKind = AssetKind::Zip;
