* Make ninja build verbose
* Respect NINJA_STATUS if already set
* Make cargo build for components of the build framework (= runner) more verbose
* Check for OFFLINE_BUILD environment variable to prevent repo sync

--- build/runner/src/build.rs.orig	2023-05-01 01:47:30 UTC
+++ build/runner/src/build.rs
@@ -58,10 +58,10 @@ pub fn run_build(args: BuildArgs) {
     let start_time = Instant::now();
     let mut command = Command::new("ninja");
     command
+        .arg("-v")
         .arg("-f")
         .arg(&build_file)
         .args(ninja_args)
-        .env("NINJA_STATUS", "[%f/%t; %r active; %es] ")
         .env("PATH", path)
         .env(
             "MYPY_CACHE_DIR",
@@ -76,6 +76,10 @@ pub fn run_build(args: BuildArgs) {
         // Updating svelte-check or its deps will likely remove the need for it.
         .env("NODE_OPTIONS", "--no-experimental-fetch");
 
+        if env::var("NINJA_STATUS").is_err() {
+            command.env("NINJA_STATUS", "[%f/%t; %r active; %es] ");
+        }
+
     // run build
     let mut status = command.status().expect("ninja not installed");
     if !status.success() && Instant::now().duration_since(start_time).as_secs() < 3 {
@@ -147,7 +151,7 @@ fn bootstrap_build() {
 
 fn bootstrap_build() {
     let status = Command::new("cargo")
-        .args(["run", "-p", "configure"])
+        .args(["run", "-p", "configure", "--verbose"])
         .status();
     assert!(status.expect("ninja").success());
 }
@@ -155,7 +159,7 @@ fn maybe_update_buildhash(build_root: &Utf8Path) {
 fn maybe_update_buildhash(build_root: &Utf8Path) {
     // only updated on release builds
     let path = build_root.join("buildhash");
-    if env::var("RELEASE").is_ok() || !path.exists() {
+    if (env::var("RELEASE").is_ok() && env::var("OFFLINE_BUILD").is_err()) || !path.exists() {
         write_if_changed(&path, &get_buildhash())
     }
 }
