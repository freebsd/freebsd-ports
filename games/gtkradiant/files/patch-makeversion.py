--- ./makeversion.py.orig	Sun Feb 12 16:47:01 2006
+++ ./makeversion.py	Thu Mar 16 16:09:46 2006
@@ -39,8 +39,6 @@
 
 import sys, re, string, os
 
-import svn
-
 def get_version():
   # version
   f = open('include/version.default', 'r')
@@ -82,7 +80,7 @@ def radiant_makeversion(append_about):
     line = f.readline()
     f.close()
   else:
-    line = "Custom build based on revision " + str(svn.getRevision(os.getcwd()))
+    line = "Custom build based on revision 1.0"
   # optional additional message
   if ( not append_about is None ):
     line += append_about
