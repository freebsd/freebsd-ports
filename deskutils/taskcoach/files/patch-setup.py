--- setup.py.orig	2011-12-13 20:24:18 UTC
+++ setup.py
@@ -52,8 +52,7 @@
     'url': meta.url,
     'license': meta.license,
     'download_url': meta.download,
-    'packages': findPackages('taskcoachlib') + findPackages('buildlib'),
-    'scripts': ['taskcoach.py'],
+    'packages': findPackages('taskcoachlib'),
     'classifiers': [\
         'Development Status :: 5 - Production/Stable',
         'Intended Audience :: End Users/Desktop',
