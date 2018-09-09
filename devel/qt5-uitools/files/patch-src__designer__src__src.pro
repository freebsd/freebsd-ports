Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/designer/src/src.pro.orig	2018-06-09 11:10:38 UTC
+++ src/designer/src/src.pro
@@ -3,26 +3,3 @@ TEMPLATE = subdirs
 SUBDIRS = \
     uiplugin \
     uitools
-
-qtConfig(process) {
-    SUBDIRS += \
-        lib \
-        components \
-        designer
-
-    lib.depends = uiplugin
-    components.depends = lib
-    designer.depends = components
-    plugins.depends = lib
-
-    contains(QT_CONFIG, shared): SUBDIRS += plugins
-}
-
-uitools.depends = uiplugin
-
-qtNomakeTools( \
-    lib \
-    components \
-    designer \
-    plugins \
-)
