--- setup.py.orig	2022-11-27 03:47:11 UTC
+++ setup.py
@@ -27,7 +27,6 @@ try:
         entry_points = {
         'console_scripts': [
             'nosetests = nose:run_exit',
-            'nosetests%s = nose:run_exit' % py_vers_tag,
             ],
         'distutils.commands': [
             'nosetests = nose.commands:nosetests',
@@ -104,7 +103,7 @@ setup(
     license = 'GNU LGPL',
     keywords = 'test unittest doctest automatic discovery',
     url = 'https://github.com/jayvdb/nose3',
-    data_files = [('man/man1', ['nosetests.1'])],
+    data_files = [('share/man/man1', ['nosetests.1'])],
     package_data = {'': ['*.txt',
                          'examples/*.py',
                          'examples/*/*.py']},
