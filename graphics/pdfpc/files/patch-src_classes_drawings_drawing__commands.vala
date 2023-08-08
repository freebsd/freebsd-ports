--- src/classes/drawings/drawing_commands.vala.orig	2023-08-08 00:11:53 UTC
+++ src/classes/drawings/drawing_commands.vala
@@ -54,8 +54,8 @@ namespace pdfpc {
         }
 
         public void clear() {
-            this.drawing_commands = new List<DrawingCommand>();
-            this.redo_commands = new List<DrawingCommand>();
+            this.drawing_commands = new List<DrawingCommand?>();
+            this.redo_commands = new List<DrawingCommand?>();
         }
 
         public void add_line(bool is_eraser,
@@ -70,7 +70,7 @@ namespace pdfpc {
 
             // After adding a new line you can no longer redo the old
             // path.
-            this.redo_commands = new List<DrawingCommand>(); // clear
+            this.redo_commands = new List<DrawingCommand?>(); // clear
 
             bool new_path = true;
             double epsilon = 1e-4; // Less than 0.1 pixel for a 1000x1000 img
@@ -171,4 +171,3 @@ namespace pdfpc {
         }
     }
 }
-
