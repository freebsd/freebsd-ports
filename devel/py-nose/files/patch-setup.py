--- setup.py.orig	Sun Apr 22 06:40:40 2007
+++ setup.py	Tue Apr 24 09:22:39 2007
@@ -38,7 +38,7 @@
     download_url = \
     'http://somethingaboutorange.com/mrl/projects/nose/nose-%s.tar.gz' \
     % VERSION,
-    data_files = [('man/man1', ['nosetests.1'])],
+#     data_files = [('man/man1', ['nosetests.1'])],
     package_data = {'': ['*.txt']},
     packages = find_packages(),
     entry_points = {        
