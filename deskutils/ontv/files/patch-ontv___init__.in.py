--- ontv/__init__.py.in.orig	Mon Jul 24 23:05:49 2006
+++ ontv/__init__.py.in	Mon Jul 24 23:06:14 2006
@@ -1,7 +1,7 @@
 NAME = 'OnTV'
 VERSION = '@VERSION@'
-SERVERS_DIR = '@prefix@/lib/bonobo/servers'
-DATA_DIR = '@prefix@/@DATADIRNAME@/ontv'
-PIXMAPS_DIR = '@prefix@/@DATADIRNAME@/pixmaps'
-UI_DIR = '@prefix@/@DATADIRNAME@/gnome-2.0/ui'
-LOCALE_DIR = '@prefix@/@DATADIRNAME@/locale'
+SERVERS_DIR = '@prefix@/libdata/bonobo/servers'
+DATA_DIR = '@prefix@/share/gnome/ontv'
+PIXMAPS_DIR = '@prefix@/share/gnome/pixmaps'
+UI_DIR = '@prefix@/share/gnome/gnome-2.0/ui'
+LOCALE_DIR = '@prefix@/share/locale'
