--- crates/zed/src/zed.rs.orig	2025-11-15 05:42:34 UTC
+++ crates/zed/src/zed.rs
@@ -370,6 +370,7 @@ pub fn initialize_workspace(
         if let Some(specs) = window.gpu_specs() {
             log::info!("Using GPU: {:?}", specs);
             show_software_emulation_warning_if_needed(specs.clone(), window, cx);
+            #[cfg(not(target_os = "freebsd"))]
             if let Some((crash_server, message)) = crashes::CRASH_HANDLER
                 .get()
                 .zip(bincode::serialize(&specs).ok())
