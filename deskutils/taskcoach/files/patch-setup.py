--- setup.py.orig	2011-09-19 03:48:34.000000000 +0800
+++ setup.py	2011-09-30 12:47:45.000000000 +0800
@@ -46,7 +46,6 @@
     'license': meta.license,
     'download_url': meta.download,
     'packages': findPackages('taskcoachlib') + findPackages('buildlib'),
-    'scripts': ['taskcoach.py'],
     'classifiers': [\
         'Development Status :: 5 - Production/Stable',
         'Intended Audience :: End Users/Desktop',
