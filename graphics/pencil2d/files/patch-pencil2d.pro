--- pencil2d.pro.orig	2020-08-03 02:00:25 UTC
+++ pencil2d.pro
@@ -6,8 +6,8 @@ TEMPLATE = subdirs
 
 SUBDIRS = \ # sub-project names
     core_lib \
-    app \
-    tests
+    app
+#    tests
 
 # build the project sequentially as listed in SUBDIRS !
 CONFIG += ordered
@@ -15,11 +15,11 @@ CONFIG += ordered
 # where to find the sub projects - give the folders
 core_lib.subdir = core_lib
 app.subdir      = app
-tests.subdir    = tests
+#tests.subdir    = tests
 
 # what subproject depends on others
 app.depends      = core_lib
-tests.depends    = core_lib
+#tests.depends    = core_lib
 
 TRANSLATIONS += translations/pencil.ts \
                 translations/pencil_ar.ts \
