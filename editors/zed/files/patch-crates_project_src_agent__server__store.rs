--- crates/project/src/agent_server_store.rs.orig	2026-06-06 03:37:40 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1088,6 +1088,10 @@ impl ExternalAgentServer for LocalRegistryArchiveAgent
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
