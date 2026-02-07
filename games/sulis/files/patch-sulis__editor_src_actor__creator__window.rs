--- sulis_editor/src/actor_creator_window.rs.orig	2024-12-15 12:24:55 UTC
+++ sulis_editor/src/actor_creator_window.rs
@@ -77,7 +77,7 @@ impl ActorCreatorWindow {
         let resources_config = Config::resources_config();
 
         let filename = format!(
-            "../{}/{}/actors/{}.yml",
+            "{}/{}/actors/{}.yml",
             resources_config.campaigns_directory,
             Config::editor_config().module,
             id
