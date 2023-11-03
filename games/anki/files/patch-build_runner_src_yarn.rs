Check for OFFLINE_BUILD and OFFLINE_YARNCACHE environment variables to run yarn
in offline mode with a custom offline cache.

--- build/runner/src/yarn.rs.orig	2023-09-24 06:42:26 UTC
+++ build/runner/src/yarn.rs
@@ -1,6 +1,8 @@
 // Copyright: Ankitects Pty Ltd and contributors
 // License: GNU AGPL, version 3 or later; http://www.gnu.org/licenses/agpl.html
 
+use std::env;
+
 use std::path::Path;
 use std::process::Command;
 
@@ -17,7 +19,14 @@ pub fn setup_yarn(args: YarnArgs) {
 pub fn setup_yarn(args: YarnArgs) {
     link_node_modules();
 
-    run_command(Command::new(&args.yarn_bin).arg("install"));
+    if env::var("OFFLINE_BUILD").is_ok() && env::var("OFFLINE_YARNCACHE").is_ok() {
+        println!("OFFLINE_BUILD and OFFLINE_YARNCACHE are set");
+        println!("Running yarn with --offline, --cache-folder and --ignore-scripts.");
+        let offline_yarn_cache = env!("OFFLINE_YARNCACHE");
+        run_command(Command::new(&args.yarn_bin).arg("install").arg("--offline").arg("--cache-folder").arg(offline_yarn_cache).arg("--ignore-scripts"));
+    } else {
+        run_command(Command::new(&args.yarn_bin).arg("install"));
+    }
 
     std::fs::write(args.stamp, b"").unwrap();
 }
