--- sulis_editor/src/load_window.rs.orig	2024-12-15 12:23:30 UTC
+++ sulis_editor/src/load_window.rs
@@ -67,7 +67,7 @@ impl WidgetKind for LoadWindow {
 
         let campaigns_dir = Config::resources_config().campaigns_directory;
         let dir_str = format!(
-            "../{}/{}/areas/",
+            "{}/{}/areas/",
             campaigns_dir,
             Config::editor_config().module
         );
