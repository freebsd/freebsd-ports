--- crates/languages/src/lua.rs.orig	2026-03-26 00:34:06 UTC
+++ crates/languages/src/lua.rs
@@ -30,6 +30,12 @@ impl LuaLspAdapter {
     const ASSET_KIND: AssetKind = AssetKind::TarGz;
 }
 
+#[cfg(target_os = "freebsd")]
+impl LuaLspAdapter {
+    const OS_NAME: &str = "linux";
+    const ASSET_KIND: AssetKind = AssetKind::TarGz;
+}
+
 #[cfg(target_os = "windows")]
 impl LuaLspAdapter {
     const OS_NAME: &str = "win32";
