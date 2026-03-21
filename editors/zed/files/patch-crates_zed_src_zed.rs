--- crates/zed/src/zed.rs.orig	2026-03-11 14:31:09 UTC
+++ crates/zed/src/zed.rs
@@ -422,6 +422,7 @@ pub fn initialize_workspace(
         if let Some(specs) = window.gpu_specs() {
             log::info!("Using GPU: {:?}", specs);
             show_software_emulation_warning_if_needed(specs.clone(), window, cx);
+            #[cfg(not(target_os = "freebsd"))]
             if let Some((crash_server, message)) = crashes::CRASH_HANDLER
                 .get()
                 .zip(bincode::serialize(&specs).ok())
