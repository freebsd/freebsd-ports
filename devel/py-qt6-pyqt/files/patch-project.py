--- project.py.orig	2022-06-17 15:12:18 UTC
+++ project.py
@@ -217,11 +217,11 @@ del find_qt
         if tool in ('build', 'install'):
             if self.designer_plugin and 'QtDesigner' in self.bindings:
                 self._add_plugin('designer', "Qt Designer", 'pyqt6',
-                        'designer', others_debug)
+                        '%%PYQT_DESIGNERDIR%%', others_debug)
 
             if self.qml_plugin and 'QtQml' in self.bindings:
                 self._add_plugin('qmlscene', "qmlscene", 'pyqt6qmlplugin',
-                        'PyQt6', others_debug)
+                        '%%PYQT_QMLDIR%%', others_debug)
 
         # Add the dbus-python support.
         if self.dbus_python:
