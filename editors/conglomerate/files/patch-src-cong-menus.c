--- src/cong-menus.c.orig	Tue Jun 24 19:33:54 2003
+++ src/cong-menus.c	Thu Jun 26 10:37:40 2003
@@ -261,6 +261,9 @@
 	CongDialogCategory *dtd_category;
 	gchar *filename, *path;
 
+	struct _xmlDtd  *extSubset;	/* the document external subset */
+	struct _xmlDtd  *intSubset;	/* the document internal subset */
+
 	g_return_val_if_fail(doc, NULL);
 
 	xml_doc = cong_document_get_xml(doc);
@@ -327,9 +330,6 @@
 	if (xml_doc->intSubset) {
 	} else {
 	}
-
-	struct _xmlDtd  *extSubset;	/* the document external subset */
-	struct _xmlDtd  *intSubset;	/* the document internal subset */
 
 #if 1
 	notebook = GTK_NOTEBOOK(gtk_notebook_new());
