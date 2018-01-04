Make QtWebKit an optional dependency of devel/qt5-designer. 
Otherwise ports like devel/qtcreator will depend on both 
qt5-webengine (directly) and qt5-webkit (via designer).

--- src/designer/src/plugins/plugins.pro.orig	2016-11-03 08:31:16 UTC
+++ src/designer/src/plugins/plugins.pro
@@ -1,6 +1,8 @@
 TEMPLATE = subdirs
 
 # qtHaveModule(opengl): SUBDIRS += tools/view3d
-qtHaveModule(webkitwidgets): SUBDIRS += qwebview
+use_webkit {
+    qtHaveModule(webkitwidgets): SUBDIRS += qwebview
+}
 win32: qtHaveModule(axcontainer): SUBDIRS += activeqt
 qtHaveModule(quickwidgets): SUBDIRS += qquickwidget
