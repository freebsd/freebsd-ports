--- plugins/gtkui/ddbcellrenderertextmultiline.c.orig	2016-06-19 11:26:18 UTC
+++ plugins/gtkui/ddbcellrenderertextmultiline.c
@@ -30,7 +30,13 @@
 #include "support.h"
 #include "ddbcellrenderertextmultiline.h"
 
+#if GTK_CHECK_VERSION(3,0,0)
+#define GTK3_CONST const
+#else
+#define GTK3_CONST
+#endif
 
+
 #define _g_free0(var) (var = (g_free (var), NULL))
 
 #define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
@@ -70,7 +76,7 @@ static gboolean ddb_cell_renderer_text_multiline_gtk_c
 };
 static void ddb_cell_renderer_text_multiline_gtk_cell_renderer_text_editing_done (DdbCellEditableTextView* entry, DdbCellRendererTextMultiline* _self_);
 static gboolean ddb_cell_renderer_text_multiline_gtk_cell_renderer_focus_out_event (DdbCellEditableTextView* entry, GdkEvent* event, DdbCellRendererTextMultiline* _self_);
-static GtkCellEditable* ddb_cell_renderer_text_multiline_real_start_editing (GtkCellRenderer* base, GdkEvent* event, GtkWidget* widget, const gchar* path, GdkRectangle* background_area, GdkRectangle* cell_area, GtkCellRendererState flags);
+static GtkCellEditable* ddb_cell_renderer_text_multiline_real_start_editing (GtkCellRenderer* base, GdkEvent* event, GtkWidget* widget, const gchar* path, GTK3_CONST GdkRectangle* background_area, GTK3_CONST GdkRectangle* cell_area, GtkCellRendererState flags);
 DdbCellRendererTextMultiline* ddb_cell_renderer_text_multiline_new (void);
 DdbCellRendererTextMultiline* ddb_cell_renderer_text_multiline_construct (GType object_type);
 static void ddb_cell_renderer_text_multiline_finalize (GObject* obj);
@@ -409,7 +415,7 @@ ddb_cell_renderer_text_multiline_populate_popup (GtkEn
             G_CALLBACK (ddb_cell_renderer_text_multiline_popup_unmap), data);
 }
 
-static GtkCellEditable* ddb_cell_renderer_text_multiline_real_start_editing (GtkCellRenderer* base, GdkEvent* event, GtkWidget* widget, const gchar* path, GdkRectangle* background_area, GdkRectangle* cell_area, GtkCellRendererState flags) {
+static GtkCellEditable* ddb_cell_renderer_text_multiline_real_start_editing (GtkCellRenderer* base, GdkEvent* event, GtkWidget* widget, const gchar* path, GTK3_CONST GdkRectangle* background_area, GTK3_CONST GdkRectangle* cell_area, GtkCellRendererState flags) {
 	DdbCellRendererTextMultiline * self;
 	GtkCellEditable* result = NULL;
 	gboolean _tmp0_ = FALSE;
