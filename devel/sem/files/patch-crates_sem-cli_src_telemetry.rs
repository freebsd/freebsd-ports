--- crates/sem-cli/src/telemetry.rs.orig	2026-06-14 20:05:28 UTC
+++ crates/sem-cli/src/telemetry.rs
@@ -37,10 +37,14 @@ fn telemetry_disabled() -> bool {
 }
 
 fn telemetry_disabled() -> bool {
-    let set = |var: &str| std::env::var(var).is_ok_and(|v| !v.is_empty() && v != "0");
-    set("SEM_NO_TELEMETRY") || set("DO_NOT_TRACK") || is_development_build()
+    !telemetry_enabled()
 }
 
+fn telemetry_enabled() -> bool {
+    let disabled = |var: &str| std::env::var(var).is_ok_and(|v| !v.is_empty() && v == "0");
+    !is_development_build() && (disabled("SEM_NO_TELEMETRY") || disabled("DO_NOT_TRACK"))
+}
+
 /// True when this binary is a development build rather than a real install,
 /// so our own work never pollutes usage data. Catches: debug builds
 /// (`cargo run`, `cargo test`), and any binary run straight out of a Cargo
@@ -119,7 +123,7 @@ pub fn record(command: &str) {
 /// Record one command invocation. Cheap (two small file ops); never blocks
 /// on the network. Call once per CLI run before dispatch.
 pub fn record(command: &str) {
-    if telemetry_disabled() {
+    if telemetry_enabled() {
         return;
     }
 
@@ -129,7 +133,7 @@ pub fn record(command: &str) {
     }
     if !state.notice_shown {
         eprintln!(
-            "sem collects anonymous usage data (command names only, never code or repo names). Set SEM_NO_TELEMETRY=1 to disable."
+            "If enabled, sem collects anonymous usage data (command names only, never code or repo names). Set SEM_NO_TELEMETRY=0 to enable telemetry."
         );
         state.notice_shown = true;
         save_state(&state);
