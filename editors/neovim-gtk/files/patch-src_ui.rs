--- src/ui.rs.orig	2024-08-27 21:04:49 UTC
+++ src/ui.rs
@@ -385,7 +385,7 @@ impl Ui {
                     files_list
                         .iter()
                         .map(|f| misc::escape_filename(f))
-                        .collect::<Box<_>>()
+                        .collect::<Box<[_]>>()
                         .join(" ")
                 ));
             } else {
