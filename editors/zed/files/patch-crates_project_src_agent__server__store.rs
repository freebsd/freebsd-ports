--- crates/project/src/agent_server_store.rs.orig	2026-06-10 17:21:09 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1176,6 +1176,10 @@ impl ExternalAgentServer for LocalRegistryArchiveAgent
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
