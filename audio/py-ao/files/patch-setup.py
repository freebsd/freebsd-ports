--- setup.py.orig	Sun Sep  2 21:14:39 2001
+++ setup.py	Mon Sep 23 16:14:54 2002
@@ -11,7 +11,7 @@
 
 def get_setup():
     data = {}
-    r = re.compile(r'(\S+)\s*?=\s*?(.+)')
+    r = re.compile(r'(\S+)\s*=\s*(.+)')
     
     if not os.path.isfile('Setup'):
         print "No 'Setup' file. Perhaps you need to run the configure script."
