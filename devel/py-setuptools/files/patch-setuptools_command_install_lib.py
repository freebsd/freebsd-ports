--- setuptools/command/install_lib.py.orig	2013-12-16 22:09:54.602395279 -0200
+++ setuptools/command/install_lib.py	2013-12-16 22:10:50.052393299 -0200
@@ -4,18 +4,6 @@
 class install_lib(_install_lib):
     """Don't add compiled flags to filenames of non-Python files"""
 
-    def _bytecode_filenames (self, py_filenames):
-        bytecode_files = []
-        for py_file in py_filenames:
-            if not py_file.endswith('.py'):
-                continue
-            if self.compile:
-                bytecode_files.append(py_file + "c")
-            if self.optimize > 0:
-                bytecode_files.append(py_file + "o")
-
-        return bytecode_files
-
     def run(self):
         self.build()
         outfiles = self.install()
