--- src/designer/designer.pro.orig	2013-06-17 10:19:19.000000000 +0200
+++ src/designer/designer.pro	2013-06-17 10:19:36.000000000 +0200
@@ -8,5 +8,5 @@
 include(../qxtbase.pri)
 
 CONFIG          += designer plugin
-target.path      = $$[QT_INSTALL_PLUGINS]/designer
+target.path      = %%PREFIX%%/lib/qt4/plugins/designer
 INSTALLS         = target
