--- setup.py.orig	2016-06-20 15:30:48 UTC
+++ setup.py
@@ -8,11 +8,6 @@ import sys
 from distutils.core import setup
 import glob
 
-try:
-	import gtk
-except:
-	sys.exit("pyGTK version 2.6 or greater is required to run everygui. http://www.pygtk.org")
-
 
 setup(
 	name='everygui',
@@ -29,4 +24,3 @@ setup(
 			("share/everygui/egconfig", glob.glob("egconfig/*.egd"))]
 	)
 
-os.chmod("/usr/share/everygui/egconfig", 0777)
