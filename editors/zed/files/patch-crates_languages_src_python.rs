--- crates/languages/src/python.rs.orig	2026-11-02 11:27:47 UTC
+++ crates/languages/src/python.rs
@@ -2740,6 +2740,12 @@ impl PyreflyLspAdapter {
     const ARCH_SERVER_NAME: &str = "linux";
 }
 
+#[cfg(target_os = "freebsd")]
+impl PyreflyLspAdapter {
+    const GITHUB_ASSET_KIND: AssetKind = AssetKind::TarGz;
+    const ARCH_SERVER_NAME: &str = "freebsd";
+}
+
 #[cfg(target_os = "windows")]
 impl PyreflyLspAdapter {
     const GITHUB_ASSET_KIND: AssetKind = AssetKind::Zip;
