--- src/rs-batch.c.orig	2011-04-07 18:05:03 UTC
+++ src/rs-batch.c
@@ -830,7 +830,7 @@ static void
 filetype_changed(gpointer active, gpointer user_data)
 {
 	RS_QUEUE *queue = (RS_QUEUE *) user_data;
-	GType filetype = GPOINTER_TO_INT(active);
+	GType filetype = (GType)active;
 
 	if (!filetype)
 		return;
