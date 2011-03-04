--- setup.py.orig	2011-02-06 01:18:05.000000000 +0800
+++ setup.py	2011-03-04 16:47:57.000000000 +0800
@@ -54,7 +54,6 @@
     'license': meta.license,
     'download_url': meta.download,
     'packages': findPackages('taskcoachlib') + findPackages('buildlib'),
-    'scripts': ['taskcoach.py'],
     'classifiers': [\
         'Development Status :: 3 - Alpha',
         'Intended Audience :: End Users/Desktop',
@@ -73,14 +72,12 @@
     setupOptions['classifiers'].append('Natural Language :: %s'%language)
 
 # Add data files for Debian-based systems:
-current_dist = [dist.lower() for dist in platform.dist()]
-if 'debian' in current_dist or 'ubuntu' in current_dist:
-    setupOptions['data_files'] = [\
-        ('share/applications', ['build.in/fedora/taskcoach.desktop']), 
-        ('share/pixmaps', ['icons.in/taskcoach.png'])]
+setupOptions['data_files'] = [\
+    ('share/applications', ['build.in/fedora/taskcoach.desktop']), 
+    ('share/pixmaps', ['icons.in/taskcoach.png'])]
 
 system = platform.system()
-if system == 'Linux':
+if (system == 'Linux') or (system == 'FreeBSD'):
     setupOptions['package_data'] = {'taskcoachlib': ['bin.in/linux/_pysyncml.so']}
 elif system == 'Windows':
     setupOptions['scripts'].append('taskcoach.pyw')
