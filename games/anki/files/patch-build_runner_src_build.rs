* Make ninja build verbose
* Make cargo build for components of the build framework (= runner) more verbose

--- build/runner/src/build.rs.orig	2026-08-25 18:50:38 UTC
+++ build/runner/src/build.rs
@@ -59,6 +59,7 @@ pub fn run_build(args: BuildArgs) {
     let start_time = Instant::now();
     let mut command = Command::new(get_ninja_command());
     command
+        .arg("-v")
         .arg("-f")
         .arg(&build_file)
         .args(ninja_args)
@@ -149,7 +150,7 @@ fn bootstrap_build() {
 
 fn bootstrap_build() {
     let status = Command::new("cargo")
-        .args(["run", "-p", "configure", "--profile", bootstrap_profile()])
+        .args(["run", "-p", "configure", "--verbose", "--profile", bootstrap_profile()])
         .status();
     assert!(status.expect("ninja").success());
 }
