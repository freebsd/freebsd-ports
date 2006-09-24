--- setup.py.orig	Sun Mar 12 23:09:05 2006
+++ setup.py	Sun Sep 24 15:05:50 2006
@@ -7,13 +7,7 @@
 import os
 import sys
 
-# use setuptools if we got it, else distutils
-try: 
-#    import ez_setup
-#    ez_setup.use_setuptools()
-    from setuptools import setup, Extension
-except:
-    from distutils.core import setup, Extension
+from distutils.core import setup, Extension
 
 if sys.argv[-1] == 'setup.py':
     print "To install, run 'python setup.py install'"
@@ -25,7 +19,7 @@
 
 # If setting the prefix failed you should attempt to set the prefix here:
 # prefix="/usr" # unix, Linux
-# prefix="/usr/local" # unix, alternate
+prefix="%%LOCALBASE%%" # unix, alternate
 # prefix="/sw"  # OSX, fink
 # prefix="/opt/local"  # OSX, darwin-ports? 
 
