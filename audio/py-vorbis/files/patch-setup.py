--- setup.py.orig	Mon Sep 23 16:29:24 2002
+++ setup.py	Mon Sep 23 16:29:34 2002
@@ -20,7 +20,7 @@
 
 def get_setup():
     data = {}
-    r = re.compile(r'(\S+)\s*?=\s*?(.+)')
+    r = re.compile(r'(\S+)\s*?=\s*(.+)')
     
     if not os.path.isfile('Setup'):
         print "No 'Setup' file. Perhaps you need to run the configure script."
