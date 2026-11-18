--- crates/project/src/agent_server_store.rs.orig	2026-11-11 16:34:27 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1182,6 +1182,10 @@ impl ExternalAgentServer for LocalRegistryArchiveAgent
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
