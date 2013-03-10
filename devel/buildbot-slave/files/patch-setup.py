--- ./setup.py.orig	2012-09-23 00:57:03.000000000 +1000
+++ ./setup.py	2012-12-07 22:19:57.724590221 +1100
@@ -105,11 +105,7 @@
         }
     }
 
-# set zip_safe to false to force Windows installs to always unpack eggs
-# into directories, which seems to work better --
-# see http://buildbot.net/trac/ticket/907
-if sys.platform == "win32":
-    setup_args['zip_safe'] = False
+setup_args['zip_safe'] = False
 
 try:
     # If setuptools is installed, then we'll add setuptools-specific arguments
