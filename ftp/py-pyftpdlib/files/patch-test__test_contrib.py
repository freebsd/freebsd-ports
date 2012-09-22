--- ./test/test_contrib.py.orig	2012-01-26 05:16:27.000000000 +1100
+++ ./test/test_contrib.py	2012-09-15 01:25:10.000000000 +1000
@@ -37,6 +37,7 @@
 import ftplib
 import unittest
 import os
+import sys
 import random
 import string
 import warnings
@@ -56,10 +57,15 @@
 except ImportError:
     pass
 
+#Path hacks
+sys.path.insert(0, os.path.abspath('..'))
 from pyftpdlib import ftpserver
 from pyftpdlib.contrib import authorizers
 from pyftpdlib.contrib import handlers
 from pyftpdlib.contrib import filesystems
+
+#More hacks
+sys.path.append('.')
 from test_ftpd import *
 
 
