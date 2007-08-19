--- setup.py	Sun Aug 12 15:12:41 2007
+++ setup.py	Sun Aug 12 15:13:05 2007
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!%%PYTHON_CMD%%
 from distutils.core import setup
 from glob import glob
 import os
@@ -6,21 +6,6 @@
 
 if sys.hexversion < 0x020400f0:
     sys.stderr.write("python version failed: current version = %s.%s, needed version >= 2.4\n" % (sys.version_info[0],sys.version_info[1]))
-    sys.exit(1)
-try:
-    import libxml2
-except ImportError:
-    sys.stderr.write("dependencies failed: python libxml2\n") 
-    sys.exit(1)
-try:
-    import libxslt
-except ImportError:
-    sys.stderr.write("dependencies failed: python libxslt1\n") 
-    sys.exit(1)
-try:
-    import gtk.glade
-except ImportError:
-    sys.stderr.write("dependencies failed: python glade\n") 
     sys.exit(1)
 
 # make sure that the mo files are generated and up-to-date
