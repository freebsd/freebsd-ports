--- crates/remote/src/transport.rs.orig	2026-01-14 15:30:09 UTC
+++ crates/remote/src/transport.rs
@@ -28,6 +28,7 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
     let os = match os {
         "Darwin" => RemoteOs::MacOs,
         "Linux" => RemoteOs::Linux,
+        "FreeBSD" => RemoteOs::FreeBSD,
         _ => anyhow::bail!(
             "Prebuilt remote servers are not yet available for {os:?}. See https://zed.dev/docs/remote-development"
         ),
@@ -40,7 +41,7 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
         || arch.starts_with("aarch64")
     {
         RemoteArch::Aarch64
-    } else if arch.starts_with("x86") {
+    } else if arch.starts_with("x86") || arch.starts_with("amd64") {
         RemoteArch::X86_64
     } else {
         anyhow::bail!(
