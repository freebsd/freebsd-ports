--- ontv/__init__.py.in.orig	Sun Feb 18 00:51:02 2007
+++ ontv/__init__.py.in	Sun Feb 18 00:51:12 2007
@@ -1,7 +1,7 @@
 NAME = 'OnTV'
 VERSION = '@VERSION@'
-SERVERS_DIR = '@prefix@/lib/bonobo/servers'
-DATA_DIR = '@prefix@/@DATADIRNAME@/ontv'
-IMAGES_DIR = '@prefix@/@DATADIRNAME@/ontv/images'
-UI_DIR = '@prefix@/@DATADIRNAME@/gnome-2.0/ui'
-LOCALE_DIR = '@prefix@/@DATADIRNAME@/locale'
+SERVERS_DIR = '@prefix@/libdata/bonobo/servers'
+DATA_DIR = '@prefix@/share/ontv'
+IMAGES_DIR = '@prefix@/share/ontv/images'
+UI_DIR = '@prefix@/share/gnome-2.0/ui'
+LOCALE_DIR = '@prefix@/share/locale'
