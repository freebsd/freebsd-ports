--- setup.py.orig	2010-03-29 10:14:53.000000000 +0800
+++ setup.py	2010-03-29 10:15:06.000000000 +0800
@@ -5,8 +5,8 @@
 # $Id: 60ec5a51fd8b03d0a0746e5d4618c688b469e2c4 $
 # ---------------------------------------------------------------------------
 
-import ez_setup
-ez_setup.use_setuptools(download_delay=2)
+#import ez_setup
+#ez_setup.use_setuptools(download_delay=2)
 from setuptools import setup, find_packages
 import sys
 import os
