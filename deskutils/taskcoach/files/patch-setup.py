--- setup.py.orig	2011-12-14 04:24:18.000000000 +0800
+++ setup.py	2012-01-05 17:57:29.000000000 +0800
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
