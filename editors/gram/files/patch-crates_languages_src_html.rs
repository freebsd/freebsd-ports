--- crates/languages/src/html.rs.orig	2026-08-25 07:40:58 UTC
+++ crates/languages/src/html.rs
@@ -33,6 +33,12 @@ impl SuperhtmlLspAdapter {
     const OS_NAME: &str = "macos";
 }
 
+#[cfg(target_os = "freebsd")]
+impl SuperhtmlLspAdapter {
+    const GITHUB_ASSET_KIND: AssetKind = AssetKind::TarGz;
+    const OS_NAME: &str = "linux-musl";
+}
+
 #[cfg(target_os = "windows")]
 impl SuperhtmlLspAdapter {
     const GITHUB_ASSET_KIND: AssetKind = AssetKind::Zip;
