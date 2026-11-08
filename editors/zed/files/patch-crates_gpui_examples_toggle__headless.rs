--- crates/gpui/examples/toggle_headless.rs.orig	2026-10-18 07:35:04 UTC
+++ crates/gpui/examples/toggle_headless.rs
@@ -119,7 +119,7 @@ fn open_window(todos: &Entity<Todos>, cx: &mut App) ->
 
 /// Builds the environment for `open`: the given `NAME=value` pairs, or this process's
 /// environment when none are given.
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 fn display_environment(arguments: &str) -> anyhow::Result<GraphicalEnvironment> {
     if arguments.trim().is_empty() {
         return Ok(GraphicalEnvironment::detect());
@@ -154,7 +154,7 @@ fn display_environment(arguments: &str) -> anyhow::Res
 }
 
 /// Builds the environment for `open`, which carries nothing on this platform.
-#[cfg(not(any(target_os = "linux", target_os = "windows", target_family = "wasm")))]
+#[cfg(not(any(target_os = "linux", target_os = "freebsd", target_os = "windows", target_family = "wasm")))]
 fn display_environment(_arguments: &str) -> anyhow::Result<GraphicalEnvironment> {
     Ok(GraphicalEnvironment::detect())
 }
@@ -204,13 +204,13 @@ fn handle_command(
     Ok(None)
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 const USAGE: &str = "commands: ls | create [message] | open [DISPLAY=… WAYLAND_DISPLAY=… XDG_RUNTIME_DIR=… XDG_ACTIVATION_TOKEN=…] | close | quit";
 
 #[cfg(target_os = "windows")]
 const USAGE: &str = "commands: ls | create [message] | open [SESSION=…] | close | quit";
 
-#[cfg(not(any(target_os = "linux", target_os = "windows", target_family = "wasm")))]
+#[cfg(not(any(target_os = "linux", target_os = "freebsd", target_os = "windows", target_family = "wasm")))]
 const USAGE: &str = "commands: ls | create [message] | open | close | quit";
 
 #[cfg(not(target_family = "wasm"))]
@@ -247,9 +247,9 @@ fn main() {
 
 #[cfg(not(target_family = "wasm"))]
 fn main() {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     let application = gpui_platform::linux(gpui::WindowingModes::all());
-    #[cfg(not(target_os = "linux"))]
+    #[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
     let application = gpui_platform::application();
     application
         .with_windowing(WindowingRequest::Headless)
