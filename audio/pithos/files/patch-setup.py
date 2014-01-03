--- setup.py	2013-12-05 06:59:17.000000000 -0800
+++ setup.py	2014-01-01 23:25:57.944668958 -0800
@@ -50,12 +50,13 @@
         'License :: OSI Approved :: GPL License',
         'Programming Language :: Python'
     ],
+
     data_files=[
-        ('/usr/share/icons/hicolor/scalable/apps', [
+        ('share/pithos/icons/hicolor/scalable/apps', [
              'data/icons/scalable/apps/pithos-mono.svg',
              'data/icons/scalable/apps/pithos.svg'
          ]),
-        ('/usr/share/applications', ['data/pithos.desktop'])
+        ('share/pithos/applications', ['data/pithos.desktop'])
     ],
     package_data={
         'pithos': [
@@ -70,6 +71,7 @@
     ],
     packages=find_packages(),
     include_package_data=True,
+    zip_safe=False,
     entry_points={
         'gui_scripts': ['pithos = pithos.pithos:main']
     }
