--- crates/remote/src/transport.rs.orig	2026-01-08 00:39:18 UTC
+++ crates/remote/src/transport.rs
@@ -28,6 +28,7 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
     let os = match os {
         "Darwin" => "macos",
         "Linux" => "linux",
+        "FreeBSD" => "freebsd",
         _ => anyhow::bail!(
             "Prebuilt remote servers are not yet available for {os:?}. See https://zed.dev/docs/remote-development"
         ),
@@ -40,7 +41,9 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
         || arch.starts_with("aarch64")
     {
         "aarch64"
-    } else if arch.starts_with("x86") {
+    } else if arch.starts_with("x86")
+    	|| arch.starts_with("amd64")
+    {
         "x86_64"
     } else {
         anyhow::bail!(
