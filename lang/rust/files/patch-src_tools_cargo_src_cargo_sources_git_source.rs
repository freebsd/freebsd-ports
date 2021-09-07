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

--- src/tools/cargo/src/cargo/sources/git/source.rs.orig	2021-09-06 18:42:51 UTC
+++ src/tools/cargo/src/cargo/sources/git/source.rs
@@ -84,6 +84,9 @@ impl<'cfg> Debug for GitSource<'cfg> {
 
 impl<'cfg> Source for GitSource<'cfg> {
     fn query(&mut self, dep: &Dependency, f: &mut dyn FnMut(Summary)) -> CargoResult<()> {
+        if std::env::var("CARGO_FREEBSD_PORTS_SKIP_GIT_UPDATE").is_ok() {
+            return Ok(());
+        }
         let src = self
             .path_source
             .as_mut()
@@ -92,6 +95,9 @@ impl<'cfg> Source for GitSource<'cfg> {
     }
 
     fn fuzzy_query(&mut self, dep: &Dependency, f: &mut dyn FnMut(Summary)) -> CargoResult<()> {
+        if std::env::var("CARGO_FREEBSD_PORTS_SKIP_GIT_UPDATE").is_ok() {
+            return Ok(());
+        }
         let src = self
             .path_source
             .as_mut()
@@ -112,6 +118,9 @@ impl<'cfg> Source for GitSource<'cfg> {
     }
 
     fn update(&mut self) -> CargoResult<()> {
+        if std::env::var("CARGO_FREEBSD_PORTS_SKIP_GIT_UPDATE").is_ok() {
+            return Ok(());
+        }
         let git_path = self.config.git_path();
         let git_path = self.config.assert_package_cache_locked(&git_path);
         let db_path = git_path.join("db").join(&self.ident);
