--- ./setup.py.orig	2012-08-19 22:25:09.000000000 +0200
+++ ./setup.py	2012-08-19 22:25:33.000000000 +0200
@@ -1,8 +1,8 @@
 #!/usr/bin/env python
 
 # Bootstrap installation of Distribute
-import distribute_setup
-distribute_setup.use_setuptools()
+#import distribute_setup
+#distribute_setup.use_setuptools()
 
 from setuptools import setup, find_packages
 
@@ -11,8 +11,8 @@
 except IOError:
     long_description = ''
 
-install_requires = ['distribute',
-                    ]
+#install_requires = ['distribute',
+#                    ]
 
 setup(
     name='stevedore',
@@ -44,7 +44,7 @@
 
     provides=['stevedore',
               ],
-    install_requires=install_requires,
+#    install_requires=install_requires,
 
     namespace_packages=[],
     packages=find_packages(),
