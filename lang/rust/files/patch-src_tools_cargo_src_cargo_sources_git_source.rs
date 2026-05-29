We run cargo update during USES=cargo ports builds to update specific
crates and patch Cargo.lock for us.  For normal crates this is based
on what's available in the vendor dir.  For Git sources this pulls
new changes from the net instead even if we replace the source with
a static path in a patch section in the config file.  Add a hack
to skip this.

This is for experimentation to solve [1].  For this to maybe be
useful for USES=cargo, the patch-in-config feature also needs to
be stabilized first.  It will be available in Rust 1.56.

[1] https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=256581
--- src/tools/cargo/src/cargo/sources/git/source.rs.orig	2026-04-11 13:43:17 UTC
+++ src/tools/cargo/src/cargo/sources/git/source.rs
@@ -254,6 +254,10 @@ impl<'gctx> GitSource<'gctx> {
             return Ok(());
         }
 
+        if std::env::var("CARGO_FREEBSD_PORTS_SKIP_GIT_UPDATE").is_ok() {
+            return Ok(());
+        }
+
         let git_fs = self.gctx.git_path();
         // Ignore errors creating it, in case this is a read-only filesystem:
         // perhaps the later operations can succeed anyhow.
@@ -393,6 +397,9 @@ impl<'gctx> Source for GitSource<'gctx> {
         kind: QueryKind,
         f: &mut dyn FnMut(IndexSummary),
     ) -> CargoResult<()> {
+        if std::env::var("CARGO_FREEBSD_PORTS_SKIP_GIT_UPDATE").is_ok() {
+            return Ok(())
+        }
         if self.path_source.borrow().is_none() {
             self.update()?;
         }
