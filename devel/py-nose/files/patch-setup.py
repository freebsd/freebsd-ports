--- setup.py.orig	2015-01-19 13:57:58 UTC
+++ setup.py
@@ -30,7 +30,6 @@ try:
         entry_points = {
         'console_scripts': [
             'nosetests = nose:run_exit',
-            'nosetests%s = nose:run_exit' % py_vers_tag,
             ],
         'distutils.commands': [
             ' nosetests = nose.commands:nosetests',
