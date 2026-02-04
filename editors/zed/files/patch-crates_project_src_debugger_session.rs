--- crates/project/src/debugger/session.rs.orig	2026-01-29 22:37:26 UTC
+++ crates/project/src/debugger/session.rs
@@ -495,6 +495,8 @@ impl RunningMode {
                     }
                 })?;
 
+                #[cfg(not(target_os = "freebsd"))]
+                {
                 if should_send_exception_breakpoints {
                     _ = session.update(cx, |this, _| {
                         filters.retain(|filter| {
@@ -517,6 +519,7 @@ impl RunningMode {
                     this.send_exception_breakpoints(filters, supports_exception_filters)
                         .await
                         .ok();
+                }
                 }
 
                 if configuration_done_supported {
