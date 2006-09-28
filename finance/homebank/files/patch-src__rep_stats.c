--- src/rep_stats.c.orig	Tue Sep 26 17:45:38 2006
+++ src/rep_stats.c	Tue Sep 26 17:46:16 2006
@@ -171,6 +171,7 @@
 void statistic_toggle_detail(GtkWidget *widget, gpointer user_data);
 void statistic_toggle_legend(GtkWidget *widget, gpointer user_data);
 void statistic_toggle_minor(GtkWidget *widget, gpointer user_data);
+void statistic_toggle_rate(GtkWidget *widget, gpointer user_data);
 GtkWidget *create_list_statistic(void);
 
 gint stat_list_compare_func (GtkTreeModel *model, GtkTreeIter  *a, GtkTreeIter  *b, gpointer      userdata);
