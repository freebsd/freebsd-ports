--- src/menucmd.c.orig	Thu Sep  1 18:33:25 2005
+++ src/menucmd.c	Fri Oct 21 11:50:56 2005
@@ -344,6 +344,7 @@
 cut_project(GtkWidget *w, gpointer data)
 {
 	GttProject *cut_prj;
+	GttProject *prj;
 
 	/* Do NOT cut unless the ctree window actually has focus.
 	 * Otherwise, it will lead to cutting mayhem.
@@ -365,7 +366,7 @@
 
 	/* Update various subsystems */
 	/* Set the notes are to whatever the new focus project is. */
-	GttProject *prj = ctree_get_focus_project (global_ptw);
+	prj = ctree_get_focus_project (global_ptw);
 	notes_area_set_project (global_na, prj);
 
 	menu_set_states();      /* To enable paste menu item */
@@ -425,6 +426,7 @@
 copy_project(GtkWidget *w, gpointer data)
 {
 	GttProject *prj;
+	GList *n;
 	prj = ctree_get_focus_project (global_ptw);
 
 	if (!prj) return;
@@ -435,7 +437,7 @@
 	 * the list of earlier cut projects.  We do this in order
 	 * to allow the most recently copied project to be pasted
 	 * multiple times.  */
-	GList *n = cutted_project_list;
+	n = cutted_project_list;
 	for (n=cutted_project_list; n; n=n->next)
 	{
 		GttProject *p = n->data;
@@ -520,12 +522,12 @@
 menu_howto_edit_times (GtkWidget *w,gpointer data)
 {
 	char * msg;
+	GtkWidget *mb;
 
 	msg = _("To edit the timer interval for this project,\n"
 	        "open the Activity window and click on a link.\n"
 	        "This will bring up a menu of time editing options.\n");
 
-	GtkWidget *mb;
 	mb = gtk_message_dialog_new (NULL,
 	         GTK_DIALOG_MODAL,
 	         GTK_MESSAGE_INFO,
