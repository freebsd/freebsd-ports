--- setup.py.orig	Mon Sep 23 16:23:48 2002
+++ setup.py	Mon Sep 23 16:24:06 2002
@@ -16,7 +16,7 @@
 
 def get_setup():
     data = {}
-    r = re.compile(r'(\S+)\s*?=\s*?(.+)')
+    r = re.compile(r'(\S+)\s*=\s*(.+)')
     
     if not os.path.isfile('Setup'):
         print "No 'Setup' file. Perhaps you need to run the configure script."
