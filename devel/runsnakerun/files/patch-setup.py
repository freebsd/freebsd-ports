--- ./setup.py.orig	2014-05-20 15:27:26.000000000 +0200
+++ ./setup.py	2014-05-20 15:28:03.000000000 +0200
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
-            'SquareMap >= 1.0.3',
-        ],
         license = "BSD",
         package_dir = {
             'runsnakerun':'runsnakerun',
