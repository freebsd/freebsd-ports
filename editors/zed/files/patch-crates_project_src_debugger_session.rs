--- crates/project/src/debugger/session.rs.orig	2025-12-27 19:42:13 UTC
+++ crates/project/src/debugger/session.rs
@@ -496,6 +496,8 @@ impl RunningMode {
                     }
                 })?;
 
+                #[cfg(not(target_os = "freebsd"))]
+                {
                 if should_send_exception_breakpoints {
                     _ = session.update(cx, |this, _| {
                         filters.retain(|filter| {
@@ -518,6 +520,7 @@ impl RunningMode {
                     this.send_exception_breakpoints(filters, supports_exception_filters)
                         .await
                         .ok();
+                }
                 }
 
                 if configuration_done_supported {
