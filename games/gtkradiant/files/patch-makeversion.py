--- ./makeversion.py.orig	Sun Feb 12 16:47:01 2006
+++ ./makeversion.py	Thu Mar 16 16:09:46 2006
@@ -37,9 +37,7 @@
 # ouput:
 #   include/aboutmsg.h
 
-import sys, re, string, os
-
-import svn
+import sys, re, string, os, platform
 
 def get_version():
   # version
@@ -82,7 +80,7 @@
     line = f.readline()
     f.close()
   else:
-    line = "Custom build based on revision " + str(svn.getRevision(os.getcwd()))
+    line = "Custom build for %s (%s)" % (platform.system(), platform.machine())
   # optional additional message
   if ( not append_about is None ):
     line += append_about
