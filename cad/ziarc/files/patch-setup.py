--- setup.py.orig	Sat Feb  8 00:14:36 2003
+++ setup.py	Sat Feb  8 00:14:41 2003
@@ -31,6 +31,5 @@
 
 from distutils.core import setup
 import glob
-import py2exe
 
 setup(name="main_ziarc.py", scripts=["main_ziarc.py"],data_files=[("icons",glob.glob("icons\\*.*"))],)
