--- crates/project/src/debugger/session.rs.orig	2026-08-26 14:24:53 UTC
+++ crates/project/src/debugger/session.rs
@@ -494,6 +494,8 @@ impl RunningMode {
                     }
                 })?;
 
+                #[cfg(not(target_os = "freebsd"))]
+                {
                 if should_send_exception_breakpoints {
                     _ = session.update(cx, |this, _| {
                         filters.retain(|filter| {
@@ -516,6 +518,7 @@ impl RunningMode {
                     this.send_exception_breakpoints(filters, supports_exception_filters)
                         .await
                         .ok();
+                }
                 }
 
                 if configuration_done_supported {
