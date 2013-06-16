--- ./setup.py.orig	2013-06-15 16:18:59.000000000 +0200
+++ ./setup.py	2013-06-15 16:19:45.000000000 +0200
@@ -34,8 +34,6 @@
 and package/module structures.""",
         'platforms': ['Any'],
     }
-    if setuptools:
-        extraArguments['install_package_data'] = True
     ### Now the actual set up call
     if sys.platform == 'darwin':
         gui_commands = [
@@ -56,9 +54,6 @@
         description = "GUI Viewer for Python profiling runs",
         author = "Mike C. Fletcher",
         author_email = "mcfletch@vrplumber.com",
-        install_requires = [
-            'SquareMap >= 1.0.1b3',
-        ],
         license = "BSD",
         package_dir = {
             'runsnakerun':'runsnakerun',
