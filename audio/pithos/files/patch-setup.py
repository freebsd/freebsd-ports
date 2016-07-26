--- setup.py.orig	2014-05-01 22:33:16 UTC
+++ setup.py
@@ -37,11 +37,11 @@ def read(fname):
 
 if sys.platform != 'win32':
     data_files = [
-        ('/usr/share/icons/hicolor/scalable/apps', ['data/icons/hicolor/pithos.svg']),
-        ('/usr/share/icons/hicolor/48x48/apps', ['data/icons/hicolor/pithos-tray-icon.png']),
-        ('/usr/share/icons/ubuntu-mono-dark/apps/16', ['data/icons/ubuntu-mono-dark/pithos-tray-icon.svg']),
-        ('/usr/share/icons/ubuntu-mono-light/apps/16', ['data/icons/ubuntu-mono-light/pithos-tray-icon.svg']),
-        ('/usr/share/applications', ['data/pithos.desktop'])
+        ('share/icons/hicolor/scalable/apps', ['data/icons/hicolor/pithos.svg']),
+        ('share/icons/hicolor/48x48/apps', ['data/icons/hicolor/pithos-tray-icon.png']),
+        ('share/icons/ubuntu-mono-dark/apps/16', ['data/icons/ubuntu-mono-dark/pithos-tray-icon.svg']),
+        ('share/icons/ubuntu-mono-light/apps/16', ['data/icons/ubuntu-mono-light/pithos-tray-icon.svg']),
+        ('share/applications', ['data/pithos.desktop'])
     ]
 else:
     data_files = []
@@ -78,6 +78,7 @@ setup(
     ],
     packages=find_packages(),
     include_package_data=True,
+    zip_safe=False,
     entry_points={
         'gui_scripts': ['pithos = pithos.pithos:main']
     }
