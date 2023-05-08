Add "SyncSubmoduleOffline" stub function that is used if the OFFLINE_BUILD
environment variable is set.

--- build/ninja_gen/src/git.rs.orig	2023-03-31 02:32:25 UTC
+++ build/ninja_gen/src/git.rs
@@ -11,6 +11,10 @@ pub struct SyncSubmodule {
     pub path: &'static str,
 }
 
+pub struct SyncSubmoduleOffline {
+    pub path: &'static str,
+}
+
 impl BuildAction for SyncSubmodule {
     fn command(&self) -> &str {
         "git -c protocol.file.allow=always submodule update --init $path"
@@ -33,6 +37,17 @@ impl BuildAction for SyncSubmodule {
 
     fn concurrency_pool(&self) -> Option<&'static str> {
         Some("git")
+    }
+}
+
+impl BuildAction for SyncSubmoduleOffline {
+    fn command(&self) -> &str {
+        "echo Runnung SyncSubmoduleOffline stub function for $path"
+    }
+
+    fn files(&mut self, build: &mut impl build::FilesHandle) {
+        build.add_variable("path", self.path);
+        build.add_output_stamp(format!("git/{}", self.path));
     }
 }
 
