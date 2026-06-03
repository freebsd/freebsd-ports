--- libgda-ui/gdaui-raw-form.c.orig	2020-11-08 20:23:19 UTC
+++ libgda-ui/gdaui-raw-form.c
@@ -383,7 +383,7 @@ gdaui_raw_form_set_property (GObject *object,
 			if (!form->priv->proxy) {
 				/* first time setting */
 				if (GDA_IS_DATA_PROXY (model))
-					form->priv->proxy = g_object_ref (G_OBJECT (model));
+					form->priv->proxy = (GdaDataProxy *) g_object_ref (G_OBJECT (model));
 				else
 					form->priv->proxy = GDA_DATA_PROXY (gda_data_proxy_new (model));
 				form->priv->data_model = gda_data_proxy_get_proxied_model (form->priv->proxy);
