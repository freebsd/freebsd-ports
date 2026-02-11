--- crates/project/src/agent_server_store.rs.orig	2026-02-06 04:11:05 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1690,6 +1690,8 @@ fn get_platform_info() -> Option<(&'static str, &'stat
         "pc-windows-msvc"
     } else if cfg!(target_os = "linux") {
         "unknown-linux-gnu"
+    } else if cfg!(target_os = "freebsd") {
+        "unknown-freebsd"
     } else {
         return None;
     };
@@ -1771,6 +1773,8 @@ impl ExternalAgentServer for LocalExtensionArchiveAgen
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
@@ -1973,6 +1977,8 @@ impl ExternalAgentServer for LocalRegistryArchiveAgent
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
