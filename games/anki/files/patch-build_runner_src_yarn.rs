Yarn v2 or later uses different parameters to enable the offline mode and to
prevent scripts from running.

--- build/runner/src/yarn.rs.orig	2026-08-05 14:40:46 UTC
+++ build/runner/src/yarn.rs
@@ -18,7 +18,7 @@ pub fn setup_yarn(args: YarnArgs) {
 pub fn setup_yarn(args: YarnArgs) {
     link_node_modules();
 
-    if env::var("OFFLINE_BUILD").is_ok() {
+    if env::var("OFFLINE_BUILD").is_ok() && env::var("PREINSTALLED_YARN").is_err() {
         println!("OFFLINE_BUILD is set");
         println!("Running yarn with '--offline' and '--ignore-scripts'.");
         run_command(
