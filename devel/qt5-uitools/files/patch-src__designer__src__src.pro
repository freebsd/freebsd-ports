Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/designer/src/src.pro
+++ src/designer/src/src.pro
@@ -1,20 +1,4 @@
 TEMPLATE = subdirs
 
 SUBDIRS = \
-    uitools \
-    lib \
-    components \
-    designer
-
-contains(QT_CONFIG, shared): SUBDIRS += plugins
-
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
