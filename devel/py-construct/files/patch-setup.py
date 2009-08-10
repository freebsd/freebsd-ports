--- setup.py-orig	2009-08-08 21:15:31.000000000 +0000
+++ setup.py	2009-08-08 21:15:53.000000000 +0000
@@ -1,8 +1,8 @@
 #!/usr/bin/env python
 
 # from distutils.core import setup
-import ez_setup
-ez_setup.use_setuptools()
+#import ez_setup
+#ez_setup.use_setuptools()
 
 from setuptools import setup, find_packages
 
@@ -45,4 +45,4 @@
     "Topic :: System :: Networking :: Monitoring",
     "Topic :: Text Processing",
     ],
-)
\ No newline at end of file
+)
