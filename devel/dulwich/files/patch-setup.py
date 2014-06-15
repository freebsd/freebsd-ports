--- ./setup.py.orig	2014-06-07 04:12:55.000000000 +0200
+++ ./setup.py	2014-06-14 11:16:37.182700482 +0200
@@ -51,8 +51,6 @@
 
 setup_kwargs = {}
 
-if has_setuptools:
-    setup_kwargs['test_suite'] = 'dulwich.tests.test_suite'
 
 setup(name='dulwich',
       description='Python Git Library',
@@ -72,7 +70,7 @@
       The project is named after the part of London that Mr. and Mrs. Git live in
       in the particular Monty Python sketch.
       """,
-      packages=['dulwich', 'dulwich.tests', 'dulwich.tests.compat', 'dulwich.contrib'],
+      packages=['dulwich', 'dulwich.contrib'],
       scripts=['bin/dulwich', 'bin/dul-web', 'bin/dul-receive-pack', 'bin/dul-upload-pack'],
       ext_modules=[
           Extension('dulwich._objects', ['dulwich/_objects.c'],
