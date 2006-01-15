--- setup.py.orig	Tue Jan 10 09:59:47 2006
+++ setup.py	Sun Jan 15 11:46:49 2006
@@ -8,11 +8,6 @@
 from distutils.core import setup
 import glob
 
-try:
-	import gtk
-except:
-	sys.exit("pyGTK version 2.6 or greater is required to run everygui. http://www.pygtk.org")
-
 
 setup(
 	name='everygui',
@@ -29,4 +24,3 @@
 			("share/everygui/egconfig", glob.glob("egconfig/*.egd"))]
 	)
 
-os.chmod("/usr/share/everygui/egconfig", 0777)
