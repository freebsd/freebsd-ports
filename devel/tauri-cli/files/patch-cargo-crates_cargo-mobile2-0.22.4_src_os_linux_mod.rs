-- Allow the command_path helper to be used on FreeBSD since cargo-mobile2
-- reuses the Linux OS module on FreeBSD.
--- cargo-crates/cargo-mobile2-0.22.4/src/os/linux/mod.rs.orig	2026-07-30 17:28:10 UTC
+++ cargo-crates/cargo-mobile2-0.22.4/src/os/linux/mod.rs
@@ -169,7 +169,7 @@ pub fn open_file_with(
 
 // We use "sh" in order to access "command -v", as that is a bultin command on sh.
 // Linux does not require a binary "command" in path, so this seems the way to go.
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub fn command_path(name: &str) -> std::io::Result<std::process::Output> {
     duct::cmd("sh", ["-c", format!("command -v {name}").as_str()]).run()
 }
