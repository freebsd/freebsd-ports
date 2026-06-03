--- crates/languages/src/erlang.rs.orig	2026-03-26 00:34:06 UTC
+++ crates/languages/src/erlang.rs
@@ -90,6 +90,12 @@ impl ElpAdapter {
     const OS_TARGET: &str = "unknown-linux-gnu";
 }
 
+#[cfg(target_os = "freebsd")]
+impl ElpAdapter {
+    const OS_NAME: &str = "linux";
+    const OS_TARGET: &str = "unknown-linux-gnu";
+}
+
 impl ElpAdapter {
     const SERVER_NAME: LanguageServerName = LanguageServerName::new_static("elp");
     const OTP_VERSION: &str = "28";
