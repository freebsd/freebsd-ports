--- libmergeant/mg-form.c.orig	Thu Aug 12 22:24:32 2004
+++ libmergeant/mg-form.c	Thu Aug 12 22:24:48 2004
@@ -586,6 +586,7 @@
 {
 	PangoAttrList *attrs = NULL;
 	PangoAttribute *att;
+	GSList *list;
 
 	if (show_mark) {
 		attrs = pango_attr_list_new ();
@@ -595,7 +596,7 @@
 		pango_attr_list_insert (attrs, att);
 	}
 
-	GSList *list = form->priv->not_null_labels;
+	list = form->priv->not_null_labels;
 	while (list) {
 		gtk_label_set_attributes (GTK_LABEL (list->data), attrs);
 		list = g_slist_next (list);
