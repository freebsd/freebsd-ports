--- src/rep_budget.c.orig	Sat Jun 24 20:49:04 2006
+++ src/rep_budget.c	Sat Jun 24 20:49:20 2006
@@ -135,6 +135,7 @@
 void repbudget_toggle_detail(GtkWidget *widget, gpointer user_data);
 void repbudget_detail(GtkWidget *widget, gpointer user_data);
 void repbudget_compute(GtkWidget *widget, gpointer user_data);
+void repbudget_update_detail(GtkWidget *widget, gpointer user_data);
 void repbudget_update_total(GtkWidget *widget, gpointer user_data);
 void repbudget_action(GtkWidget *widget, gpointer user_data);
 void repbudget_sensitive(GtkWidget *widget, gpointer user_data);
