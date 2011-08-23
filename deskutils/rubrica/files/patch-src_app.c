--- src/app.c.orig	2011-08-12 15:55:03.000000000 +0200
+++ src/app.c	2011-08-12 15:55:26.000000000 +0200
@@ -1269,8 +1269,7 @@ rubrica_app_init(RubricaApp* self)
   self->priv->cutted      = NULL;
   self->priv->notify      = notify_notification_new("Rubrica Addressbook",
 						    NULL, 
-						    "info",
-						    NULL);
+						    "info");
   self->priv->show_card   = TRUE;
 
   g_object_set(self->priv->notebook, "homogeneous", FALSE, NULL);
