--- setup.py.orig	2007-10-14 05:45:45.000000000 +0800
+++ setup.py	2008-01-14 10:18:17.000000000 +0800
@@ -57,7 +57,7 @@
     download_url = \
     'http://somethingaboutorange.com/mrl/projects/nose/nose-%s.tar.gz' \
     % VERSION,
-    data_files = [('man/man1', ['nosetests.1'])],
+#    data_files = [('man/man1', ['nosetests.1'])],
     package_data = {'': ['*.txt',
                          'examples/*.py',
                          'examples/*/*.py']},
