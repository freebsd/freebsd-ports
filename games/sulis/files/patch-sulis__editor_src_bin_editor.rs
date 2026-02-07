--- sulis_editor/src/bin/editor.rs.orig	2024-12-15 11:20:56 UTC
+++ sulis_editor/src/bin/editor.rs
@@ -36,11 +36,11 @@ fn main() {
     let resources_config = Config::resources_config();
 
     let dir = resources_config.directory;
-    let data_dir = format!("../{dir}");
+    let data_dir = format!("{dir}");
 
     let campaigns_dir = resources_config.campaigns_directory;
     let module = Config::editor_config().module;
-    let module_dir = format!("../{campaigns_dir}/{module}");
+    let module_dir = format!("{campaigns_dir}/{module}");
 
     let dirs = vec![data_dir, module_dir];
     info!("Reading resources from {:?}", dirs);
