Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/designer/src/src.pro
+++ src/designer/src/src.pro
@@ -2,22 +2,4 @@ TEMPLATE = subdirs
 
 SUBDIRS = \
     uiplugin \
-    uitools \
-    lib \
-    components \
-    designer
-
-contains(QT_CONFIG, shared): SUBDIRS += plugins
-
-uitools.depends = uiplugin
-lib.depends = uiplugin
-components.depends = lib
-designer.depends = components
-plugins.depends = lib
-
-qtNomakeTools( \
-    lib \
-    components \
-    designer \
-    plugins \
-)
+    uitools
