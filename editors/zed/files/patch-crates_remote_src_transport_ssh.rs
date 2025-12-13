--- crates/remote/src/transport/ssh.rs.orig	2025-12-11 21:24:05 UTC
+++ crates/remote/src/transport/ssh.rs
@@ -1087,6 +1087,7 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
     let os = match os {
         "Darwin" => "macos",
         "Linux" => "linux",
+        "FreeBSD" => "freebsd",
         _ => anyhow::bail!(
             "Prebuilt remote servers are not yet available for {os:?}. See https://zed.dev/docs/remote-development"
         ),
@@ -1099,7 +1100,9 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
         || arch.starts_with("aarch64")
     {
         "aarch64"
-    } else if arch.starts_with("x86") {
+    } else if arch.starts_with("x86")
+        || arch.starts_with("amd64")
+    {
         "x86_64"
     } else {
         anyhow::bail!(
