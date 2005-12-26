--- src/Alacarte/GnomeDialogHandler.py.orig	Tue Oct 25 22:13:44 2005
+++ src/Alacarte/GnomeDialogHandler.py	Mon Dec 26 02:44:14 2005
@@ -212,7 +212,10 @@
 			)
 		commandEntry.gtk_entry().set_completion(self.completion)
 		iconButton = self.tree.get_widget('eiconbutton')
-		iconButton.set_pixmap_subdir(item.iconPath)
+		if item.iconPath == None:
+			iconButton.set_pixmap_subdir('')
+		else:
+			iconButton.set_pixmap_subdir(item.iconPath)
 		termCheck = self.tree.get_widget('etermcheck')
 		originalValues = (
 			item.getKey('Name'), item.getKey('Comment'), item.getKey('Exec'),
@@ -221,7 +224,10 @@
 		nameEntry.set_text(item.getKey('Name'))
 		commentEntry.set_text(item.getKey('Comment'))
 		commandEntry.set_filename(item.getKey('Exec'))
-		iconButton.set_filename(item.iconPath)
+		if item.iconPath == None:
+			iconButton.set_filename('')
+		else:
+			iconButton.set_filename(item.iconPath)
 		if item.getKey('Terminal') == 'true':
 			termCheck.set_active(1)
 		self.setupEntry = False
