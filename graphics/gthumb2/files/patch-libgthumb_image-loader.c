--- libgthumb/image-loader.c.orig	Mon Mar  3 15:45:30 2003
+++ libgthumb/image-loader.c	Mon Mar  3 15:45:32 2003
@@ -534,8 +534,10 @@
 		image_loader_sync_pixbuf (il);
 	
 	priv->done_func = NULL;
-	if (done_func != NULL)
+	if (done_func != NULL) {
 		(*done_func) (priv->done_func_data);
+		return;
+        }
 	
 	if (! priv->emit_signal)
 		return;
