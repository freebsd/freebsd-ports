--- cellrendererspin.c.orig	2024-11-25 02:22:09 UTC
+++ cellrendererspin.c
@@ -158,7 +158,7 @@ gui_cell_renderer_spin_class_init (GuiCellRendererSpin
   object_class->finalize = gui_cell_renderer_spin_finalize;

   /* Override the cell renderer's edit-related methods */
-  cell_class->start_editing = gui_cell_renderer_spin_start_editing;
+  cell_class->start_editing = (GtkCellEditable *)gui_cell_renderer_spin_start_editing;
 }


