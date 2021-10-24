--- project.py.orig	2021-12-04 07:18:20 UTC
+++ project.py
@@ -210,11 +210,11 @@ del find_qt
         if tool in ('build', 'install'):
             if self.designer_plugin and 'QtDesigner' in self.bindings:
                 self._add_plugin('designer', "Qt Designer", 'pyqt5',
-                        'designer', others_debug)
+                        '%%PYQT_DESIGNERDIR%%', others_debug)
 
             if self.qml_plugin and 'QtQml' in self.bindings:
                 self._add_plugin('qmlscene', "qmlscene", 'pyqt5qmlplugin',
-                        'PyQt5', others_debug)
+                        '%%PYQT_QMLDIR%%', others_debug)
 
         # Add the dbus-python support.
         if self.dbus_python:
