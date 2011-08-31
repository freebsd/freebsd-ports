--- ./setup.py.orig	2011-08-31 09:29:19.000000000 +0200
+++ ./setup.py	2011-08-31 09:29:29.000000000 +0200
@@ -102,7 +102,7 @@
     license = 'GNU LGPL',
     keywords = 'test unittest doctest automatic discovery',
     url = 'http://readthedocs.org/docs/nose/',
-    data_files = [('man/man1', ['nosetests.1'])],
+#    data_files = [('man/man1', ['nosetests.1'])],
     package_data = {'': ['*.txt',
                          'examples/*.py',
                          'examples/*/*.py']},
