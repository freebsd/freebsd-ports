--- file-modules/xsl/mrp-xsl.c.orig	Sun Sep 21 19:50:32 2003
+++ file-modules/xsl/mrp-xsl.c	Sun Sep 21 19:50:55 2003
@@ -46,11 +46,12 @@
 		      gboolean        force,
 		      GError        **error)
 {
-	g_return_val_if_fail (writer != NULL, FALSE);
         gchar          *xml_project;
         xsltStylesheet *stylesheet;
         xmlDoc         *doc;
         xmlDoc         *final_doc;
+
+	g_return_val_if_fail (writer != NULL, FALSE);
 
 	mrp_project_save_to_xml (project, &xml_project, NULL);
 
