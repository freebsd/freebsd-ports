--- crates/project/src/agent_server_store.rs.orig	2026-01-29 22:37:26 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1918,6 +1918,8 @@ fn get_platform_info() -> Option<(&'static str, &'stat
         "pc-windows-msvc"
     } else if cfg!(target_os = "linux") {
         "unknown-linux-gnu"
+    } else if cfg!(target_os = "freebsd") {
+        "unknown-freebsd"
     } else {
         return None;
     };
@@ -1999,6 +2001,8 @@ impl ExternalAgentServer for LocalExtensionArchiveAgen
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
@@ -2201,6 +2205,8 @@ impl ExternalAgentServer for LocalRegistryArchiveAgent
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
