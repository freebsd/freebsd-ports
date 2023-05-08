Check for OFFLINE_BUILD and OFFLINE_YARNCACHE environment variables to run yarn
in offline mode with a custom offline cache.

If so, run yarn once more to run the "post-install" target of the package
"patch-package" to patch the "protobufjs" package.  Otherwise the editor of
Anki will not work as no symbols and fields are shown.

--- build/runner/src/yarn.rs.orig	2023-05-01 01:47:30 UTC
+++ build/runner/src/yarn.rs
@@ -1,6 +1,8 @@
 // Copyright: Ankitects Pty Ltd and contributors
 // License: GNU AGPL, version 3 or later; http://www.gnu.org/licenses/agpl.html
 
+use std::env;
+
 use std::path::Path;
 use std::process::Command;
 
@@ -17,7 +19,15 @@ pub fn setup_yarn(args: YarnArgs) {
 pub fn setup_yarn(args: YarnArgs) {
     link_node_modules();
 
-    run_silent(Command::new(&args.yarn_bin).arg("install"));
+    if env::var("OFFLINE_BUILD").is_ok() && env::var("OFFLINE_YARNCACHE").is_ok() {
+        println!("OFFLINE_BUILD and OFFLINE_YARNCACHE are set");
+        println!("Running yarn with --offline, --cache-folder and --ignore-scripts.");
+        let offline_yarn_cache = env!("OFFLINE_YARNCACHE");
+        run_silent(Command::new(&args.yarn_bin).arg("install").arg("--offline").arg("--cache-folder").arg(offline_yarn_cache).arg("--ignore-scripts"));
+        run_silent(Command::new(&args.yarn_bin).arg("add").arg("--offline").arg("--cache-folder").arg(offline_yarn_cache).arg("patch-package"));
+    } else {
+        run_silent(Command::new(&args.yarn_bin).arg("install"));
+    }
 
     std::fs::write(args.stamp, b"").unwrap();
 }
