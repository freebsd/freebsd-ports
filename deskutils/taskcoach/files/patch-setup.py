--- setup.py.orig	2011-06-11 03:03:09.000000000 +0800
+++ setup.py	2011-07-06 16:26:53.000000000 +0800
@@ -54,7 +54,6 @@
     'license': meta.license,
     'download_url': meta.download,
     'packages': findPackages('taskcoachlib') + findPackages('buildlib'),
-    'scripts': ['taskcoach.py'],
     'classifiers': [\
         'Development Status :: 5 - Production/Stable',
         'Intended Audience :: End Users/Desktop',
@@ -76,14 +75,8 @@
     setupOptions['classifiers'].append('Natural Language :: %s'%language)
 
 system = platform.system()
-if system == 'Linux':
+if (system == 'Linux') or (system == 'FreeBSD'):
     setupOptions['package_data'] = {'taskcoachlib': ['bin.in/linux/_pysyncml.so']}
-    # Add data files for Debian-based systems:
-    current_dist = [dist.lower() for dist in platform.dist()]
-    if 'debian' in current_dist or 'ubuntu' in current_dist:
-        setupOptions['data_files'] = [\
-	    ('share/applications', ['build.in/fedora/taskcoach.desktop']), 
-	    ('share/pixmaps', ['icons.in/taskcoach.png'])]
 elif system == 'Windows':
     setupOptions['scripts'].append('taskcoach.pyw')
 elif system == 'Darwin':
