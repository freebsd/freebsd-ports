--- src/planner-gantt-row.c.orig	Fri Jul  9 01:21:33 2004
+++ src/planner-gantt-row.c	Fri Jul  9 01:22:10 2004
@@ -1489,6 +1489,9 @@
 	gboolean                  summary;
 	MrpTaskType               type;
 	gchar                    *message;
+	PlannerTaskTree   *tree;
+	GtkTreePath       *path;
+	GtkTreeSelection  *selection;
 	
 	row = PLANNER_GANTT_ROW (item);
 	priv = row->priv;
@@ -1931,9 +1934,6 @@
 		gnome_canvas_item_ungrab (item, event->button.time);
 		
 		/* Select the clicked on task in the treeview */
-		PlannerTaskTree   *tree;
-		GtkTreePath       *path;
-		GtkTreeSelection  *selection;
 		
 		chart = g_object_get_data (G_OBJECT (item->canvas), "chart");
 		tree = planner_gantt_chart_get_view (chart);
