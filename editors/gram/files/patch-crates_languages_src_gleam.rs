--- crates/languages/src/gleam.rs.orig	2026-03-26 00:34:06 UTC
+++ crates/languages/src/gleam.rs
@@ -32,6 +32,12 @@ impl GleamLspAdapter {
     const OS_NAME: &str = "unknown-linux-musl";
 }
 
+#[cfg(target_os = "freebsd")]
+impl GleamLspAdapter {
+    const GITHUB_ASSET_KIND: AssetKind = AssetKind::TarGz;
+    const OS_NAME: &str = "unknown-linux-musl";
+}
+
 #[cfg(target_os = "windows")]
 impl GleamLspAdapter {
     const GITHUB_ASSET_KIND: AssetKind = AssetKind::Zip;
