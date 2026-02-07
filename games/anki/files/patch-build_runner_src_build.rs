* Make ninja build verbose
* Make cargo build for components of the build framework (= runner) more verbose

--- build/runner/src/build.rs.orig	2024-02-29 18:06:02 UTC
+++ build/runner/src/build.rs
@@ -57,6 +57,7 @@ pub fn run_build(args: BuildArgs) {
     let start_time = Instant::now();
     let mut command = Command::new(get_ninja_command());
     command
+        .arg("-v")
         .arg("-f")
         .arg(&build_file)
         .args(ninja_args)
@@ -150,7 +151,7 @@ fn bootstrap_build() {
 
 fn bootstrap_build() {
     let status = Command::new("cargo")
-        .args(["run", "-p", "configure"])
+        .args(["run", "-p", "configure", "--verbose"])
         .status();
     assert!(status.expect("ninja").success());
 }
