--- libgda/gda-query-target.c~	Mon Jan 23 00:18:37 2006
+++ libgda/gda-query-target.c	Sun Mar 26 10:03:52 2006
@@ -732,8 +732,8 @@
 	g_free (str);
 	
 	if (target->priv->entity_ref) {
-		str = NULL;
 		GdaObject *base = gda_object_ref_get_ref_object (target->priv->entity_ref);
+		str = NULL;
 
 		if (base) {
 			str = gda_xml_storage_get_xml_id (GDA_XML_STORAGE (base));
