--- crates/remote/src/transport.rs.orig	2026-07-01 15:07:44 UTC
+++ crates/remote/src/transport.rs
@@ -32,6 +32,7 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
     let os = match os {
         "Darwin" => RemoteOs::MacOs,
         "Linux" => RemoteOs::Linux,
+        "FreeBSD" => RemoteOs::FreeBSD,
         _ => anyhow::bail!(
             "Prebuilt remote servers are not yet available for {os:?}. See https://zed.dev/docs/remote-development"
         ),
@@ -44,7 +45,7 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
         || arch.starts_with("aarch64")
     {
         RemoteArch::Aarch64
-    } else if arch.starts_with("x86") {
+    } else if arch.starts_with("x86") || arch.starts_with("amd64") {
         RemoteArch::X86_64
     } else {
         anyhow::bail!(
@@ -66,6 +67,7 @@ pub(crate) fn os_version_command(os: RemoteOs) -> (&'s
         RemoteOs::MacOs => ("sw_vers", &["-productVersion"]),
         // Prints e.g. "Microsoft Windows [Version 10.0.19045.5011]".
         RemoteOs::Windows => ("cmd.exe", &["/c", "ver"]),
+        RemoteOs::FreeBSD => ("cat", &["/var/run/os-release"]),
     }
 }
 
@@ -82,7 +84,7 @@ pub(crate) fn parse_os_version(os: RemoteOs, output: &
         return None;
     }
     match os {
-        RemoteOs::Linux => util::parse_os_release(output),
+        RemoteOs::Linux | RemoteOs::FreeBSD => util::parse_os_release(output),
         RemoteOs::MacOs => {
             // `sw_vers -productVersion` prints a single version line.
             output
