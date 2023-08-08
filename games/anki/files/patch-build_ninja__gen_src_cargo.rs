Make the cargo build for the rust library more verbose

--- build/ninja_gen/src/cargo.rs.orig	2023-04-09 12:58:05 UTC
+++ build/ninja_gen/src/cargo.rs
@@ -74,7 +74,7 @@ impl BuildAction for CargoBuild<'_> {
 
 impl BuildAction for CargoBuild<'_> {
     fn command(&self) -> &str {
-        "cargo build $release_arg $target_arg $cargo_flags $extra_args"
+        "cargo build $release_arg $target_arg $cargo_flags $extra_args --verbose --verbose"
     }
 
     fn files(&mut self, build: &mut impl FilesHandle) {
