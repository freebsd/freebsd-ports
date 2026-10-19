-- Newer nightly: AuditCommand::exec returns Result<Infallible>, so the
-- trailing Ok(()) is unreachable and the workspace denies warnings.

--- src/runtime/cli/mod.rs.orig	2026-10-04 00:00:00 UTC
+++ src/runtime/cli/mod.rs	2026-10-04 00:00:00 UTC
@@ -1558,8 +1558,7 @@
     #[inline(never)]
     fn exec_audit(log: &mut bun_ast::Log) -> CmdResult {
         let ctx = init(Tag::AuditCommand, log)?;
-        super::audit_command::AuditCommand::exec(ctx)?;
-        Ok(())
+        match super::audit_command::AuditCommand::exec(ctx)? {}
     }
 
     #[cold]
