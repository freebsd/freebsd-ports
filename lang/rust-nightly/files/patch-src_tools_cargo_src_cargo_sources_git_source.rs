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

--- src/tools/cargo/src/cargo/sources/git/source.rs.orig	2021-10-04 20:59:57 UTC
+++ src/tools/cargo/src/cargo/sources/git/source.rs
@@ -205,6 +205,9 @@ impl<'cfg> Source for GitSource<'cfg> {
         kind: QueryKind,
         f: &mut dyn FnMut(IndexSummary),
     ) -> Poll<CargoResult<()>> {
+        if std::env::var("CARGO_FREEBSD_PORTS_SKIP_GIT_UPDATE").is_ok() {
+            return Poll::Ready(Ok(()));
+        }
         if let Some(src) = self.path_source.as_mut() {
             src.query(dep, kind, f)
         } else {
@@ -228,6 +231,10 @@ impl<'cfg> Source for GitSource<'cfg> {
         if self.path_source.is_some() {
             self.mark_used(None)?;
             return Ok(());
+        }
+
+        if std::env::var("CARGO_FREEBSD_PORTS_SKIP_GIT_UPDATE").is_ok() {
+             return Ok(());
         }
 
         let git_fs = self.config.git_path();
