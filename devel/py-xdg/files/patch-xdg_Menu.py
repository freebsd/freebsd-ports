--- xdg/Menu.py.orig	2008-06-02 05:29:42.000000000 -0400
+++ xdg/Menu.py	2008-08-16 14:59:55.000000000 -0400
@@ -495,6 +495,9 @@ def parse(filename=None):
         filename = __getFileName("applications.menu")
 
     if not filename:
+	filename = __getFilename("gnome-applications.menu")
+
+    if not filename:
         raise ParsingError('File not found', "/etc/xdg/menus/applications.menu")
 
     # check if it is a .menu file
