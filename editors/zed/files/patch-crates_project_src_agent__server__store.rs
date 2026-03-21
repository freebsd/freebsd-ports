--- crates/project/src/agent_server_store.rs.orig	2026-03-11 14:31:09 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1046,6 +1046,8 @@ impl ExternalAgentServer for LocalExtensionArchiveAgen
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
@@ -1240,6 +1242,8 @@ impl ExternalAgentServer for LocalRegistryArchiveAgent
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
