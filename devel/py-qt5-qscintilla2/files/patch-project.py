--- project.py.orig	2021-03-04 14:24:28 UTC
+++ project.py
@@ -81,7 +81,8 @@ class Qsci(PyQtBindings):
             qmake_CONFIG = ['qscintilla2']
         else:
             qmake_CONFIG = []
-
+        
+        self.project = project
         super().__init__(project, 'Qsci', qmake_CONFIG=qmake_CONFIG)
 
     def apply_user_defaults(self, tool):
@@ -125,6 +126,7 @@ class Qsci(PyQtBindings):
 
             self._add_internal_lib_sources()
 
+        self.tags.append("WS_X11")
         super().apply_user_defaults(tool)
 
     def get_options(self):
