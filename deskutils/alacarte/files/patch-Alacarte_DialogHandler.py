--- Alacarte/DialogHandler.py.orig	Wed Jul 26 20:53:06 2006
+++ Alacarte/DialogHandler.py	Wed Jul 26 20:53:14 2006
@@ -84,7 +84,7 @@ class DialogHandler:
 		if button.icon_path:
 			dialog.set_current_folder(button.icon_path.rsplit('/', 1)[0])
 		else:
-			dialog.set_current_folder('/usr/share/icons/')
+			dialog.set_current_folder('/usr/local/share/icons/')
 		preview = gtk.VBox()
 		preview.set_spacing(8)
 		preview.set_size_request(92, 92)
