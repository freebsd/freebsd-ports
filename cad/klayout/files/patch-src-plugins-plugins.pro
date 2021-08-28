--- src/plugins/plugins.pro.orig	2021-08-27 22:02:52 UTC
+++ src/plugins/plugins.pro
@@ -2,6 +2,7 @@ TEMPLATE = subdirs
 
 # Automatically include all sub-folders, but not the .pro file
 SUBDIR_LIST = $$files($$PWD/*)
+SUBDIR_LIST -= $$files($$PWD/*.orig)
 SUBDIR_LIST -= $$PWD/plugins.pro
 SUBDIR_LIST -= $$PWD/db_plugin.pri
 SUBDIR_LIST -= $$PWD/lay_plugin.pri
