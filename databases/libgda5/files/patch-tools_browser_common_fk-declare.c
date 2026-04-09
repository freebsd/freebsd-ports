--- tools/browser/common/fk-declare.c.orig	2020-11-08 20:23:20 UTC
+++ tools/browser/common/fk-declare.c
@@ -403,7 +403,7 @@ fk_declare_new (GtkWindow *parent, GdaMetaStruct *mstr
 	g_free (str);
 
 	decl = FK_DECLARE (wid);
-	decl->priv->mstruct = g_object_ref ((GObject*) mstruct);
+	decl->priv->mstruct = (GdaMetaStruct *) g_object_ref ((GObject*) mstruct);
 	decl->priv->mtable = table;
 
 	create_internal_layout (decl);
