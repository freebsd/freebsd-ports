--- crates/project/src/agent_server_store.rs.orig	2026-02-17 20:22:48 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1672,6 +1672,8 @@ fn get_platform_info() -> Option<(&'static str, &'stat
         "pc-windows-msvc"
     } else if cfg!(target_os = "linux") {
         "unknown-linux-gnu"
+    } else if cfg!(target_os = "freebsd") {
+        "unknown-freebsd"
     } else {
         return None;
     };
@@ -1753,6 +1755,8 @@ impl ExternalAgentServer for LocalExtensionArchiveAgen
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
@@ -1955,6 +1959,8 @@ impl ExternalAgentServer for LocalRegistryArchiveAgent
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
