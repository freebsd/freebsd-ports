--- cellrenderertextish.c.orig	2016-07-05 18:32:44 UTC
+++ cellrenderertextish.c
@@ -154,7 +154,7 @@ static gchar** _vala_array_dup1 (gchar** self, int len
 CellRendererTextish* cell_renderer_textish_new_with_items (gchar** items, int items_length1);
 CellRendererTextish* cell_renderer_textish_construct_with_items (GType object_type, gchar** items, int items_length1);
 static gchar** _vala_array_dup1 (gchar** self, int length);
-static GtkCellEditable* cell_renderer_textish_real_start_editing (GtkCellRenderer* base, GdkEvent* event, GtkWidget* widget, const gchar* path, GdkRectangle* background_area, GdkRectangle* cell_area, GtkCellRendererState flags);
+static GtkCellEditable* cell_renderer_textish_real_start_editing (GtkCellRenderer* base, GdkEvent* event, GtkWidget* widget, const gchar* path, const GdkRectangle* background_area, const GdkRectangle* cell_area, GtkCellRendererState flags);
 CellEditableAccel* cell_editable_accel_new (CellRendererTextish* parent, const gchar* path, GtkWidget* widget);
 CellEditableAccel* cell_editable_accel_construct (GType object_type, CellRendererTextish* parent, const gchar* path, GtkWidget* widget);
 GType cell_editable_accel_get_type (void) G_GNUC_CONST;
@@ -282,7 +282,7 @@ static gpointer _g_object_ref0 (gpointer self) {
 }
 
 
-static GtkCellEditable* cell_renderer_textish_real_start_editing (GtkCellRenderer* base, GdkEvent* event, GtkWidget* widget, const gchar* path, GdkRectangle* background_area, GdkRectangle* cell_area, GtkCellRendererState flags) {
+static GtkCellEditable* cell_renderer_textish_real_start_editing (GtkCellRenderer* base, GdkEvent* event, GtkWidget* widget, const gchar* path, const GdkRectangle* background_area, const GdkRectangle* cell_area, GtkCellRendererState flags) {
 	CellRendererTextish * self;
 	GtkCellEditable* result = NULL;
 	gboolean _tmp0_ = FALSE;
