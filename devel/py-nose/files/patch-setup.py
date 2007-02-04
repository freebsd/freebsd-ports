--- setup.py.orig	Thu Feb  1 11:32:28 2007
+++ setup.py	Fri Feb  2 12:10:08 2007
@@ -38,7 +38,7 @@
     download_url = \
     'http://somethingaboutorange.com/mrl/projects/nose/nose-%s.tar.gz' \
     % VERSION,
-    data_files = [('man/man2', ['nosetests.1'])],
+#     data_files = [('man/man2', ['nosetests.1'])],
     package_data = {'': ['*.txt']},
     packages = find_packages(),
     entry_points = {        
