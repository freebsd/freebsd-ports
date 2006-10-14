--- xdg/Menu.py.orig	Thu Aug 11 07:37:48 2005
+++ xdg/Menu.py	Sat Sep  2 05:10:19 2006
@@ -494,6 +494,10 @@
 	if not filename:
 		filename = __getFileName("applications.menu")
 
+	# use gnome if no filename given
+	if not filename:
+		filename = __getFileName("gnome-applications.menu")
+
 	if not filename:
 		raise ParsingError('File not found', "/etc/xdg/menus/applications.menu")
 
