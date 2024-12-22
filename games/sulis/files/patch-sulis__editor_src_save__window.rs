--- sulis_editor/src/save_window.rs.orig	2024-12-15 12:29:05 UTC
+++ sulis_editor/src/save_window.rs
@@ -67,7 +67,7 @@ impl WidgetKind for SaveWindow {
             .add_callback(Callback::new(Rc::new(move |widget, _kind| {
                 let (parent, _) = Widget::parent::<SaveWindow>(widget);
                 let filename_prefix = format!(
-                    "../{}/{}/areas/",
+                    "{}/{}/areas/",
                     Config::resources_config().campaigns_directory,
                     Config::editor_config().module
                 );
