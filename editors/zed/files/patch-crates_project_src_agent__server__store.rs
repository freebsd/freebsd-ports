--- crates/project/src/agent_server_store.rs.orig	2026-07-29 14:43:24 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1181,6 +1181,10 @@ impl ExternalAgentServer for LocalRegistryArchiveAgent
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
